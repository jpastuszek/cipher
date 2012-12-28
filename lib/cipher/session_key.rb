class SessionKey < String
	def self.generate(key_length)
		self.new(OpenSSL::Random.random_bytes((key_length.to_f / 8).ceil))
	end

	def self.from_encrypted_session_key(cipher, password, encrypted_session_key)
		key_cipher = CipherSelector.new
			.cipher(cipher)
			.preferred_mode('ECB')
			.key_length(encrypted_session_key.length * 8)

		password_digest = OpenSSL::PKCS5.pbkdf2_hmac_sha1(password, 'salt', 2000, encrypted_session_key.length)

		session_key = ''

		# setting iv since ECB may not be available for all ciphers
		Decrypter.new(key_cipher, password_digest, initialization_vector: encrypted_session_key, padding: false)
		.each do |out|
			session_key << out
			return session_key if session_key.length >= encrypted_session_key.length
		end
		.process do |sink|
			sink << encrypted_session_key
			sink << encrypted_session_key
		end
	end

	def encrypt(cipher, password)
		key_cipher = CipherSelector.new
			.cipher(cipher)
			.preferred_mode('ECB')
			.key_length(self.length * 8)

		password_digest = OpenSSL::PKCS5.pbkdf2_hmac_sha1(password, 'salt', 2000, self.length)

		# setting iv since ECB may not be available for all ciphers
		Encrypter.new(key_cipher, password_digest, initialization_vector: self, padding: false)
		.each do |encrypted_session_key|
			return encrypted_session_key
		end
		.process do |sink|
			sink << self
		end
	end
end

