require_relative '../lib/cipher/session_key'

describe SessionKey do
	it 'should be of given length in bits' do
		SessionKey.generate(128).length.should == 128 / 8
		SessionKey.generate(256).length.should == 256 / 8
	end

	it 'should be random' do
		SessionKey.generate(128).should_not == SessionKey.generate(128)
	end

	it 'can be encrypted' do
		session_key = SessionKey.generate(256)
		
		encrypted_session_key = session_key.encrypt('AES', 'test')
		encrypted_session_key.should_not == session_key
		encrypted_session_key.length.should == session_key.length

		encrypted_session_key.should == session_key.encrypt('AES', 'test')
		encrypted_session_key.should_not == session_key.encrypt('AES', 'test2')
	end

	it 'can be created from encrypted key' do
		session_key = SessionKey.generate(256)
		encrypted_session_key = session_key.encrypt('AES', 'test')

		SessionKey.from_encrypted_session_key('AES', 'test', encrypted_session_key).should == session_key
	end
end

