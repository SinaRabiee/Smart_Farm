import paho.mqtt.client as paho
import time
import serial
import schedule


ACCESS_TOKEN = "ESP8266-NEW"
broker = "demo.thingsboard.io"
port = 1883

client1 = paho.Client("control1")
client1.username_pw_set(ACCESS_TOKEN)
client1.connect(broker, port, keepalive=60)


def main_func():
    arduino = serial.Serial("COM5", 9600)
    arduino_data_LDR = arduino.readline()
    if arduino_data_LDR == b"0\r\n":
        light = "0"
    else:
        light = "1"
    arduino_data_Mositure = arduino.readline()
    if arduino_data_Mositure == b"0\r\n":
        Moisture = "0"
    else:
        Moisture = "1"
    # Moisture = str(
    #     arduino_data_Mositure[0 : len(arduino_data_Mositure)].decode("utf-8")
    # )[:-1]
    arduino_data_Temp = arduino.readline()
    Temp = str(arduino_data_Temp[0 : len(arduino_data_Temp)].decode("utf-8"))[:-1]

    ########
    payload = "{"
    payload += '"temperature":' + Temp + ","
    payload += '"moisture":' + Moisture + ","
    payload += '"light":' + light
    payload += "}"
    ret = client1.publish("v1/devices/me/telemetry", payload)
    print(payload)
    ##########


list_values = []
list_in_floats = []

print("Program started")
# Setting up the Arduino
schedule.every(1).seconds.do(main_func)

while True:
    schedule.run_pending()
    time.sleep(0.5)
