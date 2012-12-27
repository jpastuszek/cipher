require 'base64'

class String
	def to_base64_multiline
		Base64.encode64(self)
	end

	def to_base64
		Base64.strict_encode64(self)
	end

	def from_base64
		Base64.strict_decode64(self)
	end
end

