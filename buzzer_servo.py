import board
import pwmio
import time

from adafruit_motor import servo

# servo setup
pwm = pwmio.PWMOut(board.GP17, duty_cycle=2∗∗15, frequency=50)
my_servo = servo.Servo(pwm)

# buzzer setup
buzzbuzz = pwmio.PWMOut(board.GP16, 
                        duty_cycle = 1000, 
                        frequency = 150, 
                        variable_frequency = True)

water_is_done = False

while True:
    if water_is_done:
        break
    
    for angle in range(0, 180, 5):
        my_servo.angle = angle
        time.sleep (0.05)
    for angle in range(180 , 0, −5):
        my_servo.angle = angle
        time.sleep (0.05)

buzzbuzz.duty_cycle = 40000
