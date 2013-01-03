module BlockCipher
	module CFB
		class Encrypter < Filter
			def initialize(cipher_selector, key, options = {})
				@log = options[:log] || Logger.new('out.log')

				@initialization_vector = options.delete(:initialization_vector)
				# TODO: generate
				@initialization_vector ||= 'iv' * (cipher_selector.block_size / 8 / 2)

				@sub_block_length = cipher_selector.sub_block_size / 8

				@crypter = Crypter.new(cipher_selector, key, options) do |cipher|
					cipher.encrypt
				end

				shift_register = @initialization_vector

				@log.debug "Using initialize vector: #{initialization_vector}"

				@crypter.input do |crypter_input|
					super() do |input_sub_block, output|
						@crypter.output do |crypter_output|
							@log.debug "crypter output: #{crypter_output.to_hex}"

							crypter_output_sub_block = crypter_output.byteslice(0, @sub_block_length)
							@log.debug "crypter output sub block: #{crypter_output_sub_block.to_hex}"
							
							ciphertext = xor(crypter_output_sub_block, input_sub_block)

							@log.debug "ciphertext: #{ciphertext.to_hex}"
							output << ciphertext
							shift_register = shift(shift_register, ciphertext.byteslice(0, @sub_block_length))
						end

						@log.debug "crypter input (shift_register): #{shift_register.to_hex}"
						crypter_input << shift_register
					end
				end
			end

			attr_reader :initialization_vector

			def xor(block_a, block_b)
				@log.debug "#{block_a.to_hex} XOR #{block_b.to_hex}"
				block_a ^ block_b
			end

			def shift(shift_register, block)
				@log.debug "#{shift_register.to_hex} <shift< #{block.to_hex}"
				shift_register.lshift(block)
			end
		end
	end
end

