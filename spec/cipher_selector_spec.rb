require_relative '../lib/cipher/cipher_selector'

describe CipherSelector do
	it 'should provide list of available ciphers' do
		subject.ciphers.should include 'AES'
	end

	it 'should raise error if selected cipher does not exist' do
		lambda do
			subject.cipher('XES')
		end.should raise_error RuntimeError, "unsupported cipher XES"
	end

	it 'should provide CipherSelector::ModeSelector for given cipher' do
		subject.cipher('AES').should be_a CipherSelector::ModeSelector
	end

	it 'should provide flat list of all ciphers, modes and key lengths supported' do
		flat = []
		subject.flat_list do |cipher, mode, key|
			flat << [cipher, mode, key]
		end

		flat.should include ["AES", "CBC", 128]
	end

	describe CipherSelector::ModeSelector do
		subject do
			CipherSelector.new.cipher('AES')
		end

		it 'should provide name of the cipher' do
			subject.cipher.should == 'AES'
		end

		it 'should provide list of available modes' do
			subject.modes.should include 'CBC'
		end

		it 'should raise error if selected mode does not exist' do
			lambda do
				subject.mode('XBC')
			end.should raise_error RuntimeError, "unsupported mode XBC for cipher AES"
		end

		it 'should provide CipherSelector::ModeSelector::KeyLengthSelector for given mode' do
			subject.mode('CBC').should be_a CipherSelector::ModeSelector::KeyLengthSelector
		end

		it 'should support selecting given mode' do
			subject.mode('CBC').mode.should == 'CBC'
		end

		it 'should support selecting preffered mode' do
			subject.preferred_mode('CBC').mode.should == 'CBC'
		end

		it '#preferred_mode should select none mode when not available' do
			CipherSelector.new.cipher('RC4').preferred_mode('CBC').mode.should == 'none'
		end
	end

	describe CipherSelector::ModeSelector::KeyLengthSelector do
		subject do
			CipherSelector.new.cipher('AES').mode('CBC')
		end

		it 'should provide name of the cipher' do
			subject.cipher.should == 'AES'
		end

		it 'should provide name of the mode' do
			subject.mode.should == 'CBC'
		end

		it 'should provide list of available key lengths' do
			subject.key_lengths.should include 128
		end

		it 'should raise error if selected key lentght does not exist' do
			lambda do
				subject.key_length(123)
			end.should raise_error RuntimeError, "unsupported key length 123 for mode CBC for cipher AES"
		end

		it 'should raise error if selecting key length is not supported' do
			lambda do
				CipherSelector.new.cipher('DES').mode('CBC').key_length(128)
			end.should raise_error RuntimeError, "cipher DES does not support key length selection"
		end

		it 'should provide CipherSelector::ModeSelector::KeyLengthSelector::Cipher for given key length' do
			subject.key_length(128).should be_a CipherSelector::ModeSelector::KeyLengthSelector::Cipher
		end

		it 'should support selecting given key length' do
			subject.key_length(128).openssl_cipher_name.should == 'AES128'
		end

		it 'should support selecting custom key length with supported cipher' do
			cipher = CipherSelector.new.cipher('RC2').mode('CBC').key_length(92)
			cipher.openssl_cipher_name.should == 'RC2-CBC'
			cipher.key_length.should == 92
			cipher.need_key_length_set?.should be_true
		end

		it 'should preferr selecting predefined key length with supported cipher if requested matches' do
			cipher = CipherSelector.new.cipher('RC2').mode('CBC').key_length(128)
			cipher.openssl_cipher_name.should == 'RC2'
			cipher.key_length.should == 128
			cipher.need_key_length_set?.should be_false
		end

		it 'should support selecting longest available key length' do
			subject.longest_key.openssl_cipher_name.should == 'AES256'
		end

		it '#longest_key should select nil key length for ciphers not supporting key lenghts' do
			cipher = CipherSelector.new.cipher('DES').mode('CBC').longest_key
			cipher.openssl_cipher_name.should == 'DES'
			cipher.key_length.should be_nil
		end

		it '#longest_key should select longest predefined key length when custom key length is supported' do
			cipher = CipherSelector.new.cipher('RC2').mode('CBC').longest_key
			cipher.openssl_cipher_name.should == 'RC2'
			cipher.key_length.should == 128
		end

		it '#longest_key should select 256 key length for ciphers supporting only any key length' do
			cipher = CipherSelector.new.cipher('IDEA').mode('CBC').longest_key
			cipher.openssl_cipher_name.should == 'IDEA'
			cipher.key_length.should == 256
			cipher.need_key_length_set?.should be_true
		end

		it '#longest_key should select given key length for ciphers supporting only any key length' do
			cipher = CipherSelector.new.cipher('IDEA').mode('CBC').longest_key(128)
			cipher.openssl_cipher_name.should == 'IDEA'
			cipher.key_length.should == 128
			cipher.need_key_length_set?.should be_true
		end
	end
end

