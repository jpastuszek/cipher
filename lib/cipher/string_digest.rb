class String
	def digest(size, salt = 'salt', iterations = 2000)
		OpenSSL::PKCS5.pbkdf2_hmac_sha1(self, salt, iterations, (size.to_f / 8).ceil)
	end
end

