class Filter
	class Processor
		def initialize(&input_filter)
			@output = ->(a){}
			@input_filter = input_filter
		end

		def <<(input_data)
			output(@input_filter.call(input_data))
		end

		def output(output)
			@output.call(output) if output
		end
		
		def output=(output)
			@output = output
		end
	end

	def initialize(&input_filter)
		@input_filter = input_filter
		@processor = Processor.new(&@input_filter)
	end

	def output(&output)
		@processor.output = output
		self
	end

	def input
		@on_open and @on_open.each{|callback| callback.call}
		@processor.output @header_input.call if @header_input
		yield @processor
		@processor.output @footer_input.call if @footer_input
		@on_close and @on_close.each{|callback| callback.call}
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

	def on_open(&callback)
		(@on_open ||= []) << callback
		self
	end

	def on_close(&callback)
		(@on_close ||= []) << callback
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

		on_close do
			@chain_fiber.resume nil
			@chain_fiber = nil
		end
	end
end

