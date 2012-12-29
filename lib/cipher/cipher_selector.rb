require 'openssl'

class CipherInfo
	def initialize(cipher)
		@cipher = cipher

		# most ciphers have 64 bit block size
		@block_sizes = Hash.new(64)
		@block_sizes.merge!(
			'AES' => 128,
			'CAST5' => 128,
		)
	end

	attr_reader :cipher

	def block_size
		@block_sizes[cipher]	
	end
end

class ModeInfo < CipherInfo
	def initialize(cipher_info, mode, need_initialization_vector)
		super(cipher_info.cipher)
		@mode = mode
		@need_initialization_vector = need_initialization_vector
	end

	attr_reader :mode

	def need_initialization_vector?
		@need_initialization_vector
	end
end

class CipherSelectorInfo < ModeInfo
	def initialize(mode_info, openssl_cipher_name, key_size, need_key_size)
		super(mode_info, mode_info.mode, mode_info.need_initialization_vector?)
		@openssl_cipher_name = openssl_cipher_name
		@key_size = key_size
		@need_key_size = need_key_size
	end

	attr_reader :openssl_cipher_name
	attr_reader :key_size

	def need_key_size?
		@need_key_size
	end
end

class CipherSelector
	def initialize
		@cipher_tree = build_cipher_tree
	end

	def ciphers
		@cipher_tree.keys
	end

	def cipher(cipher)
		mode_tree = @cipher_tree[cipher] or fail "unsupported cipher #{cipher}"
		ModeSelector.new(cipher, mode_tree)
	end

	def flat_list
		@cipher_tree.each do |cipher, modes|
			modes.each do |mode, keys|
				keys.each_key do |key|
					yield cipher, mode, key
				end
			end
		end
	end

	private

	def build_cipher_tree
		ciphers = {}
		# default alias is for CBC mode
		aliases = {
			'RC2'			=> ['RC2', 128, 'CBC'],
			'IDEA'		=> ['IDEA', :custom, 'CBC'],
			'DES'			=> ['DES', :custom, 'CBC'],
			'CAST'		=> ['CAST', :custom, 'CBC'],
			'BF'			=> ['BF', :custom, 'CBC'],
			'DES-EDE' => ['DES-EDE', :custom, 'ECB'],
			'DES3'		=> ['DES-EDE3', :custom, 'CBC'],
			'DESX'		=> ['DES-EDE3', :custom, 'none'],
			'RC4'			=> ['RC4', :custom, 'none'], # streaming cipher: no mode
			'AES128'	=> ['AES', 128, 'CBC'],
			'AES192'	=> ['AES', 192, 'CBC'],
			'AES256'	=> ['AES', 256, 'CBC'],
		}

		# use only upcased aliases
		OpenSSL::Cipher.ciphers.select{|a| a == a.upcase}.sort do |a, b|
			# sort aliases at the end so that aliaste take precedence in selection
			next a <=> b if aliases.member? a and aliases.member? b
			next 1 if aliases.member? a
			next -1 if aliases.member? b
			a <=> b
		end.uniq.map do |c|
			# all variants of alias construction
			cipher, key_size, mode = 
			case c
				when lambda{|c| aliases.member? c}
					aliases[c]
				when /([^-]+)-([0-9]+)-(.*)/
					[$1, $2.to_i, $3]
				when /([^-]+)-([0-9]+)/
					[$1, $2.to_i, 'none']
				when /(.*)-(.*)/
					[$1, :custom, $2]
				else
					#STDERR.puts "unsupported cipher alias: #{c}"
			end

			# Some found working values
			key_size = 64 if cipher == 'DES'
			key_size = 192 if cipher == 'DESX'
			key_size = 128 if cipher == 'DES-EDE'
			key_size = 192 if cipher == 'DES-EDE3'

			#puts c
			#puts "c: %s k: %s m: %s" % [cipher, key_size, mode]
			#
			# build nested hash
			((ciphers[cipher] ||= {})[mode] ||= {})[key_size] = c
		end
		ciphers
	end
end

class ModeSelector < CipherInfo
	def initialize(cipher, mode_tree)
		super cipher
		@mode_tree = mode_tree
	end

	def modes
		@mode_tree.keys
	end

	def mode(mode)
		key_size_tree = @mode_tree[mode] or fail "unsupported mode #{mode} for cipher #{self.cipher}"
		need_initialization_vector = 
		if ['ECB', 'none'].include? mode
			false
		else
			true
		end

		KeyLengthSelector.new(self, mode, need_initialization_vector, key_size_tree)
	end

	def preferred_mode(mode)
		if modes.include? mode
			mode(mode)
		elsif modes.include? 'CBC'
			mode('CBC')
		elsif modes.include? 'none'
			mode('none')
		else
			modes.sort.first
		end
	end
end

class KeyLengthSelector < ModeInfo
	def initialize(cipher_info, mode, need_initialization_vector, key_size_tree)
		super cipher_info, mode, need_initialization_vector
		@key_size_tree = key_size_tree
	end

	def key_sizes
		@key_size_tree.keys
	end

	def key_size(key_size)
		if key_sizes.include? :not_available
			fail "cipher #{self.cipher} does not support key length selection" if key_size
			CipherSelectorInfo.new(self, @key_size_tree[:not_available], nil, false)
		elsif @key_size_tree.include? key_size
			CipherSelectorInfo.new(self, @key_size_tree[key_size], key_size, false)
		elsif @key_size_tree.include? :custom
			CipherSelectorInfo.new(self, @key_size_tree[:custom], key_size, true)
		else
			fail "unsupported key length #{key_size} for mode #{self.mode} for cipher #{self.cipher}"
		end
	end

	def longest_key(custom_key_size = 256)
		longest = key_sizes.select{|k| k.is_a? Numeric}.sort.last
		if longest
			key_size(longest)
		else	 
			if key_sizes.include? :not_available
				# cannot use key length with this algorithm
				key_size(nil)
			else
				key_size(custom_key_size)
			end
		end
	end
end

