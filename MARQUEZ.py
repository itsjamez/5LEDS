import serial
import time

arduino = serial.Serial(port='COM4', baudrate=9600, timeout=1)
time.sleep(1)  

def main():
    while True:
        command = input("Enter ON or OFF (type 'EXIT' to quit): ")
        
        if command == "EXIT":
            print("Exiting program...")
            break

        elif command == "ON":
            print("LEDs are ON.")
            print("Available Patterns:")
            print("1 - Blink")
            print("2 - Fade")
            print("3 - Midlane")
            print("4 - Running")
            print("5 - Back and forth")

        
            arduino.write((command + "\n").encode())
            time.sleep(1)

            choice = input("Choose pattern (1–5): ")
            
            arduino.write((choice + "\n").encode())
            time.sleep(1)

        elif command == "OFF":
            arduino.write((command + "\n").encode())
            time.sleep(1)

        else:
            print("Invalid command. Please enter ON or OFF.")

    arduino.close()

main()