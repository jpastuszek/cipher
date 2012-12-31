class Filter
	class Processor
		def initialize(output, &input_filter)
			@output = output
			@input_filter = input_filter
		end

		def <<(input_data)
			output(@input_filter.call(input_data))
		end

		def output(output)
			@output.call(output) if output
		end
	end

	def initialize(&input_filter)
		@input_filter = input_filter
	end

	def output(&output)
		@processor = Processor.new(output, &@input_filter)
		self
	end

	def input
		fail 'filter output not connected' unless @processor
		@processor.output @header_input.call if @header_input
		yield @processor
		@processor.output @footer_input.call if @footer_input
	end

	def header(&input)
		@header_input = input
	end

	def footer(&input)
		@footer_input = input
	end
end

