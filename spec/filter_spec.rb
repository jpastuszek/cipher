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
end

