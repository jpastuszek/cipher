require 'logger'
require_relative 'string_hex'
require_relative 'cipher_selector'
require_relative 'filter'

class Crypter < Filter
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
		@log = options[:log] || Logger.new('out.log')
		@cipher_selector = cipher_selector

		@log.info "Using cipher: #{@cipher_selector.openssl_cipher_name}"
		@cipher = OpenSSL::Cipher::Cipher.new(@cipher_selector.openssl_cipher_name)

		yield @cipher
 
		if @cipher_selector.need_key_size?
			@log.info "Using key length: #{@cipher_selector.key_size}"
			@cipher.key_len = @cipher_selector.key_size / 8
		end

		@log.debug "Using key: #{key.to_hex}"
		@cipher.key = key

		if @cipher_selector.need_initialization_vector?
			if options[:initialization_vector]
				@initialization_vector = options[:initialization_vector]
				@cipher.iv = @initialization_vector 
				@log.debug "Using initialization vector: #{@initialization_vector.to_hex}"
			else
				@initialization_vector = @cipher.random_iv
				@log.debug "Using generated initialization vector: #{@initialization_vector.to_hex}"

				if @initialization_vector.length * 8 != @cipher_selector.block_size
					@log.warn "provided block size (#{@cipher_selector.block_size}) does not match generated initialization vector size (#{@initialization_vector.length * 8})"
				end
			end
		end

		if not options.include?(:padding) or options[:padding] 
			@cipher.padding = 1
			@log.debug "Padding enabled"
		else
			@cipher.padding = 0
			@log.debug "Padding disabled"
		end

		super() do |input|
			@cipher.update input
		end
		footer do 
			@cipher.final
		end
	end

	attr_reader :initialization_vector
end

class Encrypter < Crypter
	def initialize(cipher_selector, key, options = {})
		super do |cipher|
			cipher.encrypt
		end
	end
end

class Decrypter < Crypter
	def initialize(cipher_selector, key, options = {})
		super(cipher_selector, key, options) do |cipher|
			cipher.decrypt
		end
	end
end

