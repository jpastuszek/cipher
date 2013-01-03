module BlockCipher
	module CFB
		class Encrypter < Filter
			def initialize(cipher_selector, key, options = {})
				@log = options[:log] || Logger.new('out.log')

				@initialization_vector = options.delete(:initialization_vector)

				# TODO: generate
				@initialization_vector ||= 'iv' * (cipher_selector.block_size / 8 / 2)

				@crypter = Crypter.new(cipher_selector, key, options) do |cipher|
					cipher.encrypt
				end

				shift_register = @initialization_vector

				@log.debug "Using initialize vector: #{initialization_vector}"

				@crypter.input do |crypter_input|
					super() do |input_block, output|
						@crypter.output do |crypter_output|
							@log.debug "crypter output: #{crypter_output.to_hex}"
							ciphertext = xor(crypter_output, input_block)
							output << ciphertext
							shift_register = shift(shift_register, ciphertext)
						end

						@log.debug "crypter input: #{shift_register.to_hex}"
						crypter_input << shift_register
					end
				end
			end

			attr_reader :initialization_vector

			def xor(block_a, block_b)
				@log.debug "#{block_a.to_hex} XOR #{block_b.to_hex}"
				block_a
			end

			def shift(shift_register, block)
				@log.debug "#{shift_register.to_hex} <shift< #{block.to_hex}"
				block
			end
		end
	end
end

