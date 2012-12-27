require_relative '../lib/cipher/io_crypter'

log = Logger.new('test.log')

describe IOEncrypter do
	it 'should encrypt input stream to output stream' do
		cipher_selector = CipherSelector.new.cipher('IDEA').mode('CBC').longest_key(128)
		
		input = StringIO.new('hello world')
		output = StringIO.new

		IOEncrypter.new(input, output, cipher_selector, 'test' * 16, initialization_vector: 'test' * 16, log: log)

		output.string.should include('IDEA')
		output.string.base64.should == "Y2lwaGVyICJJREVBIgptb2RlICJDQkMiCmtleV9sZW5ndGggMTI4CmluaXRpYWxpemF0aW9uX3ZlY3RvciAiZEdWemRIUmxjM1IwWlhOMGRHVnpkSFJsYzNSMFpYTjBkR1Z6ZEhSbGMzUjBaWE4wZEdWemRIUmxjM1IwWlhOMGRHVnpkSFJsYzNSMFpYTjBkR1Z6ZEE9PSIKCuoD2umfVpoLpX1USRb/RSk="
	end
end

describe IODecrypter do
	it 'should decrypt input stream to output stream' do
		input = StringIO.new("Y2lwaGVyICJJREVBIgptb2RlICJDQkMiCmtleV9sZW5ndGggMTI4CmluaXRpYWxpemF0aW9uX3ZlY3RvciAiZEdWemRIUmxjM1IwWlhOMGRHVnpkSFJsYzNSMFpYTjBkR1Z6ZEhSbGMzUjBaWE4wZEdWemRIUmxjM1IwWlhOMGRHVnpkSFJsYzNSMFpYTjBkR1Z6ZEE9PSIKCuoD2umfVpoLpX1USRb/RSk=".unbase64)
		output = StringIO.new

		IODecrypter.new(input, output, 'test' * 16, log: log)

		output.string.should == 'hello world'
	end
end

