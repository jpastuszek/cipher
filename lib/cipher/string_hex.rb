class String
	def to_hex
		self.unpack('H*').first
	end

	def from_hex
		self.scan(/../).map { |x| x.hex }.pack('c*')
	end
end

