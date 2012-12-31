require_relative '../lib/cipher/Filter_chain'

describe FilterChain do
	it 'should allow chaining of filters' do
		upcase_filter = Filter.new do |input|
			input.upcase
		end

		space_filter = Filter.new do |input|
			input + ' '
		end

		out = ''

		subject << upcase_filter
		subject << space_filter

		subject.output do |output|
			out << output
		end

		subject.input do |input|
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
			'>>'
		end
		upcase_filter.footer do
			'<<'
		end

		space_filter = Filter.new do |input|
			input + ' '
		end
		space_filter.header do
			'(('
		end
		space_filter.footer do
			'))'
		end

		subject.header do
			'->'
		end
		subject.footer do
			'<-'
		end

		subject << upcase_filter
		subject << space_filter

		out = ''

		subject.output do |output|
			out << output
		end

		subject.input do |input|
			input << 'hello'
			input << 'world'
		end

		out.should == '->((>> HELLO WORLD << ))<-'
	end
end

