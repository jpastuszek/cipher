require_relative 'crypter'
require_relative 'envelope'

class IOEncrypter
	def initialize(input, output, cipher_selector, key, options = {})
		encrypter = Encrypter.new(cipher_selector, key, options)
		options = { 
			in_block_size: 1024*256,
			envelope_class: Envelope::SDL
		}.merge(options)

		initialization_vector = 
		if options.include? initialization_vector
			options[:initialization_vector]
		else
			encrypter.initialization_vector
		end

		options[:envelope_class].new do
			cipher cipher_selector.cipher
			mode cipher_selector.mode
			key_length cipher_selector.key_length if cipher_selector.key_length
			# TODO: move base64 to envelope
			initialization_vector initialization_vector.base64
		end
		.each do |message_data|
			output.write message_data
		end
		.body do |envelope_sink|
			encrypter
			.each do |encrypted_data|
				envelope_sink << encrypted_data
			end
			.process do |encrypter_sink|
				while data = input.read(options[:in_block_size])
					encrypter_sink << data
				end
			end
		end
	end
end

class IODecrypter
	def initialize(input, output, key, options = {})
		options = { 
			in_block_size: 1024*256,
			envelope_class: Envelope::SDL
		}.merge(options)

		decrypter_fiber = nil

		options[:envelope_class]::Loader.new
		.on_header do |header|
			cipher_selector = CipherSelector.new
				.cipher(header.cipher)
				.mode(header.mode)
				.key_length(header.key_length)

			decrypter_fiber = Fiber.new do
				Decrypter.new(cipher_selector, key, header.initialization_vector.unbase64, options)
				.each do |data|
					output.write data
				end
				.process do |decrypter_sink|
					while encrypted_data = Fiber.yield do
						decrypter_sink << encrypted_data
					end
				end
			end
			decrypter_fiber.resume # start fiber
		end
		.on_body do |encrypted_data|
			decrypter_fiber.resume encrypted_data
		end
		.on_end do
			decrypter_fiber.resume nil
		end
		.load do |envelope_sink|
			while message_data = input.read(options[:in_block_size])
				envelope_sink << message_data
			end
		end
	end
end

