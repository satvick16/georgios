import board
import busio
import adafruit_pca9685

i2c = busio.I2C(board.GP0, board.GP1)
pca = adafruit_pca9685.PCA9685(i2c)

while True:
    pca.write(0, 0)
    data = i2c.readfrom(0x04, 4) # Read 4 bytes from Arduino at address 0x04
    print(data)