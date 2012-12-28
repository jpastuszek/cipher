require 'openssl'
require 'ostruct'

class CipherInfo
	def initialize(openssl_cipher_name, cipher, mode, key_length, need_key_length)
		@openssl_cipher_name = openssl_cipher_name
		@cipher = cipher
		@mode = mode
		@key_length = key_length
		@need_key_length = need_key_length
	end

	attr_reader :openssl_cipher_name
	attr_reader :cipher
	attr_reader :mode
	attr_reader :key_length

	def need_key_length?
		@need_key_length
	end
end

class CipherSelector
	def initialize
		@cipher_tree = build_cipher_tree
		@cipher_info = OpenStruct.new
	end

	def ciphers
		@cipher_tree.keys
	end

	def cipher(cipher)
		mode_tree = @cipher_tree[cipher] or fail "unsupported cipher #{cipher}"
		@cipher_info.cipher = cipher
		ModeSelector.new(mode_tree, @cipher_info)
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
			cipher, key_length, mode = 
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
			#puts c
			#puts "c: %s k: %s m: %s" % [cipher, key_length, mode]

			# some algorithms does not support setting key sizes
			key_length = :not_available if cipher =~ /^DES/
			
			# build nested hash
			((ciphers[cipher] ||= {})[mode] ||= {})[key_length] = c
		end
		ciphers
	end
end


class ModeSelector
	def initialize(mode_tree, cipher_info)
		@mode_tree = mode_tree
		@cipher_info = cipher_info
	end

	def cipher
		@cipher_info.cipher
	end

	def modes
		@mode_tree.keys
	end

	def mode(mode)
		key_length_tree = @mode_tree[mode] or fail "unsupported mode #{mode} for cipher #{@cipher_info.cipher}"
		@cipher_info.mode = mode
		KeyLengthSelector.new(key_length_tree, @cipher_info)
	end

	def preferred_mode(mode)
		if modes.include? mode
			mode(mode)
		else
			mode('none')
		end
	end
end

class KeyLengthSelector
	def initialize(key_length_tree, cipher_info)
		@key_length_tree = key_length_tree
		@cipher_info = cipher_info
	end

	def cipher
		@cipher_info.cipher
	end

	def mode
		@cipher_info.mode
	end

	def key_lengths
		@key_length_tree.keys
	end

	def key_length(key_length)
		if key_lengths.include? :not_available
			fail "cipher #{@cipher_info.cipher} does not support key length selection" if key_length
			@cipher_info.openssl_cipher_name = @key_length_tree[:not_available]
		elsif @key_length_tree.include? key_length
			@cipher_info.key_length = key_length
			@cipher_info.openssl_cipher_name = @key_length_tree[key_length]
		elsif @key_length_tree.include? :custom
			@cipher_info.key_length = key_length
			@cipher_info.need_key_length = true
			@cipher_info.openssl_cipher_name = @key_length_tree[:custom]
		else
			fail "unsupported key length #{key_length} for mode #{@cipher_info.mode} for cipher #{@cipher_info.cipher}"
		end

		CipherInfo.new(
			@cipher_info.openssl_cipher_name, 
			@cipher_info.cipher, 
			@cipher_info.mode, 
			@cipher_info.key_length, 
			@cipher_info.need_key_length
		)
	end

	def longest_key(custom_key_length = 256)
		longest = key_lengths.select{|k| k.is_a? Numeric}.sort.last
		if longest
			key_length(longest)
		else	 
			if key_lengths.include? :not_available
				# cannot use key length with this algorithm
				key_length(nil)
			else
				key_length(custom_key_length)
			end
		end
	end
end

