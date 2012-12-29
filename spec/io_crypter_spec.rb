require_relative '../lib/cipher/io_crypter'
require_relative '../lib/cipher/string_base64'

describe IOEncrypter do
	it 'should encrypt input stream to output stream' do
		cipher_selector = CipherSelector.new.cipher('IDEA').mode('CBC').longest_key(128)
		
		input = StringIO.new('hello world')
		output = StringIO.new

		IOEncrypter.new(input, output, cipher_selector, 'password', initialization_vector: 'test' * 16)

		output.string.should include('IDEA')
		output.string.length.should > 30
	end

	it 'should use defferent session key for each run' do
		cipher_selector = CipherSelector.new.cipher('IDEA').mode('CBC').longest_key(128)
		
		input = StringIO.new('hello world')
		output = StringIO.new
		IOEncrypter.new(input, output, cipher_selector, 'password', initialization_vector: 'test' * 16)

		input.rewind
		output2 = StringIO.new
		IOEncrypter.new(input, output2, cipher_selector, 'password', initialization_vector: 'test' * 16)

		output.string.should_not == output2.string
	end
end

describe IODecrypter do
	it 'should decrypt input stream to output stream' do
		input = StringIO.new("Y2lwaGVyICJJREVBIgptb2RlICJDQkMiCmtleV9sZW5ndGggMTI4CmluaXRpYWxpemF0aW9uX3ZlY3RvciAiNzQ2NTczNzQ3NDY1NzM3NDc0NjU3Mzc0NzQ2NTczNzQ3NDY1NzM3NDc0NjU3Mzc0NzQ2NTczNzQ3NDY1NzM3NDc0NjU3Mzc0NzQ2NTczNzQ3NDY1NzM3NDc0NjU3Mzc0NzQ2NTczNzQ3NDY1NzM3NDc0NjU3Mzc0NzQ2NTczNzQiCnNlc3Npb25fa2V5ICIwODUxNTNjMTFiOGY3Yjc1NTdmMzliN2I3MTE0ZjUyOCIKCoDR4z2zhNATQUACb8v5MX8=".from_base64)
		output = StringIO.new

		IODecrypter.new(input, output, 'password')

		output.string.should == 'hello world'
	end
end

