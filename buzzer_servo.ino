#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Servo setup
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
#define SERVO_FREQ 50
#define SERVO_PIN 19
#define SERVO_MIN_US 600
#define SERVO_MAX_US 2400
#define SERVO_STEP 5

// Buzzer setup
#define BUZZER_PIN 15
#define BUZZER_FREQ 150
#define BUZZER_DUTY_CYCLE 0

bool water_is_done = false;

void setup() {
  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  if (water_is_done) {
    break;
  }

  for (int angle = 0; angle < 180; angle += SERVO_STEP) {
    int us = map(angle, 0, 180, SERVO_MIN_US, SERVO_MAX_US);
    pwm.setPWM(SERVO_PIN, 0, us);
    delay(50);
  }

  for (int angle = 180; angle > 0; angle -= SERVO_STEP) {
    int us = map(angle, 0, 180, SERVO_MIN_US, SERVO_MAX_US);
    pwm.setPWM(SERVO_PIN, 0, us);
    delay(50);
  }

  delay(100);
}

void loop() {
  pwm.setPWM(BUZZER_PIN, 0, BUZZER_DUTY_CYCLE);
  delay(100);
}
