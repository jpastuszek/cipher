module BlockCipher
	module CFB
		class Encrypter < Filter
			def initialize(cipher_selector, key, options = {})
				@log = options[:log] || Logger.new('out.log')

				@initialization_vector = (
					options.delete(:initialization_vector) or
					OpenSSL::Random.random_bytes(cipher_selector.block_size / 8)
				)

				sub_block_length = cipher_selector.sub_block_size / 8

				shift_register = @initialization_vector
				input_sub_block = nil

				@log.debug "Using initialization vector: #{initialization_vector.to_hex}"

				# save input and send shift_register to crypter
				super() do |input, output|
					input_sub_block = input
					output << shift_register
				end

				crypter = Crypter.new(cipher_selector, key, options.merge(padding: false)) do |cipher|
					cipher.encrypt
				end
				nest crypter

				# xor crypted block with saved input and send ciphertext; shift shift_register
				xor_shift = Filter.new do |crypt_block, output|
					crypt_block_sub_block = crypt_block.byteslice(0, sub_block_length)
					ciphertext = crypt_block_sub_block ^ input_sub_block
					ciphertext = ciphertext.byteslice(0, input_sub_block.length)
					output << ciphertext
					shift_register = shift_register.lshift(ciphertext)
				end
				crypter.nest(xor_shift)
			end

			attr_reader :initialization_vector
		end
	end
end

