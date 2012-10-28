require 'openssl'
require 'base64'
require 'cli'
require 'haddock'
require 'sdl4r'
require 'logger'

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
	def base64_multiline
		Base64.encode64(self)
	end

	def base64
		Base64.strict_encode64(self)
	end
end

OpenSSL::Cipher.extend(CipherSelector)

settings = CLI.new do
	stdin :data
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
		description: 'encryption or decryption password (auto generated by default)',
		default: Haddock::Password.generate
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

	settings.password_digest

	fail "please provide passord" unless settings.password
end

log = Logger.new(STDERR)
log.formatter = proc do |severity, datetime, progname, msg|
	  "> #{msg}\n"
end

class Key < String
	def initialize(password, password_digest)
		super OpenSSL::Digest.new(password_digest).update(password).digest
	end
end

class Encrypter
	def initialize(cipher_name, key, options = {})
		@header = {}
		log = options[:log] || Logger.new(STDERR)

		log.info "Using cipher: #{cipher_name}"
		@cipher = OpenSSL::Cipher::Cipher.new(cipher_name)
		@header[:cipher] = cipher_name

		@cipher.encrypt

		if options[:key_length]
			rounded_key_length = options[:key_length] / 8 * 8
			log.info "Using key length: #{rounded_key_length}"
			@cipher.key_len = rounded_key_length / 8
			@header[:key_length] = rounded_key_length
		end

		log.debug "Using key: #{key.base64}"
		@cipher.key = key

		initialization_vector = if options[:initialization_vector]
			options[:initialization_vector]
		else
			@cipher.random_iv
		end
		@cipher.iv = initialization_vector
		@header[:initialization_vector] = initialization_vector.base64
		log.debug "Using initialization vector: #{initialization_vector.base64}"

	end

	def each(&sink)
		@sink = sink
		@sink.call(SDL4R.dump(@header) + "\n")
		self
	end

	def <<(data)
		@sink.call @cipher.update(data)
	end

	def encrypt
		yield self
		@sink.call @cipher.final
	end
end

log.info "Using password: #{settings.password}"

options = {}
options[:log] = log
options[:key_length] = settings.key_length if settings.custom_key_length
options[:initialization_vector] = settings.initialization_vector.ljust(16) if settings.initialization_vector

e = Encrypter.new(settings.cipher_name, Key.new(settings.password, settings.password_digest), options)

e.each do |encrypted_data_chunk|
	print encrypted_data_chunk
end

e.encrypt do |e|
	while data = settings.stdin.read(1024)
		e << data
	end
end

#decipher = OpenSSL::Cipher::Cipher.new(settings.cipher_name)
#if settings.custom_key_length
	#puts "Using key length: #{settings.key_length / 8 * 8}"
	#decipher.key_len = settings.key_length / 8
#end

#decipher.key = key
#decipher.iv = iv if iv
#log.debug decipher.update(data) + decipher.final

