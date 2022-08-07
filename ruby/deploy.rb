require 'net/http'

$account = 'econverse'

def login

def get_auth_token(apikey, apitoken)
  payload = LoginPayload.new(apikey, apitoken)
  puts payload.apitoken
end

loginApiRoute = "http://api.vtexcommercestable.com.br/api/vtexid/apptoken/login?an=#{$account}" 

get_auth_token('key', 'token')
