import serial
import time

# Set up the serial connection (use your specific port)
arduino_port = 'COM3'  # Replace 'COM3' with the port your Arduino is connected to (e.g., /dev/ttyUSB0 for Linux)
baud_rate = 9600  # Must match the baud rate in the Arduino sketch
ser = serial.Serial(arduino_port, baud_rate, timeout=1)

# Allow time for connection to establish
time.sleep(2)

print("Reading from Arduino:")
while True:
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').strip()
        print(f"Received: {line}")

# Close the serial port when finished
ser.close()
