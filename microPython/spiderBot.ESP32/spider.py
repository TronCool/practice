"""
Author: Tairraos (xiaole.tao@gmail.com)
Last Update: 2020-02-01
"""
from machine import Pin, PWM

class Leg_node:
    def __init__(self, pin):
        self.pwm = PWM(Pin(pin), freq=50, duty=0)

    def angle(self, degree):
        self.pwm.duty(int((degree * 11.11111 + 500) / 19.53125))

class Leg:
    def __init__(self, waist_pin, knee_pin, ankle_pin):
        self.waist = Leg_node(waist_pin)
        self.knee = Leg_node(knee_pin)
        self.ankle = Leg_node(ankle_pin)

    def move(self, waist_degree, knee_degree, ankle_degree):
        self.waist.angle(waist_degree)
        self.knee.angle(knee_degree)
        self.ankle.angle(ankle_degree)

class Spider:
    def __init__(self, pins):
        