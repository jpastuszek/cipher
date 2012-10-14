require 'openssl'
require 'base64'
require 'cli'

module CipherSelector
	def [](*args)
		unless @ciphers
			@ciphers = {}
			OpenSSL::Cipher.ciphers.sort.uniq.map do |c|
				cipher, key_length, mode = *c.split('-')
				((@ciphers[cipher] ||= {})[key_length ? key_length.to_i : nil] ||= {})[mode] = c
			end
		end

		root = @ciphers
		until args.empty?
			root = root[args.shift]
		end
		root.is_a?(Hash) ? root.keys : root
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
		description: 'seleck key size for selected cipher',
		cast: Integer,
		default: 256
	option :mode,
		short: :m,
		description: 'seleck mode for selected cipher and key length',
		default: 'CFB'
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
		puts OpenSSL::Cipher[].join ' '
		exit
	end
	OpenSSL::Cipher[settings.cipher] or fail "unsupported cipher #{settings.cipher}"

	if settings.list_key_lengths
		puts OpenSSL::Cipher[settings.cipher].join ' '
		exit
	end
	settings.key_length = 
	if OpenSSL::Cipher[settings.cipher].include? settings.key_length
		settings.key_length
	elsif OpenSSL::Cipher[settings.cipher].include? 0
		0
	else
		nil
	end
	OpenSSL::Cipher[settings.cipher, settings.key_length] or fail "unsupported key length #{settings.key_length} for cipher #{settings.cipher}"

	if settings.list_modes
		puts OpenSSL::Cipher[settings.cipher, settings.key_length].join ' '
		exit
	end
	settings.mode = 
	if not OpenSSL::Cipher[settings.cipher, settings.key_length].include? settings.mode and OpenSSL::Cipher[settings.cipher, settings.key_length].include? nil
		nil
	else
		settings.mode
	end
	OpenSSL::Cipher[settings.cipher, settings.key_length, settings.mode] or fail "unsupported mode #{settings.mode} for key length #{settings.key_length} for cipher #{settings.cipher}"


	settings.cipher_name = OpenSSL::Cipher[settings.cipher, settings.key_length, settings.mode]
	settings.cipher = OpenSSL::Cipher::Cipher.new(settings.cipher_name)
	settings.password_digest = OpenSSL::Digest.new(settings.password_digest)
end

puts "Using cipher: #{settings.cipher_name}"
cipher = settings.cipher
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
decipher.key = key
decipher.iv = iv if iv
puts decipher.update(data) + decipher.final

