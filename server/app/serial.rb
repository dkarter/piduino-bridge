require 'serialport'

class Serial
  def initialize
    device = ENV.fetch('DEVICE_PATH')
    @serial = SerialPort.new(device, 9600, 8, 1, SerialPort::NONE)
  end

  def send_signal
    serial.write('8')
  end

  private

  attr_reader :serial
end
