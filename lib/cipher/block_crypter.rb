require 'ostruct'

module BlockCipher
	class CFB < Filter
		class State < OpenStruct
			def initialize(initialization_vector)
				super()
				self.shift_register = initialization_vector
			end
		end

		class InputShiftRegisterSwitcher < Filter
			def initialize(state)
				super() do |input, output|
					state.input_sub_block = input
					output << state.shift_register
				end
			end
		end

		class ECBEncrypter < Crypter
			def initialize(cipher_selector, key, options = {})
				super(cipher_selector, key, options.merge(padding: false)) do |cipher|
					cipher.encrypt
				end
			end
		end

		class XOR < Filter
			def initialize(state, sub_block_length)
				super() do |crypt_block, output|
					crypt_block_sub_block = crypt_block.byteslice(0, sub_block_length)
					ciphertext = crypt_block_sub_block ^ state.input_sub_block
					ciphertext = ciphertext.byteslice(0, state.input_sub_block.length)
					output << ciphertext
				end
			end
		end

		class CiphertextShifter < Filter
			def initialize(state)
				super() do |ciphertext, output|
					state.shift_register = state.shift_register.lshift(ciphertext)
					output << ciphertext
				end
			end
		end

		class InputShifter < Filter
			def initialize(state)
				super() do |ciphertext, output|
					state.shift_register = state.shift_register.lshift(state.input_sub_block)
					output << ciphertext
				end
			end
		end

		def initialize(cipher_selector, key, options = {})
			@log = options[:log] || Logger.new('out.log')

			@initialization_vector = (
				options.delete(:initialization_vector) or
				OpenSSL::Random.random_bytes(cipher_selector.block_size / 8)
			)
			@log.debug "Using initialization vector: #{initialization_vector.to_hex}"

			sub_block_length = cipher_selector.sub_block_size / 8

			@state = State.new(@initialization_vector)

			super()
			nest BlockSlicer.new(sub_block_length)
			nest InputShiftRegisterSwitcher.new(@state)
			nest ECBEncrypter.new(cipher_selector, key, options)
			nest XOR.new(@state, sub_block_length)
		end

		attr_reader :initialization_vector

		class Encrypter < CFB
			def initialize(cipher_selector, key, options = {})
				super
				nest CiphertextShifter.new(@state)
			end
		end

		class Decrypter < CFB
			def initialize(cipher_selector, key, options = {})
				super
				nest InputShifter.new(@state)
			end
		end
	end
end

