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
	def initialize(slice_size)
		slice_length = (slice_size.to_f / 8).ceil
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
			buffer
		end
	end
end

