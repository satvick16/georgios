import time
import board
import analogio

adc = analogio.AnalogIn(board.GP28)

while True:
    # Read the ADC value and convert it to a voltage
    adc_value = adc.value
    voltage = adc_value * 5 / 65535

    # Print the voltage to the console
    #print("Voltage: {:.2f} V".format(voltage))
    print(voltage)

    # Wait for a short time before reading again
    time.sleep(0.1)
