$message

def test
  $message = system('ls')

  puts type($message)
end

test()
