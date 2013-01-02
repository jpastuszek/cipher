Feature: Encrypting and decrypting streams with CLI application
	In ordre to be useful in shell cipher provides CLI application
	This application can take input stream and produce encrypted or decrypted stream

	Background:
		#Given cipher will print it's output
		#Given decipher will print it's output

	Scenario: Usage display
		Given cipher argument -h
		Given cipher is running
		When I wait for cipher termination
		Then cipher output should include 'Usage:'

	Scenario: Encrypt to stdout with AES256-CBC by default
		Given cipher is running
		When I write test.txt to cipher input
		Then I wait for cipher termination
		And cipher output should include following entries: 
			| cipher "AES" |
			| mode "CBC" |
			| key_size 256 |
			| session_key |
			| initialization_vector |

