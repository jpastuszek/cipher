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
					[$1, :any, $2]
				else
					[c, :any, 'none']
			end
			puts c
			puts "c: %s k: %s m: %s" % [cipher, key_length, mode]

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
		description: 'seleck key size for selected cipher',
		cast: Integer,
		default: 256
	option :mode,
		short: :m,
		description: 'seleck mode for selected cipher and key length',
		default: 'CBC'
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

	p modes = OpenSSL::Cipher[settings.cipher] or fail "unsupported cipher #{settings.cipher}"

	if settings.list_modes
		puts modes.keys.join ' '
		exit
	end

	key_lenghts =
	if modes.include? settings.mode
		modes[settings.mode]
	else
		fail "unsupported mode #{settings.mode} for key length #{settings.key_length} for cipher #{settings.cipher}"
	end

	if settings.list_key_lengths
		puts key_lenghts.keys.join ' '
		exit
	end

	settings.cipher_name = 
	if key_lenghts.include? :na
		# cannot use key length with this algorithm
		settings.key_lenghts = nil
		key_lenghts[:na]
	elsif key_lenghts.include? settings.key_length
		key_lenghts[settings.key_length]
	elsif key_lenghts.include? :any
		key_lenghts[:any]
	else
		fail "unsupported key length #{settings.key_length} for cipher #{settings.cipher}"
	end

	settings.cipher = OpenSSL::Cipher::Cipher.new(settings.cipher_name)
	settings.password_digest = OpenSSL::Digest.new(settings.password_digest)

	fail "please provide passord" unless settings.password
end

puts "Using cipher: #{settings.cipher_name}"
cipher = settings.cipher
p cipher.key_len
if settings.key_length
	puts "Using key length: #{settings.key_length / 8 * 8}"
	cipher.key_len = p settings.key_length / 8
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
p cipher.key_len
if settings.key_length
	puts "Using key length: #{settings.key_length / 8 * 8}"
	decipher.key_len = p settings.key_length / 8
end

decipher.key = key
decipher.iv = iv if iv
puts decipher.update(data) + decipher.final

