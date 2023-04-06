#include <Servo.h>

// servo setup
Servo my_servo;
const uint8_t SERVO_PIN = 9;

// buzzer setup
const uint8_t BUZZER_PIN = 6;
int counter = 0;

bool water_is_done = false;

void setup() {
  // Set up the servo
  my_servo.attach(SERVO_PIN);
  my_servo.write(0);

  // Set up the buzzer
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int analogPin = A0;
  int analogValue = 0;

  analogValue = analogRead(analogPin);
  Serial.println(analogValue);

  if (water_is_done) {
    analogWrite(BUZZER_PIN, 200);
    long timer = millis();
    delay(10000);
    analogWrite(BUZZER_PIN, 0);
    while (1) {
      ;
    }
  }

  // Move the servo
  if (analogValue > 700){
    // open valve
    my_servo.write(0);
    counter++;
  }
  else{
    my_servo.write(180);
    counter = 0;
  }
  delay(1000);

 if(counter > 10){
    water_is_done = true;
 }
}
