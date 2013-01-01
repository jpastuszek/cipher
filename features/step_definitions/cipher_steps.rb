Given /content of ([^ ]*) file is used as ([^ ]*) input/ do |file, program|
	(@input ||= {})[program] = (Pathname.new('features') + 'support' + file).read
end

When /following arguments are used to run ([^ ]*):/ do |program, arguments|
	arguments.raw.flatten.each do |args|
		((@arguments ||= {})[program] ||= []) << args
	end
end

When /I run ([^ ]*) with output passed through ([^ ]*) for each argument/ do |program_out, program_in|
	@arguments[program_out].each do |arguments|
		step "#{program_out} argument #{arguments}"
		step "#{program_out} is running"
		(@programs ||= ProgramList.new)[program_out].input.write @input[program_out]
		(@programs ||= ProgramList.new)[program_out].input.close
		step "I wait for #{program_out} termination"

		step "#{program_in} is running"
		step "I write #{program_out} output to #{program_in} input"
		step "I wait for #{program_in} termination"

		#((@output ||= {})[program_in] ||= []) << (@programs ||= ProgramList.new)[program_in].output
		
		begin
			(@programs ||= ProgramList.new)[program_in].output.should == @input[program_out]
		rescue => e
			puts "Bad output for arguments: #{arguments}"
			puts "#{program_out} output: "
			puts (@programs ||= ProgramList.new)[program_out].output.inspect
			puts "#{program_in} output: "
			puts (@programs ||= ProgramList.new)[program_in].output.inspect
			raise
		end
	end
end

Then /for each argument I should get ([^ ]*) output same as input of ([^ ]*)/ do |program_out, program_in|
	@output[program_out].each_with_index do |output, index|
		begin
			output.should == @input[program_in]
		rescue
			puts "Bad output for arguments: #{@arguments[program_out][index]}"
		end
	end
end

