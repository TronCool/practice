from machine import I2C, Pin
import ssd1306
import math

i2c = I2C(-1, Pin(5), Pin(4))
buff = ssd1306.SSD1306_I2C(128, 64, i2c)

buff.text("Hello World", 10, 2)
buff.text("-----------", 10, 10)

x0 = 0
y0 = 40

for x in range(128):
    y = int(math.sin(x/3.14) * 22 + 40)
    buff.line(x0, y0, x, y, 1)
    x0, y0 = x, y

buff.show()