require_relative '../lib/cipher/envelope'

describe Envelope::SDL do
	it 'should allow defining header values' do
		message = ''

		Envelope::SDL.new do
			cipher 'AES'
			mode 'CBC'
			key_length 128
		end.each do |data|
			message << data
		end.body do |sink|
			4.times do
				sink << 'test'
			end
		end

		message.should == <<EOF.chomp
cipher "AES"
mode "CBC"
key_length 128

testtesttesttest
EOF
	end
end

