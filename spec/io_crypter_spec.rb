require_relative '../lib/cipher/io_crypter'
require_relative '../lib/cipher/string_base64'

describe IOEncrypter do
	it 'should encrypt input stream to output stream' do
		cipher_selector = CipherSelector.new.cipher('IDEA').mode('CBC').longest_key(128)
		
		input = StringIO.new('hello world')
		output = StringIO.new

		IOEncrypter.new(input, output, cipher_selector, 'test' * 16, initialization_vector: 'test' * 16)

		output.string.should include('IDEA')
		output.string.to_base64.should == "Y2lwaGVyICJJREVBIgptb2RlICJDQkMiCmtleV9sZW5ndGggMTI4CmluaXRpYWxpemF0aW9uX3ZlY3RvciAiNzQ2NTczNzQ3NDY1NzM3NDc0NjU3Mzc0NzQ2NTczNzQ3NDY1NzM3NDc0NjU3Mzc0NzQ2NTczNzQ3NDY1NzM3NDc0NjU3Mzc0NzQ2NTczNzQ3NDY1NzM3NDc0NjU3Mzc0NzQ2NTczNzQ3NDY1NzM3NDc0NjU3Mzc0NzQ2NTczNzQiCgrqA9rpn1aaC6V9VEkW/0Up"
	end
end

describe IODecrypter do
	it 'should decrypt input stream to output stream' do
		input = StringIO.new("Y2lwaGVyICJJREVBIgptb2RlICJDQkMiCmtleV9sZW5ndGggMTI4CmluaXRpYWxpemF0aW9uX3ZlY3RvciAiNzQ2NTczNzQ3NDY1NzM3NDc0NjU3Mzc0NzQ2NTczNzQ3NDY1NzM3NDc0NjU3Mzc0NzQ2NTczNzQ3NDY1NzM3NDc0NjU3Mzc0NzQ2NTczNzQ3NDY1NzM3NDc0NjU3Mzc0NzQ2NTczNzQ3NDY1NzM3NDc0NjU3Mzc0NzQ2NTczNzQiCgrqA9rpn1aaC6V9VEkW/0Up".from_base64)
		output = StringIO.new

		IODecrypter.new(input, output, 'test' * 16)

		output.string.should == 'hello world'
	end
end

