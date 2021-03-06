require 'sdl4r'

class Envelope
	class SDL < Filter
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

			def sub_block_size(v)
				@header[:sub_block_size] = v.to_i
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
			header do
				SDL4R.dump(@header) + "\n"
			end
			super() {|input, output| output << input}
		end

		class Loader < Filter
			def initialize
				header = nil
				header_data = ''

				super() do |input, output|
					unless header
						header_data << input
						if header_data.include? "\n\n"
							header, input = header_data.split("\n\n", 2)

							header = SDL4R.load(header)
							header.initialization_vector = header.initialization_vector.from_hex if header.initialization_vector
							header.session_key = header.session_key.from_hex if header.session_key

							@on_header.call(header) if @on_header
							output << input
						end
					else
						output << input
					end
				end
			end

			def on_header(&callback)
				@on_header = callback
				self
			end
		end
	end
end

