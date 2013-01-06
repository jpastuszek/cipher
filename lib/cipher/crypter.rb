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
			@log.info "Using key size: #{@cipher_selector.key_size}"
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

		super() do |input, output|
			out = @cipher.update(input)
			output << out unless out.empty? # skip empty result
		end
		footer do 
			final = @cipher.final
			next if final.empty? # skip empty string final
			final
		end
	end

	attr_reader :initialization_vector
end

class Encrypter < Filter
	def initialize(cipher_selector, key, options = {})
		super()

		@crypter = if cipher_selector.need_custom_sub_block_processor?
			if cipher_selector.mode == 'CFB'
				BlockCrypter::CFB::Encrypter.new(cipher_selector, key, options)
			elsif cipher_selector.mode == 'OFB'
				BlockCrypter::OFB::Encrypter.new(cipher_selector, key, options)
			else
				raise NotImplementedError, "custom sub block mode #{cipher_selector.mode} not supported"
			end
		else
			Crypter.new(cipher_selector, key, options) do |cipher|
				cipher.encrypt
			end
		end

		nest @crypter
	end

	def initialization_vector
		@crypter.initialization_vector
	end
end

class Decrypter < Filter
	def initialize(cipher_selector, key, options = {})
		super()
		@crypter = if cipher_selector.need_custom_sub_block_processor?
			if cipher_selector.mode == 'CFB'
				BlockCrypter::CFB::Decrypter.new(cipher_selector, key, options)
			elsif cipher_selector.mode == 'OFB'
				BlockCrypter::OFB::Decrypter.new(cipher_selector, key, options)
			else
				raise NotImplementedError, "custom sub block mode #{cipher_selector.mode} not supported"
			end
		else
			Crypter.new(cipher_selector, key, options) do |cipher|
				cipher.decrypt
			end
		end

		nest @crypter
	end

	def initialization_vector
		@crypter.initialization_vector
	end
end

