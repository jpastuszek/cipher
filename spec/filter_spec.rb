require_relative '../lib/cipher/filter'

describe Filter do
	subject do
		Filter.new do |input, output|
			output << input.upcase
		end
	end

	it 'should process input into output' do
		out = ''
		subject.output do |output|
			out << output
		end
		subject.input do |input|
			input << 'hello'
			input << ' '
			input << 'world'
		end

		out.should == 'HELLO WORLD'
	end

	it 'should allow passing multiple output values for one input' do
		out = ''
		subject = Filter.new do |input, output|
			output << input.upcase
			output << ' '
			output << 'WORLD'
		end

		subject.output do |output|
			out << output
		end
		subject.input do |input|
			input << 'hello'
		end

		out.should == 'HELLO WORLD'
	end

	it 'should pass nil values' do
		out = []
		subject = Filter.new do |input, output|
			output << (input ? input.upcase : nil)
		end

		subject.output do |output|
			out << output
		end
		subject.input do |input|
			input << nil
			input << 'hello'
			input << nil
		end

		out.should == [nil, 'HELLO', nil]
	end

	it 'may not produce value for input' do
		out = []
		subject = Filter.new do |input, output|
			output << input.upcase if input
		end

		subject.output do |output|
			out << output
		end
		subject.input do |input|
			input << nil
			input << 'hello'
			input << nil
		end

		out.should == ['HELLO']
	end

	it 'should output header before filtering' do
		out = ''
		subject.output do |output|
			out << output
		end
		subject.header do
			'>> '
		end
		subject.input do |input|
			input << 'hello'
			input << ' '
			input << 'world'
		end

		out.should == '>> HELLO WORLD'
	end

	it 'should output footer after filtering' do
		out = ''
		subject.output do |output|
			out << output
		end
		subject.footer do
			' <<'
		end
		subject.input do |input|
			input << 'hello'
			input << ' '
			input << 'world'
		end

		out.should == 'HELLO WORLD <<'
	end

	describe 'chaining' do
		it 'should allow chaining of filters' do
			upcase_filter = Filter.new do |input, output|
				output << input.upcase
			end

			space_filter = Filter.new do |input, output|
				output << input + ' '
			end

			out = ''

			upcase_filter.chain(space_filter)


			space_filter.output do |output|
				out << output
			end

			upcase_filter.input do |input|
				input << 'hello'
				input << 'world'
			end

			out.should == 'HELLO WORLD '
		end

		it 'should call all header and footer handlers' do
			upcase_filter = Filter.new do |input, output|
				output << input.upcase
			end
			upcase_filter.header do
				'aa'
			end
			upcase_filter.footer do
				'bb'
			end

			bracket_filter = Filter.new do |input, output|
				output << '(' + input + ')'
			end
			bracket_filter.header do
				'xx'
			end
			bracket_filter.footer do
				'zz'
			end

			upcase_filter.chain(bracket_filter)

			out = ''

			bracket_filter.output do |output|
				out << output
			end

			upcase_filter.input do |input|
				input << 'hello'
				input << 'world'
			end

			out.should == 'xx(aa)(HELLO)(WORLD)(bb)zz'
		end
	end

	describe 'nesting' do
		it 'should allow nesting many filters' do
			upcase_filter = Filter.new do |input, output|
				output << input.upcase
			end

			bracket_filter = Filter.new do |input, output|
				output << '(' + input + ')'
			end

			space_filter = Filter.new do |input, output|
				output << input + ' '
			end

			upcase_filter.nest(bracket_filter)
			upcase_filter.nest(space_filter)

			output = ''
			upcase_filter.output do |out|
				output << out
			end
			upcase_filter.input do |input|
				input << 'hello'
				input << 'world'
			end

			output.should == '(HELLO) (WORLD) '
		end

		it 'should call all header and footer handlers' do
			upcase_filter = Filter.new do |input, output|
				output << input.upcase
			end
			upcase_filter.header do
				'aa'
			end
			upcase_filter.footer do
				'bb'
			end

			bracket_filter = Filter.new do |input, output|
				output << '(' + input + ')'
			end
			bracket_filter.header do
				'xx'
			end
			bracket_filter.footer do
				'zz'
			end

			space_filter = Filter.new do |input, output|
				output << input + ' '
			end
			space_filter.header do |input|
				'>'
			end
			space_filter.footer do |input|
				'<'
			end

			upcase_filter.nest(bracket_filter).nest(space_filter)

			out = ''

			upcase_filter.output do |output|
				out << output
			end

			upcase_filter.input do |input|
				input << 'hello'
				input << 'world'
			end

			out.should == '>xx (aa) (HELLO) (WORLD) (bb) zz <'
		end
	end
end

