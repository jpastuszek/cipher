require_relative 'filter'

class FilterChain < Filter
	class Link
		def initialize(filter)
			filter.output do |output|
				@output_to.input_fiber.resume output if @output_to
				@output.call output if @output
			end	
			@input_fiber = Fiber.new do |input_data|
				filter.input do |input|
					begin
						input << input_data
					end while input_data = Fiber.yield
				end

				# close receiver input
				@output_to.input_fiber.resume nil if @output_to
			end
		end

		attr_reader :input_fiber

		def output_to(link)
			@output_to = link
		end

		def output(&output)
			@output = output
		end
	end

	def initialize
		super do |input|
			# capture input
			pass input
			nil
		end

		on_end do
			# notify chain that there is no more input
			link = @chain.first or return
			link.input_fiber.resume nil
		end

		terminator = Filter.new do |input|
			input
		end

		@terminator = Link.new(terminator)
		@terminator.output do |output|
			# pass output directy from terminator to client
			@processor.output output
		end

		@chain = []
	end

	def <<(filter)
		link = Link.new(filter)
		link.output_to(@terminator)
		if last_link = @chain.last
			last_link.output_to(link) 
		end
		@chain << link
	end

	private

	def pass(input)
		@chain.first.input_fiber.resume(input)
	end
end

