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
		cipher_selector = CipherSelector.new.cipher('AES').mode('CBC').key_length(128)	

		encrypted_session_key = session_key.encrypt(cipher_selector, 'test')
		encrypted_session_key.should_not == session_key

		encrypted_session_key.should == session_key.encrypt(cipher_selector, 'test')
		encrypted_session_key.should_not == session_key.encrypt(cipher_selector, 'test2')
	end

	it 'can be encrypted (192)' do
		session_key = SessionKey.generate(192)
		cipher_selector = CipherSelector.new.cipher('AES').mode('CBC').key_length(192)	
		
		encrypted_session_key = session_key.encrypt(cipher_selector, 'test')
		encrypted_session_key.should_not == session_key

		encrypted_session_key.should == session_key.encrypt(cipher_selector, 'test')
		encrypted_session_key.should_not == session_key.encrypt(cipher_selector, 'test2')
	end

	it 'can be created from encrypted key' do
		session_key = SessionKey.generate(256)
		cipher_selector = CipherSelector.new.cipher('AES').mode('CBC').key_length(256)	
		encrypted_session_key = session_key.encrypt(cipher_selector, 'test')

		SessionKey.from_encrypted_session_key(cipher_selector, 'test', encrypted_session_key).should == session_key

		session_key = SessionKey.generate(192)
		cipher_selector = CipherSelector.new.cipher('AES').mode('CBC').key_length(192)	
		encrypted_session_key = session_key.encrypt(cipher_selector, 'test')

		SessionKey.from_encrypted_session_key(cipher_selector, 'test', encrypted_session_key).should == session_key
	end
end

