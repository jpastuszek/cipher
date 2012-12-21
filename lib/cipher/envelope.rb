require 'sdl4r'

class Envelope
	class SDL
		class HeaderDSL
			def initialize(&dsl)
				@header = {}
				instance_eval &dsl
			end

			attr_reader :header

			def cipher(v)
				@header[:cipher] = v
			end

			def mode(v)
				@header[:mode] = v
			end

			def key_length(v)
				@header[:key_length] = v.to_i
			end

			def initialization_vector(v)
				@header[:initialization_vector] = v
			end
		end

		class Sink
			def initialize(&sink)
				@sink = sink
			end

			def <<(data)
				@sink.call data
			end
		end

		def initialize(&header)
			@header = HeaderDSL.new(&header).header
		end

		def each(&sink)
			sink.call(SDL4R.dump(@header) + "\n")
			@sink = Sink.new(&sink)
			self
		end

		def body
			yield @sink
		end
	end
end

