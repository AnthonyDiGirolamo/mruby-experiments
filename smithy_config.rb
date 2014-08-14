SmithyConfig.software_root(ENV['HOME']+'/sw')
puts SmithyConfig.arch('x86_64')
def test_call
  puts "inside test_call"
  return 64
end
