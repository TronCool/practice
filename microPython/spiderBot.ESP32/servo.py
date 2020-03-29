"""
Author: Tairraos (xiaole.tao@gmail.com)
Last Update: 2020-01-26
"""
from machine import Pin, PWM

class Servo:

    def __init__(self, pin, min_angle=0, max_angle=180, min_us=500, max_us=2500, freq=50):
        self.min_angle = min_angle
        # self.max_angle = max_angle
        self.min_us = min_us
        # self.max_us = max_us
        self.freq = freq
        self.pwm = PWM(Pin(pin), freq=freq, duty=0)
        self.angle_range = max_angle - min_angle
        self.us_range = max_us - min_us

    def angle(self, degree):
        us = (degree % 360 - self.min_angle) / self.angle_range * self.us_range + self.min_us
        duty = int(us // (1000000 / self.freq / 1024))
        self.pwm.duty(duty)
