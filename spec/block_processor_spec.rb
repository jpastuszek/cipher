require_relative 'spec_helper'
describe BlockSlicer do
	subject do
		BlockSlicer.new(4 * 8)
	end

	it 'should slice up input data into given size chunks' do
		out = []
		subject.output do |output|
			out << output
		end	

		subject.input do |input|
			input << '123456'
			input << '7'
			input << '89'
			input << '0123'
			input << '4567890'
			input << '12'
		end

		out.should == %w{1234 5678 9012 3456 7890 12}
	end
end

