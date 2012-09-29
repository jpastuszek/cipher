
#==============================================================================#
# $Id: test-loadpath.rb,v 1.3 2005/04/15 09:42:52 yuya Exp $
#==============================================================================#

require 'testcase'

#==============================================================================#

class LoadPathTestCase < Test::Unit::TestCase
  include ExerbTestCase

  def name
    return 'test-loadpath'
  end

  def test_loadpath
    assert_equal(%|["."]\n|, execute_exe(@name))
  end

end # LoadPathTestCase

#==============================================================================#
#==============================================================================#
