class String
	def lshift(b)
		self.byteslice(b.length, self.length - b.length) + b
	end
end

