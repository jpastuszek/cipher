Feature: Encrypting and decrypting streams with different encryption parameters

	Background:
		Given cipher argument -p test
		Given decipher argument -p test
		Given content of test.txt file is used as cipher input

	@encryption @aes
	Scenario: Encryption with AES 128 ECB
		Given cipher argument -c AES -k 128 -m ECB
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @aes
	Scenario: Encryption with AES 192 ECB
		Given cipher argument -c AES -k 192 -m ECB
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @aes
	Scenario: Encryption with AES 256 ECB
		Given cipher argument -c AES -k 128 -m ECB
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @aes
	Scenario: Encryption with AES 128 CFB
		Given cipher argument -c AES -k 128 -m CFB
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @aes
	Scenario: Encryption with AES 128 OFB
		Given cipher argument -c AES -k 128 -m OFB
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @aes @native-sub-block @cfb @test
	Scenario: Encryption with AES 128 CFB-1
		Given cipher argument -c AES -k 128 -m CFB-1
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @aes @native-sub-block @cfb
	Scenario: Encryption with AES 128 CFB-8
		Given cipher argument -c AES -k 128 -m CFB-8
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @aes @custom-to-native-sub-block @cfb
	Scenario: Encryption with AES 128 CFB-8
		Given cipher argument -c AES -k 128 -m CFB-8 -B
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @aes @custom-sub-block @cfb
	Scenario: Encryption with AES 128 CFB-16
		Given cipher argument -c AES -k 128 -m CFB-16
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @aes @custom-sub-block @cfb
	Scenario: Encryption with AES 128 CFB-64
		Given cipher argument -c AES -k 128 -m CFB-64
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @aes @custom-sub-block @ofb
	Scenario: Encryption with AES 128 OFB-8
		Given cipher argument -c AES -k 128 -m OFB-8
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @aes @custom-sub-block @ofb
	Scenario: Encryption with AES 128 OFB-16
		Given cipher argument -c AES -k 128 -m OFB-16
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @aes @custom-sub-block @ofb
	Scenario: Encryption with AES 128 OFB-64
		Given cipher argument -c AES -k 128 -m OFB-64
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @bf
	Scenario: Encryption with BF 128 ECB
		Given cipher argument -c BF -k 128 -m ECB
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @bf
	Scenario: Encryption with BF 192 ECB
		Given cipher argument -c BF -k 192 -m ECB
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @bf
	Scenario: Encryption with BF 192 CFB
		Given cipher argument -c BF -k 192 -m CFB
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @bf
	Scenario: Encryption with BF 192 OFB
		Given cipher argument -c BF -k 192 -m OFB
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

	@encryption @bf
	Scenario: Encryption with BF 192 CBC
		Given cipher argument -c BF -k 192 -m CBC
		When I run cipher with output sent through decipher
		Then decipher output should be the same as cipher input

