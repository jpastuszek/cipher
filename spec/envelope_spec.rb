require_relative '../lib/cipher/envelope'

describe Envelope::SDL do
	it 'should generate message' do
		message = ''

		Envelope::SDL.new do
			cipher 'AES'
			mode 'CBC'
			key_length 128
			initialization_vector 'abc'
		end
		.each do |data|
			message << data
		end
		.body do |sink|
			4.times do
				sink << 'test'
			end
		end

		message.should == <<EOF.chomp
cipher "AES"
mode "CBC"
key_length 128
initialization_vector "abc"

testtesttesttest
EOF
	end

	it 'should load streamed message' do
		header = nil
		body = ''
		test_message = <<EOF.chomp
cipher "AES"
mode "CBC"
key_length 128
initialization_vector "abc"

testtesttesttest

hello
EOF

		Envelope::SDL::Loader.new
		.on_header do |h|
			header = h
		end
		.on_body do |data|
			body << data
		end
		.on_end do
			body << '.'
		end
		.load do |sink|
			# put message chunk by chunk
			test_message.chars.each_slice(3) do |slice|
				sink << slice.join
			end
		end

		header.cipher.should == 'AES'
		header.mode.should == 'CBC'
		header.key_length.should == 128
		header.initialization_vector.should == 'abc'
		body.should == "testtesttesttest\n\nhello."
	end
end

