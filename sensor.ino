int sensorPin = A0;
int digitalValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  digitalValue = analogRead(sensorPin);
  Serial.print("digital value = ");
  Serial.print(digitalValue);
  delay(1000);
}
