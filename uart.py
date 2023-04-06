import board
import pwmio
import time
import busio

from adafruit_motor import servo

# servo setup
pwm = pwmio.PWMOut(board.GP19, duty_cycle=2**15, frequency=50)
my_servo = servo.Servo(pwm)

# buzzer setup
buzzbuzz = pwmio.PWMOut(board.GP15,
                        duty_cycle = 0,
                        frequency = 150,
                        variable_frequency = True)

# uart setup
uart = busio.UART(board.GP0, board.GP1, 9600)

while True:
    data = uart.readline(0.1)
    print("henry")
    if data:
        print("william")
        print(data.decode().strip())

    time.sleep(0.1)
