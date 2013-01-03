class SessionKey < String
	def self.generate(key_size)
		self.new(OpenSSL::Random.random_bytes((key_size.to_f / 8).ceil))
	end

	def self.from_encrypted_session_key(cipher_selector, password, encrypted_session_key)
		password_digest = password.digest(cipher_selector.key_size)
		key_cipher_selector = CipherSelector.new.cipher(cipher_selector.cipher).preferred_mode('ECB').key_size(cipher_selector.key_size)

		session_key = ''

		# setting iv since ECB may not be available for all ciphers
		Decrypter.new(key_cipher_selector, password_digest, initialization_vector: password_digest)
		.output do |out|
			session_key << out
		end
		.input do |sink|
			sink << encrypted_session_key
		end

		return session_key
	end

	def encrypt(cipher_selector, password)
		password_digest = password.digest(cipher_selector.key_size)
		key_cipher_selector = CipherSelector.new.cipher(cipher_selector.cipher).preferred_mode('ECB').key_size(cipher_selector.key_size)

		session_key = ''

		# setting iv since ECB may not be available for all ciphers
		Encrypter.new(key_cipher_selector, password_digest, initialization_vector: password_digest)
		.output do |encrypted_session_key|
			session_key << encrypted_session_key
		end
		.input do |sink|
			sink << self
		end

		return session_key
	end
end

