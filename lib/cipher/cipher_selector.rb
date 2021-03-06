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
	def initialize(cipher_info, mode, sub_block_size, need_initialization_vector, need_custom_sub_block_processor)
		super(cipher_info.cipher)
		@mode = mode
		@sub_block_size = sub_block_size
		@need_initialization_vector = need_initialization_vector
		@need_custom_sub_block_processor = need_custom_sub_block_processor
	end

	attr_reader :mode
	attr_reader :sub_block_size

	def need_initialization_vector?
		@need_initialization_vector
	end

	def need_custom_sub_block_processor?
		@need_custom_sub_block_processor
	end
end

class CipherSelectorInfo < ModeInfo
	def initialize(mode_info, openssl_cipher_name, key_size, need_key_size)
		super(mode_info, mode_info.mode, mode_info.sub_block_size, mode_info.need_initialization_vector?, mode_info.need_custom_sub_block_processor?)
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
			'RC2'			=> ['RC2', 128, 'CBC', :full_block],
			'IDEA'		=> ['IDEA', :custom, 'CBC', :full_block],
			'DES'			=> ['DES', :custom, 'CBC', :full_block],
			'CAST'		=> ['CAST', :custom, 'CBC', :full_block],
			'BF'			=> ['BF', :custom, 'CBC', :full_block],
			'DES-EDE' => ['DES-EDE', :custom, 'ECB', :full_block],
			'DES-EDE3' => ['DES-EDE3', :custom, 'ECB', :full_block],
			'DES3'		=> ['DES-EDE3', :custom, 'CBC', :full_block],
			'DESX'		=> ['DESX', :custom, 'none', :full_block],
			'RC4'			=> ['RC4', :custom, 'none', :full_block], # streaming cipher: no mode
			'AES128'	=> ['AES', 128, 'CBC', :full_block],
			'AES192'	=> ['AES', 192, 'CBC', :full_block],
			'AES256'	=> ['AES', 256, 'CBC', :full_block],
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
			cipher, key_size, mode, sub_block_size = 
			case c
				when lambda{|c| aliases.member? c}
					aliases[c]
				when /([^-]+)-([0-9]+)-([^0-9]+)([0-9]+)/
					[$1, $2.to_i, $3, $4.to_i]
				when /([^-]+)-([0-9]+)-(.*)/
					[$1, $2.to_i, $3, :full_block]
				when /([^-]+)-([0-9]+)/
					[$1, $2.to_i, 'none', :full_block]
				when /(.*)-([^0-9]+)([0-9]+)/
					[$1, :custom, $2, $3]
				when /(.*)-(.*)/
					[$1, :custom, $2, :full_block]
				else
					#STDERR.puts "unsupported cipher alias: #{c}"
			end

			# Some found working values
			key_size = 64 if cipher == 'DES'
			key_size = 192 if cipher == 'DESX'
			key_size = 128 if cipher == 'DES-EDE'
			key_size = 192 if cipher == 'DES-EDE3'

			#puts c
			#puts "c: %s k: %s m: %s s: %s" % [cipher, key_size, mode, sub_block_size]
			
			# build nested hash
			((ciphers[cipher] ||= {})[[mode, sub_block_size]] ||= {})[key_size] = c

			# add custom mode supported settings
			if mode == 'ECB' and sub_block_size == :full_block
				((ciphers[cipher] ||= {})[['CFB', :custom]] ||= {})[key_size] = c
				((ciphers[cipher] ||= {})[['OFB', :custom]] ||= {})[key_size] = c
			end
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

	def mode(mode, sub_block_size = :full_block, options = {})
		need_custom_sub_block_processor = false
		key_size_tree =  nil

		need_initialization_vector = 
		if ['ECB', 'none'].include? mode
			false
		else
			true
		end

		unless options[:prefer_custom_sub_block_processor]
			key_size_tree = 
			if natively_supported? mode, sub_block_size
				@mode_tree[[mode, sub_block_size]] 
			elsif custom_supported? mode, sub_block_size
				valid_custom_sub_block_size? sub_block_size or fail "unsupported sub block size #{sub_block_size} for mode #{mode} for cipher #{cipher}"
				need_custom_sub_block_processor = true
				need_initialization_vector = false
				@mode_tree[['ECB', :full_block]] 
			end
		else
			key_size_tree = 
			if custom_supported? mode, sub_block_size and valid_custom_sub_block_size? sub_block_size
				need_custom_sub_block_processor = true
				need_initialization_vector = false
				@mode_tree[['ECB', :full_block]] 
			elsif natively_supported? mode, sub_block_size
				@mode_tree[[mode, sub_block_size]] 
			end
		end

		fail "unsupported mode #{mode} for cipher #{cipher}" unless key_size_tree

		sub_block_size = block_size if sub_block_size == :full_block

		KeyLengthSelector.new(self, mode, sub_block_size, need_initialization_vector, need_custom_sub_block_processor, key_size_tree)
	end

	def preferred_mode(mode, sub_block_size = :full_block, options = {})
		if modes.include? [mode, sub_block_size]
			mode(mode, sub_block_size, options)
		elsif modes.include? ['CBC', :full_block]
			mode('CBC', sub_block_size, options)
		elsif modes.include? ['none', :full_block]
			mode('none', sub_block_size, options)
		else
			modes.sort do |a, b|
				next a.first <=> b.first if a.last == :full_block and b.last == :full_block
				next 1 if a.last == :full_block
				next -1 if b.last == :full_block
				next a.first <=> b.first if a.last == :custom and b.last == :custom
				next -1 if a.last == :custom
				next 1 if b.last == :custom
				a.first <=> b.first
			end.first
		end
	end

	private

	def natively_supported?(mode, sub_block_size)
		@mode_tree.include? [mode, sub_block_size]
	end

	def custom_supported?(mode, sub_block_size)
		@mode_tree.include? [mode, :custom]
	end

	def valid_custom_sub_block_size?(sub_block_size)
		sub_block_size == :full_block or not (
			sub_block_size > block_size or 
			sub_block_size < 8 or 
			sub_block_size % 8 != 0
		)
	end
end

class KeyLengthSelector < ModeInfo
	def initialize(cipher_info, mode, sub_block_size, need_initialization_vector, need_custom_sub_block_processor, key_size_tree)
		super cipher_info, mode, sub_block_size, need_initialization_vector, need_custom_sub_block_processor
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

