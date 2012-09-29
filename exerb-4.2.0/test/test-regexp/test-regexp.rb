
#==============================================================================#
# $Id: test-regexp.rb,v 1.2 2003/11/29 08:55:59 yuya Exp $
#==============================================================================#

p(/Foo/)
p(/Foo/i)
p(/Foo/e)
p(/Foo/s)
p(/Foo/m)

p(/Foo Bar/i)
p(/Foo\s+Bar/i)

p(/Foo Bar/i =~ "Foo Bar")
p(/Foo Bar/i =~ "Foo\tBar")
p(/Foo Bar/i =~ "Foo\nBar")
p(/Foo\s+Bar/i =~ "Foo Bar")
p(/Foo\s+Bar/i =~ "Foo\tBar")
p(/Foo\s+Bar/i =~ "Foo\nBar")

#==============================================================================#
#==============================================================================#
