require_relative '../lib/cipher/crypter'

log = Logger.new('test.log')

describe Encrypter do
	subject do
		Encrypter.new(CipherSelector.new.cipher('AES').mode('CBC').key_length(128), 'k' * 16, initialization_vector: 'iv' * 8, log: log)
	end

	it 'should encrypt data stream with given cipher specs and key' do
		encrypted = ''
		subject.each do |data|
			encrypted << data
		end

		subject.process do |sink|
			20.times do
				sink << 'test'
			end
		end

		encrypted.to_base64.should == 'KVbwK9Xp3EKIRvkg4+eudG1FCe2vK1jp1dp8Jb0eUeicVe5Bdne31afl5Z6khytT7HCsghF1S8CYWiukCeSYgzt2G8pie35ecVj1g4NvSgTl1ns0mTkTBUKDEHcEVL57'
	end

	it 'should provide initialization vector used' do
		subject.initialization_vector.should == 'iv' * 8
	end

	it 'should provide random initialization vector if not specified' do
		Encrypter.new(CipherSelector.new.cipher('AES').mode('CBC').key_length(128), 'k' * 16, log: log).initialization_vector.length.should == 16
	end

	it 'should provide nil initialization vector if not needed' do
		Encrypter.new(CipherSelector.new.cipher('AES').mode('ECB').key_length(128), 'k' * 16, log: log).initialization_vector.should be_nil
	end

	it 'should work with custom key length' do
		subject = Encrypter.new(CipherSelector.new.cipher('BF').mode('CBC').key_length(64), 'k' * 16, initialization_vector: 'iv' * 8, log: log)

		encrypted = ''
		subject.each do |data|
			encrypted << data
		end

		subject.process do |sink|
			20.times do
				sink << 'test'
			end
		end

		encrypted.to_base64.should == 'NVh81Aq0+TixCzB77Pp3gXiov1nuaexLKJzKS3iOe9SGHzfY0kHfvANM5MTB5wpfPvB0ZHo6Jup9zp8el92UNp9m9a1+xLg6OgLj4bMYcynPg7sdem8nPQ=='
	end

	it 'should encrypt with padding' do
		subject = Encrypter.new(CipherSelector.new.cipher('AES').mode('CBC').key_length(128), 'k' * 16, initialization_vector: 'iv' * 8, log: log)

		encrypted = ''

		subject.each do |data|
			encrypted << data
		end

		subject.process do |sink|
			4.times do
				sink << 'a' * 16
			end
		end

		encrypted.length.should > 4 * 16
	end

	it 'should allow disabling of padding' do
		subject = Encrypter.new(CipherSelector.new.cipher('AES').mode('CBC').key_length(128), 'k' * 16, initialization_vector: 'iv' * 8, padding: false, log: log)

		encrypted = ''

		subject.each do |data|
			encrypted << data
		end

		subject.process do |sink|
			4.times do
				sink << 'a' * 16
			end
		end

		encrypted.length.should == 4 * 16
	end
end

describe Decrypter do
	subject do
		Decrypter.new(CipherSelector.new.cipher('AES').mode('CBC').key_length(128), 'k' * 16, 'iv' * 8, log: log)
	end

	it 'should decrypt data stream with given cipher specs, key and initialization vector' do
		decrypted = ''
		subject.each do |data|
			decrypted << data
		end

		subject.process do |sink|
			sink << 'KVbwK9Xp3EKIRvkg4+eudG1FCe2vK1jp1dp8Jb0eUeicVe5Bdne31afl5Z6khytT7HCsghF1S8CYWiukCeSYgzt2G8pie35ecVj1g4NvSgTl1ns0mTkTBUKDEHcEVL57'.from_base64
		end

		decrypted.should == 'test' * 20
	end

	it 'should work with custom key length' do
		subject = Decrypter.new(CipherSelector.new.cipher('BF').mode('CBC').key_length(64), 'k' * 16, 'iv' * 8, log: log)

		decrypted = ''
		subject.each do |data|
			decrypted << data
		end

		subject.process do |sink|
			sink << 'NVh81Aq0+TixCzB77Pp3gXiov1nuaexLKJzKS3iOe9SGHzfY0kHfvANM5MTB5wpfPvB0ZHo6Jup9zp8el92UNp9m9a1+xLg6OgLj4bMYcynPg7sdem8nPQ=='.from_base64
		end

		decrypted.should == 'test' * 20
	end

	it 'should decrypt message without padding when padding is disabled' do
		subject = Decrypter.new(CipherSelector.new.cipher('AES').mode('CBC').key_length(128), 'k' * 16, 'iv' * 8, padding: false, log: log)

		decrypted = ''
		subject.each do |data|
			decrypted << data
		end

		subject.process do |sink|
			sink << "m10dFkVinkrM6fI/JLSMMSvAaf399xYIYbvNe0MY5CKGm6BBOoWh0ZlG5MBgT+ZpEtOOD0IGyOY3U2k2vFTrhw==".from_base64
		end

		decrypted.should == 'a' * 4 * 16
	end
end

