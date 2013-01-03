require_relative 'spec_helper'

describe IOEncrypter do
	it 'should encrypt input stream to output stream' do
		cipher_selector = CipherSelector.new.cipher('IDEA').mode('CBC').longest_key(128)
		
		input = StringIO.new('hello world')
		output = StringIO.new

		IOEncrypter.new(input, output, cipher_selector, 'password', initialization_vector: 't' * 16, session_key: 's' * 16)

		output.string.should include('IDEA')
		output.string.to_base64.should == "Y2lwaGVyICJJREVBIgptb2RlICJDQkMiCmtleV9zaXplIDEyOAppbml0aWFsaXphdGlvbl92ZWN0b3IgIjc0NzQ3NDc0NzQ3NDc0NzQ3NDc0NzQ3NDc0NzQ3NDc0IgpzZXNzaW9uX2tleSAiMjkwMzI5MTAxOGUyZTY2YzI5MDMyOTEwMThlMmU2NmMyOTY5ZTVhOGEwZGQ0NTViIgoKQaa+VoEhcFYOgrrdgDxSdQ=="
	end

	it 'should use defferent session key for each run if not specified' do
		cipher_selector = CipherSelector.new.cipher('IDEA').mode('CBC').longest_key(128)
		
		input = StringIO.new('hello world')
		output = StringIO.new
		IOEncrypter.new(input, output, cipher_selector, 'password', initialization_vector: 'test' * 16)

		input.rewind
		output2 = StringIO.new
		IOEncrypter.new(input, output2, cipher_selector, 'password', initialization_vector: 'test' * 16)

		output.string.should_not == output2.string
	end

	it 'should use defferent initialization vector for each run if not specified' do
		cipher_selector = CipherSelector.new.cipher('IDEA').mode('CBC').longest_key(128)
		
		input = StringIO.new('hello world')
		output = StringIO.new
		IOEncrypter.new(input, output, cipher_selector, 'password', session_key: 's' * 16)

		input.rewind
		output2 = StringIO.new
		IOEncrypter.new(input, output2, cipher_selector, 'password', session_key: 's' * 16)

		output.string.should_not == output2.string
	end
end

describe IODecrypter do
	it 'should decrypt input stream to output stream' do
		input = StringIO.new("Y2lwaGVyICJJREVBIgptb2RlICJDQkMiCmtleV9zaXplIDEyOAppbml0aWFsaXphdGlvbl92ZWN0b3IgIjc0NzQ3NDc0NzQ3NDc0NzQ3NDc0NzQ3NDc0NzQ3NDc0IgpzZXNzaW9uX2tleSAiMjkwMzI5MTAxOGUyZTY2YzI5MDMyOTEwMThlMmU2NmMyOTY5ZTVhOGEwZGQ0NTViIgoKQaa+VoEhcFYOgrrdgDxSdQ==".from_base64)
		output = StringIO.new

		IODecrypter.new(input, output, 'password')

		output.string.should == 'hello world'
	end
end

