class Filter
	class InputProcessor
		def initialize(input_filter, &output)
			@input_filter = input_filter || ->(i){i}
			@output = output
		end

		def <<(input_data)
			@output.call(@input_filter.call(input_data) || return)
		end
	end

	def initialize(&input_filter)
		@input_processor = InputProcessor.new(input_filter) do |processed_output|
			@send.call(processed_output)
		end

		@output = nil

		@send = lambda do |data|
			@return.call(data)
		end

		@return = lambda do |data|
			@output.call(data) if @output
		end
	end

	def output(&output)
		@output = output
		self
	end

	def input
		@on_open and @on_open.each{|callback| callback.call}
		@send.call @header_input.call if @header_input
		yield @input_processor
		@send.call @footer_input.call if @footer_input
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

	def send_to(filter)
		@send_fiber = Fiber.new do |send_data|
			filter.input do |input|
				begin
					input << send_data
				end while send_data = Fiber.yield
			end
		end

		@send = lambda do |send_data|
			@send_fiber.resume send_data if @send_fiber
		end

		on_close do
			@send_fiber.resume nil
			@send_fiber = nil
		end
	end

	def return_from(filter)
		filter.output do |return_data|
			@return.call return_data
		end
	end

	def nest(filter)
		if @nest
			@nest.nest(filter)
		else
			@nest = filter
			send_to(filter)
			return_from(filter)
		end
		self
	end
end

