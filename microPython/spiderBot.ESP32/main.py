import blynklib_mp as blynklib
import network
import time
from machine import Pin

WIFI_SSID = 'Tairraos_Kernel'
WIFI_PASS = 'xiaolesalanok'
BLYNK_AUTH = 'A1_ZkOyBF1zr2wTM_NfoVM4wAh4MNmRt'

p1=Pin(19,Pin.OUT)
p2=Pin(18,Pin.OUT)
p3=Pin(5,Pin.OUT)
p4=Pin(17,Pin.OUT)
p5=Pin(16,Pin.OUT)

print("Connecting to WiFi network '{}'".format(WIFI_SSID))
wifi = network.WLAN(network.STA_IF)
wifi.active(True)
wifi.connect(WIFI_SSID, WIFI_PASS)
while not wifi.isconnected():
    time.sleep(1)
    print('WiFi connect retry ...')
print('WiFi IP:', wifi.ifconfig()[0])

print("Connecting to Blynk server...")
blynk = blynklib.Blynk(BLYNK_AUTH)

while True:
    blynk.run()
