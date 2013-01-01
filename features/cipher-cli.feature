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

	@test
	Scenario: Encryption and decryption with different settings
		Given cipher argument -p test
		Given decipher argument -p test
		Given content of test.txt file is used as cipher input
		When following arguments are used to run cipher:
			| -k 128 |
			| -k 192 |
			| -k 192 |
			| -m CFB |
			| -m ECB |
			| -m CFB |
			| -m CFB-1 |
			| -m CFB-8 |
			| -m OFB |
			| -m OFB-1 |
			| -m OFB-8 |
			| -c BF |
			| -c BF -m CFB |
			| -c BF -k 192 |
		And I run cipher with output passed through decipher for each argument

