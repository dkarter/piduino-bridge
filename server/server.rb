require 'sinatra'
require_relative './serial'

get '/' do
  @serial = Serial.new
  @serial.send_signal
  'Hello World'
end
