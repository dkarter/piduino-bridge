require 'sinatra'
require_relative './serial'

class Server < Sinatra::Base
  configure do
    set :bind, '0.0.0.0'
    set :port, 8080
    set :server, :puma
  end

  get '/' do
    @serial = Serial.new
    @serial.send_signal
    'Hello World'
  end
end
