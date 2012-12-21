require 'base64'

class String
	def base64_multiline
		Base64.encode64(self)
	end

	def base64
		Base64.strict_encode64(self)
	end

	def unbase64
		Base64.strict_decode64(self)
	end
end

