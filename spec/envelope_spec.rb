require_relative 'spec_helper'

describe Envelope::SDL do
	it 'should generate message' do
		message = ''

		Envelope::SDL.new do
			cipher 'AES'
			mode 'CBC'
			key_size 128
			initialization_vector 'abc'
		end
		.output do |data|
			message << data
		end
		.input do |sink|
			4.times do
				sink << 'test'
			end
		end

		message.should == <<EOF.chomp
cipher "AES"
mode "CBC"
key_size 128
initialization_vector "616263"

testtesttesttest
EOF
	end

	it 'should load streamed message' do
		header = nil
		body = ''
		test_message = <<EOF.chomp
cipher "AES"
mode "CBC"
key_size 128
initialization_vector "616263"

testtesttesttest

hello
EOF

		Envelope::SDL::Loader.new
		.on_header do |h|
			header = h
		end
		.output do |data|
			body << data
		end
		.on_close do
			body << '.'
		end
		.input do |sink|
			# put message chunk by chunk
			test_message.chars.each_slice(3) do |slice|
				sink << slice.join
			end
		end

		header.cipher.should == 'AES'
		header.mode.should == 'CBC'
		header.key_size.should == 128
		header.initialization_vector.should == 'abc'
		body.should == "testtesttesttest\n\nhello."
	end
end

