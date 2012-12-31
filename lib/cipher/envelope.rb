require 'sdl4r'
require_relative 'string_hex'

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

			def key_size(v)
				@header[:key_size] = v.to_i
			end

			def initialization_vector(v)
				@header[:initialization_vector] = v.to_hex
			end

			def session_key(v)
				@header[:session_key] = v.to_hex
			end
		end

		def initialize(&header)
			@header = HeaderDSL.new(&header).header
		end

		def output(&sink)
			sink.call(SDL4R.dump(@header) + "\n")
			@sink = Sink.new(&sink)
			self
		end

		def input
			yield @sink
		end

		class Loader
			def on_header(&callback)
				@on_header = callback
				self
			end

			def output(&callback)
				@output = callback
				self
			end

			def on_end(&callback)
				@on_end = callback
				self
			end

			def input
				header = nil
				header_data = ''

				sink = Sink.new do |data|
					unless header
						header_data << data
						if header_data.include? "\n\n"
							header, data = header_data.split("\n\n", 2)

							header = SDL4R.load(header)
							header.initialization_vector = header.initialization_vector.from_hex if header.initialization_vector
							header.session_key = header.session_key.from_hex if header.session_key

							@on_header.call(header) if @on_header
							@output.call(data) if @output
						end
					else
						@output.call(data) if @output
					end
				end

				yield sink

				@on_end.call if @on_end
				self
			end
		end
	end
end

