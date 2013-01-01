require_relative 'crypter'
require_relative 'envelope'
require_relative 'session_key'

class IOEncrypter
	def initialize(input, output, cipher_selector, password, options = {})
		options = { 
			in_block_size: 1024*256,
			envelope_class: Envelope::SDL
		}.merge(options)

		key = 
		if options[:session_key]
			SessionKey.new(options[:session_key])
		else
			SessionKey.generate(cipher_selector.key_size)
		end

		encrypter = Encrypter.new(cipher_selector, key, options)

		initialization_vector = 
		if options.include? initialization_vector
			options[:initialization_vector]
		else
			# may be nil if not needed
			encrypter.initialization_vector
		end

		envelope = options[:envelope_class].new do
			cipher cipher_selector.cipher
			mode cipher_selector.mode
			key_size cipher_selector.key_size if cipher_selector.key_size
			initialization_vector initialization_vector if initialization_vector
			session_key key.encrypt(cipher_selector, password)
		end

		# pass encrypted data to envelope
		encrypter.chain(envelope)

		envelope.output do |message_data|
			output.write message_data
		end

		encrypter.input do |encrypter_sink|
			while data = input.read(options[:in_block_size])
				encrypter_sink << data
			end
		end
	end
end

class IODecrypter
	def initialize(input, output, password, options = {})
		options = { 
			in_block_size: 1024*256,
			envelope_class: Envelope::SDL
		}.merge(options)

		# we will have decrypter after header was received
		decrypter = nil

		envelope = options[:envelope_class]::Loader.new

		envelope.on_header do |header|
			cipher_selector = CipherSelector.new
				.cipher(header.cipher)
				.mode(header.mode)
				.key_size(header.key_size)

			key = SessionKey.from_encrypted_session_key(cipher_selector, password, header.session_key)

			decrypter = Decrypter.new(cipher_selector, key, options.merge(initialization_vector: header.initialization_vector))

			envelope.chain(decrypter)

			decrypter.output do |data|
				output.write data
			end
		end

		envelope.on_close do
			raise IOError, 'stream closed before header was read' unless decrypter
		end

		envelope.input do |envelope_sink|
			while message_data = input.read(options[:in_block_size])
				envelope_sink << message_data
			end
		end
	end
end

