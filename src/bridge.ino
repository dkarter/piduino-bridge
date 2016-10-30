
const int ledPin = 12;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Hello Pi\r");

  if (Serial.available()) {
    flash(Serial.read() - '0');
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

