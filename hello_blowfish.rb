require 'openssl'
require 'base64'
require 'cli'

module CipherSelector
	def [](c)
		cipher_tree[c]
	end
	
	def keys
		cipher_tree.keys
	end

	private

	def cipher_tree
		return @ciphers if @ciphers
		@ciphers = {}
		# use only upcased aliases
		OpenSSL::Cipher.ciphers.select{|a| a == a.upcase}.sort.uniq.map do |c|
			# all variants of alias construction
			cipher, key_length, mode = 
			case c
				when /([^-]+)-([0-9]+)-(.*)/
					[$1, $2.to_i, $3]
				when /([^-]+)-([0-9]+)/
					[$1, $2.to_i, 'none']
				when /([^-]+)-(.*)/
					[$1, :custom, $2]
				else
					[c, :custom, 'none']
			end
			#puts c
			#puts "c: %s k: %s m: %s" % [cipher, key_length, mode]

			# some algorithms does not support setting key sizes
			key_length = :na if ['DES', 'DES3'].include? cipher
			
			# build nested hash
			((@ciphers[cipher] ||= {})[mode] ||= {})[key_length] = c
		end
		@ciphers
	end
end

class String
	def encode64
		Base64.encode64(self)
	end
end

OpenSSL::Cipher.extend(CipherSelector)

settings = CLI.new do
	option :cipher,
		short: :c,
		description: 'select cipher to use',
		default: 'AES'
	option :key_length,
		short: :k,
		description: 'cipher key length in bits (rounded to multiple of 8)',
		default: 'longest preset'
	option :mode,
		short: :m,
		description: 'cipher streaming mode',
		default: 'prefer CBC'
	option :password,
		short: :p,
		description: 'encryption or decryption password'
	option :initialization_vector,
		short: :i,
		description: 'initialization vector for CBC, CFB, OFB and CTR modes or random if not specified'
	option :password_digest,
		short: :d,
		description: 'digest to use to hash password for cipher key',
		default: 'SHA256'
	switch :list_ciphers,
		short: :C,
		description: 'list ciphers'
	switch :list_key_lengths,
		short: :K,
		description: 'list available key lenghts for selected cipher'
	switch :list_modes,
		short: :M,
		description: 'list available modes for given cipher and key length'
end.parse! do |settings|
	if settings.list_ciphers
		puts OpenSSL::Cipher.keys.join ' '
		exit
	end

	modes = OpenSSL::Cipher[settings.cipher] or fail "unsupported cipher #{settings.cipher}"

	if settings.list_modes
		puts modes.keys.join ' '
		exit
	end

	if settings.mode =~ /prefer (.+)/
		settings.mode =
		if modes.keys.include? $1
			$1
		else
			'none'
		end
	end

	key_lengths =
	if modes.include? settings.mode
		modes[settings.mode]
	else
		fail "unsupported mode #{settings.mode} for key length #{settings.key_length} for cipher #{settings.cipher}"
	end

	if settings.list_key_lengths
		puts key_lengths.keys.join ' '
		exit
	end

	settings.key_length =
	if settings.key_length == 'longest preset'
		longest = key_lengths.keys.select{|k| k.is_a? Numeric}.sort.last
		if longest
			longest
		else	 
			if key_lengths.include? :na
				# cannot use key length with this algorithm
				nil
			else
				128
			end
		end
	else
		fail "cipher #{settings.cipher} does not support key length option" if key_lengths.include? :na
		settings.key_length.to_i
	end

	settings.cipher_name = 
	if key_lengths.include? :na
		key_lengths[:na]
	elsif key_lengths.include? settings.key_length
		key_lengths[settings.key_length]
	elsif key_lengths.include? :custom
		settings.custom_key_length = true
		key_lengths[:custom]
	else
		fail "unsupported key length #{settings.key_length} for cipher #{settings.cipher}"
	end

	settings.cipher = OpenSSL::Cipher::Cipher.new(settings.cipher_name)
	settings.password_digest = OpenSSL::Digest.new(settings.password_digest)

	fail "please provide passord" unless settings.password
end

puts "Using cipher: #{settings.cipher_name}"
cipher = settings.cipher

if settings.custom_key_length
	puts "Using key length: #{settings.key_length / 8 * 8}"
	cipher.key_len = settings.key_length / 8
end

cipher.encrypt

key = settings.password_digest.update(settings.password).digest
puts "Using key: #{key.encode64}"
cipher.key = key

iv = (settings.initialization_vector || cipher.random_iv).tap do |iv|
	puts "Using initialization vector: #{iv.encode64}"
end if settings.mode

data = cipher.update('hello world') + cipher.final

puts "Data:"
puts data.encode64

decipher = OpenSSL::Cipher::Cipher.new(settings.cipher_name)
if settings.custom_key_length
	puts "Using key length: #{settings.key_length / 8 * 8}"
	decipher.key_len = settings.key_length / 8
end

decipher.key = key
decipher.iv = iv if iv
puts decipher.update(data) + decipher.final

