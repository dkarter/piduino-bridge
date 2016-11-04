root = Dir.getwd.to_s

activate_control_app 'tcp://0.0.0.0:8080'
bind 'unix:///tmp/puma.treat-dispenser.sock'
pidfile "#{root}/tmp/pids/puma.pid"
rackup "#{root}/config.ru"
state_path "#{root}/tmp/pids/puma.state"
