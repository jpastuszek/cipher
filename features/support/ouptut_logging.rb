After do |scenario|
	if(scenario.failed?)
		if @input
			@input.each_pair do |name, data|
				STDERR.puts "Input for #{name} was:"
				STDERR.puts	data.inspect
			end
		end

		if @programs
			@programs.each_pair do |name, program|
				STDERR.puts "Output of #{name}:"
				STDERR.puts program.output.inspect
			end
		end
	end
end
