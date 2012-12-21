require 'logger'
require_relative 'string_base64'

class Crypter
	class Processor
		def initialize(cipher, &sink)
			@cipher = cipher
			@sink = sink
		end

		def <<(data)
			@sink.call @cipher.update(data)
		end

		def finalize
			@sink.call @cipher.final
		end
	end

	def initialize(cipher_selector, key, options = {})
		@log = options[:log] || Logger.new(STDERR)
		@cipher_selector = cipher_selector

		@log.info "Using cipher: #{@cipher_selector.openssl_cipher_name}"
		@cipher = OpenSSL::Cipher::Cipher.new(@cipher_selector.openssl_cipher_name)

		yield @cipher

		if @cipher_selector.need_key_length_set?
			@log.info "Using key length: #{@cipher_selector.key_length}"
			@cipher.key_len = @cipher_selector.key_length / 8
		end

		@log.debug "Using key: #{key.base64}"
		@cipher.key = key

		if options[:initialization_vector]
			@initialization_vector = options[:initialization_vector]
			@cipher.iv = @initialization_vector 
			@log.debug "Using initialization vector: #{@initialization_vector.base64}"
		else
			@initialization_vector = @cipher.random_iv
			@log.debug "Using generated initialization vector: #{@initialization_vector.base64}"
		end
	end

	attr_reader :initialization_vector
	def each(&sink)
		@processor = Processor.new(@cipher, &sink)
		self
	end

	def process
		yield @processor
		fail 'no each block given' unless @processor
		@processor.finalize
	end
end

class Encrypter < Crypter
	def initialize(cipher_selector, key, options = {})
		super do |cipher|
			cipher.encrypt
		end
	end
end

class Decrypter < Crypter
	def initialize(cipher_selector, key, initialization_vector, options = {})
		options = options.merge(initialization_vector: initialization_vector)
		super(cipher_selector, key, options) do |cipher|
			cipher.decrypt
		end
	end
end
