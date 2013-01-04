require 'ostruct'

class BlockCrypter < Filter
	class State < OpenStruct
		def initialize(initialization_vector)
			super()
			self.shift_register = initialization_vector
		end
	end

	class LoggingBlockProcessor < Filter
		def initialize(log)
			super() do |input, output|
				log.debug "crypt block: #{input.to_hex}" if log
				log.debug "crypt block length: #{input.length}" if log
				output << input
			end
		end
	end

	class BlockSlicer < Filter
		def initialize(slice_length)
			buffer = ''

			super() do |input, output|
				buffer += input
				next if buffer.length < slice_length

				slices = buffer.length / slice_length
				slices.times do |slice_no|
					output << buffer.byteslice(slice_no * slice_length, slice_length)
				end

				buffer = buffer.byteslice(slices * slice_length, buffer.length % slice_length) || ''
			end

			footer do
				next if buffer.empty?
				buffer
			end
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

	class SubBlockInputXOR < Filter
		def initialize(state, sub_block_length)
			super() do |input, output|
				sub_block = input.byteslice(0, sub_block_length)
				ciphertext = sub_block ^ state.input_sub_block
				ciphertext = ciphertext.byteslice(0, state.input_sub_block.length)
				output << ciphertext
			end
		end
	end

	class SubBlockShiftRegisterShifter < Filter
		def initialize(state, sub_block_length)
			super() do |input, output|
				state.shift_register = state.shift_register.lshift(input.byteslice(0, sub_block_length))
				output << input
			end
		end
	end

	class SubBlockInputShiftRegisterShifter < Filter
		def initialize(state)
			super() do |input, output|
				state.shift_register = state.shift_register.lshift(state.input_sub_block)
				output << input
			end
		end
	end

	def initialize(cipher_selector, key, options = {})
		@log = options[:log] || Logger.new('out.log')
		@log.info "Using custom sub block cipher"

		@initialization_vector = (
			options.delete(:initialization_vector) or
			OpenSSL::Random.random_bytes(cipher_selector.block_size / 8)
		)
		@log.debug "Using initialization vector: #{initialization_vector.to_hex}"

		@sub_block_length = cipher_selector.sub_block_size / 8

		@state = State.new(@initialization_vector)
		super()
		nest BlockSlicer.new(@sub_block_length)
		nest InputShiftRegisterSwitcher.new(@state)
		nest ECBEncrypter.new(cipher_selector, key, options)
	end

	attr_reader :initialization_vector

	class CFB < BlockCrypter
		def initialize(cipher_selector, key, options = {})
			super
			nest SubBlockInputXOR.new(@state, @sub_block_length)
		end

		class Encrypter < CFB
			def initialize(cipher_selector, key, options = {})
				super
				nest SubBlockShiftRegisterShifter.new(@state, @sub_block_length)
			end
		end

		class Decrypter < CFB
			def initialize(cipher_selector, key, options = {})
				super
				nest SubBlockInputShiftRegisterShifter.new(@state)
			end
		end
	end

	class OFB < BlockCrypter
		def initialize(cipher_selector, key, options = {})
			super
			nest SubBlockShiftRegisterShifter.new(@state, @sub_block_length)
			nest SubBlockInputXOR.new(@state, @sub_block_length)
		end

		class Encrypter < OFB
		end

		class Decrypter < OFB
		end
	end
end

