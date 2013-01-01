require_relative '../lib/cipher/filter'

describe Filter do
	subject do
		Filter.new do |input|
			input.upcase
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
			upcase_filter = Filter.new do |input|
				input.upcase
			end

			space_filter = Filter.new do |input|
				input + ' '
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
			upcase_filter = Filter.new do |input|
				input.upcase
			end
			upcase_filter.header do
				'aa'
			end
			upcase_filter.footer do
				'bb'
			end

			space_filter = Filter.new do |input|
				'(' + input + ')'
			end
			space_filter.header do
				'xx'
			end
			space_filter.footer do
				'zz'
			end

			upcase_filter.chain(space_filter)

			out = ''

			space_filter.output do |output|
				out << output
			end

			upcase_filter.input do |input|
				input << 'hello'
				input << 'world'
			end

			out.should == 'xx(aa)(HELLO)(WORLD)(bb)zz'
		end
	end
end

