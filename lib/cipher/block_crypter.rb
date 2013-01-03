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
				last_block_length = nil

				@log.debug "Using initialization vector: #{initialization_vector.to_hex}"

				# save input and send shift_register to crypter
				super() do |input, output|
					input_sub_block = input

					# save size of last block if smaller that sub block
					last_block_length = input.length if input.length < sub_block_length

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

					unless last_block_length
						output << ciphertext
					else
						# strip bytes not needed for decryption - no paddning needed in this mode
						output << ciphertext.byteslice(0, last_block_length)
					end

					shift_register = shift_register.lshift(ciphertext.byteslice(0, sub_block_length))
				end
				crypter.nest(xor_shift)

				# add zero padding if needed - this is not needed at all!?
				#if options[:padding] 
				#	footer do
				#		0.chr(Encoding::ASCII_8BIT) * sub_block_length if padding_length == 0
				#	end
				#end
			end

			attr_reader :initialization_vector
		end
	end
end

