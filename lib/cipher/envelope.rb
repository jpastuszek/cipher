require 'sdl4r'

class Envelope
	class Sink
		def initialize(&sink)
			@sink = sink
		end

		def <<(data)
			@sink.call data
		end
	end

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

		class Loader
			def on_header(&callback)
				@on_header = callback
				self
			end

			def on_body(&callback)
				@on_body = callback
				self
			end

			def on_end(&callback)
				@on_end = callback
				self
			end

			def load
				header = nil
				header_data = ''

				sink = Sink.new do |data|
					unless header
						header_data << data
						if header_data.include? "\n\n"
							header, data = header_data.split("\n\n", 2)
							@on_header.call(SDL4R.load(header)) if @on_header
							@on_body.call(data) if @on_body
						end
					else
						@on_body.call(data) if @on_body
					end
				end

				yield sink

				@on_end.call if @on_end
				self
			end
		end
	end
end

