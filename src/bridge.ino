#include <Servo.h>

// Initial servo position
int pos = 0;

// create a servo object to control the servo
Servo myservo;

const int ledPin = 12;

void setup() {
  // setup led
  pinMode(ledPin, OUTPUT);

  // setup serial port (usb)
  Serial.begin(9600);

  // attach to pin 9 for controlling the servo
  // the servo should also be attached to the power (5v to middle wire on the
  // servo) and ground (to brown or black wire on the servo)
  myservo.attach(9);

  // notify user on machine init
  flash(2);
}

void loop() {
  if (Serial.available()) {
    flash(Serial.read() - '0');
    dispense();
  }

  delay(1000);
}

void flash(int n) {
  for (int i = 0; i <= n; i++) {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
}

void dispense() {
  myservo.write(0);
  delay(1000); // wait for servo to reach its position
  myservo.write(90);
  delay(1000); // wait for servo to reach its position
  myservo.write(180);
  delay(1000); // wait for servo to reach its position
}
