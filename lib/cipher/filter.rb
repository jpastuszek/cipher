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

		@on_start and @on_start.each{|callback| callback.call}
		@processor.output @header_input.call if @header_input
		yield @processor
		@processor.output @footer_input.call if @footer_input
		@on_end and @on_end.each{|callback| callback.call}
		self
	end

	def header(&input)
		@header_input = input
		self
	end

	def footer(&input)
		@footer_input = input
		self
	end

	def on_start(&callback)
		(@on_start ||= []) << callback
		self
	end

	def on_end(&callback)
		(@on_end ||= []) << callback
		self
	end

	def chain(filter)
		@chain_fiber = Fiber.new do |input_data|
			filter.input do |input|
				begin
					input << input_data
				end while input_data = Fiber.yield
			end
		end

		output do |output|
			@chain_fiber.resume output if @chain_fiber
		end

		on_end do
			@chain_fiber.resume nil
			@chain_fiber = nil
		end
	end
end

