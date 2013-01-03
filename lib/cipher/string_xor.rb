class String
	def ^(b)
		bytes.zip(b.bytes).map{|a, b| ((a || 0) ^ (b || 0)).chr(Encoding::ASCII_8BIT)}.join
	end
end

