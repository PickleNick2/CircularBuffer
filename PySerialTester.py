import serial
import time

def main():
    try:

        # Open the serial port
        ser = serial.Serial(port="COM3", baudrate=9600, timeout=1)
        print("Serial port opened successfully.")
        send_and_read(ser)
        
    except serial.SerialException as e:
        print(f"Error opening serial port: {e}")


def send_bytes(ser: serial):
    while True:
        ser.write(b'Hello, Serial Port\n')

def send_and_read(ser: serial):
    try:
        while True:
            # ser.write(b'Hello, Serial Port!\n')
            ser.write(b'Another, message here!\n')
            print("Data written to serial port.")
            
            buffer_response = ser.readline()
            if buffer_response:
                print(f"Current data in circular buffer: {buffer_response.decode('utf-8').strip()}")

            time.sleep(1) 
     
    except KeyboardInterrupt:
        print("Keyboard Interrupt received.")

    finally:
        if ser.is_open:
            ser.close()
            print("Serial port closed.")
        else:
            print("Serial port was not open.")

if __name__ == "__main__":
    main()

