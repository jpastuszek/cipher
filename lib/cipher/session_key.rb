class SessionKey < String
	def self.generate(key_length)
		self.new(OpenSSL::Random.random_bytes((key_length.to_f / 8).ceil))
	end

	def self.from_encrypted_session_key(cipher_selector, password, encrypted_session_key)
		password_digest = OpenSSL::PKCS5.pbkdf2_hmac_sha1(password, 'salt', 2000, (cipher_selector.key_length.to_f / 8).ceil)

		session_key = ''

		# setting iv since ECB may not be available for all ciphers
		Decrypter.new(cipher_selector, password_digest, initialization_vector: password_digest)
		.output do |out|
			session_key << out
		end
		.input do |sink|
			sink << encrypted_session_key
		end

		return session_key
	end

	def encrypt(cipher_selector, password)
		password_digest = OpenSSL::PKCS5.pbkdf2_hmac_sha1(password, 'salt', 2000, (cipher_selector.key_length.to_f / 8).ceil)

		session_key = ''

		# setting iv since ECB may not be available for all ciphers
		Encrypter.new(cipher_selector, password_digest, initialization_vector: password_digest)
		.output do |encrypted_session_key|
			session_key << encrypted_session_key
		end
		.input do |sink|
			sink << self
		end

		return session_key
	end
end

