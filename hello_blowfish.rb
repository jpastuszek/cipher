puts 'test'
require 'openssl'
require 'base64'

#p OpenSSL::Cipher.ciphers
cipher = OpenSSL::Cipher::Cipher.new('blowfish')
#cipher = OpenSSL::Cipher.new('blowfish')
cipher.encrypt

key = cipher.random_key
iv = cipher.random_iv

data = cipher.update('hello world') + cipher.final

puts Base64.encode64(key)
puts Base64.encode64(iv)
puts Base64.encode64(data)

decipher = OpenSSL::Cipher::Cipher.new('blowfish')
#decipher = OpenSSL::Cipher.new('blowfish')
decipher.key = key
decipher.iv = iv
puts decipher.update(data) + decipher.final

