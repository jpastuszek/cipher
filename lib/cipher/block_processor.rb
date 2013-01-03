class LoggingBlockProcessor < Filter
	def initialize(log)
		super() do |input, output|
			log.debug "crypt block: #{input.inspect}" if log
			log.debug "crypt block length: #{input.length}" if log
			output << input
		end
	end
end

class BlockSlicer < Filter
	def initialize(size)
		slice_length = (size.to_f / 8).ceil
		offset = 0
		overflow = ''

		super() do |input, output|
			if overflow_length = overflow.length > 0
				overflow_slize_length = slice_length - overflow_length
				output << overflow + input.byteslice(0, overflow_slize_length)
				offset = overflow_slize_length
			end

			slices = (input.length - offset) / length
			slices.times do |slice_no|
				output << input.byteslice(offset + slice_no * slice_length, slice_length)
			end

			overflow = input.byteslice(offset + slices * slice_length, slice_length)
		end

		footer do
			overflow
		end
	end
end

