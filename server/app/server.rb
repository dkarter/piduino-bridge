require 'dotenv'
Dotenv.load

require 'sinatra'
require_relative './serial'

# Server for raspberry pi
class Server < Sinatra::Base
  configure do
    set :bind, '0.0.0.0'
    set :port, 8080
    set :server, :puma
  end

  get '/blink' do
    @serial = Serial.new
    @serial.send_signal
    'Hello World'
  end
end
