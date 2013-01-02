## Life cycle

Given /^([^ ]*) argument (.*)/ do |program, argument|
	(@programs ||= ProgramList.new)[program] << argument
end

Given /([^ ]*) is loaded/ do |program|
	(@programs ||= ProgramList.new)[program].load
end

Given /([^ ]*) is spawned/ do |program|
	(@programs ||= ProgramList.new)[program].spawn
end

Given /([^ ]*) is terminated/ do |program|
	(@programs ||= ProgramList.new)[program].terminate
end

Given /([^ ]*) will print it's output/ do |program|
	(@programs ||= ProgramList.new)[program].print_output
end

When /([^ ]*) is running/ do |program|
	(@programs ||= ProgramList.new)[program].spawn
end

Then /I wait for (.*) termination/ do |program|
	(@programs ||= ProgramList.new)[program].wait_exit
	#puts (@programs ||= ProgramList.new)[program].output
end

Then /([^ ]*) exit status should be (.+)/ do |program, status|
	(@programs ||= ProgramList.new)[program].exit_status.should == status.to_i
end

After do
	@programs.terminate if @programs
end

## Common input tasks

Given /content of ([^ ]*) file is used as ([^ ]*) input/ do |file, program|
	(@input ||= {})[program] = (Pathname.new('features') + 'support' + file).read
end

When /I close ([^ ]*) input/ do |program|
	(@programs ||= ProgramList.new)[program].input.close
end

When /I write ([^ ]*) input/ do |program|
	(@programs ||= ProgramList.new)[program].input.write @input[program]
	step "I close #{program} input"
end

When /I write ([^ ]*) to ([^ ]*) input/ do |file, program|
	(@programs ||= ProgramList.new)[program].input.write (Pathname.new('features') + 'support' + file).read
	step "I close #{program} input"
end

When /I write ([^ ]*) output to ([^ ]*) input/ do |program_out, program_in|
 #p (@programs ||= ProgramList.new)[program_out].output

	(@programs ||= ProgramList.new)[program_in].input.write (@programs ||= ProgramList.new)[program_out].output
	step "I close #{program_in} input"
end

## Common output tests

Then /([^ ]*) output should include '(.*)'/ do |program, entry|
	(@programs ||= ProgramList.new)[program].output.should include(entry)
end

Then /([^ ]*) output should not include '(.*)'/ do |program, entry|
	(@programs ||= ProgramList.new)[program].output.should_not include(entry)
end

Then /([^ ]*) output should include '(.*)' (.+) time/ do |program, entry, times|
	(@programs ||= ProgramList.new)[program].output.scan(entry).size.should == times.to_i
end

Then /([^ ]*) last output line should include '(.*)'/ do |program, entry|
	(@programs ||= ProgramList.new)[program].output.lines.to_a.last.should include(entry)
end

Then /([^ ]*) output should include following entries:/ do |program, log_entries|
	@program_log = (@programs ||= ProgramList.new)[program].output
	log_entries.raw.flatten.each do |entry|
		@program_log.should include(entry)
	end
end

When /I run ([^ ]*) with output sent through ([^ ]*)/ do |program_out, program_in|
	step "#{program_out} is running"
	step "I write #{program_out} input"
	step "I wait for #{program_out} termination"

	step "#{program_in} is running"
	step "I write #{program_out} output to #{program_in} input"
	step "I wait for #{program_in} termination"
end

Then /([^ ]*) output should be the same as ([^ ]*) input/ do |program_out, program_in|
	(@programs ||= ProgramList.new)[program_out].output.should == @input[program_in]
end

# For debugging
Then /([^ ]*) output is displayed/ do |program|
	print (@programs ||= ProgramList.new)[program].output
end

