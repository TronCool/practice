from machine import I2C, Pin
import micropython
import ssd1306
import random
import time

# 机器人图，62 x 39
robot = [0x7fffff3fff3fffff, 0x7ffffe1ffe1fffff, 0x7ffffccffccfffff, 0x7ffffccffccfffff, 0x7ffff213f213ffff,
         0x7ffff333f333ffff, 0x7fff333333333fff, 0x7fff333333333fff, 0x7ff00000000001ff, 0x7fc00000000000ff,
         0x7f8000000000007f, 0x7f000000007e003f, 0x7f00000001ff803f, 0x7e00000003ffc01f, 0x7e00000007ffe01f,
         0x7e001f800ffff01f, 0x7e003fc00ffff01f, 0x62007fe01fc3f811, 0x4200fff01f81f810, 0x4201fff81f81f810,
         0x4201f9f81f81f810, 0x4201f0f81f81f810, 0x4201f0f81fc3f810, 0x4201f9f80ffff010, 0x4201fff80ffff010,
         0x4200fff007ffe010, 0x42007fe003ffc010, 0x62003fc001ff8011, 0x7e001f80007e001f, 0x7e0000000000001f,
         0x7e0000000000001f, 0x7e0000000000001f, 0x7e001e79e79e001f, 0x7e001e79e79e001f, 0x7f001e79e79e003f,
         0x7f001e79e79e003f, 0x7f8000000000007f, 0x7fc00000000000ff, 0x7ff00000000003ff]

# 眼睛 38 x 18
eyeOpen = [0x4000000fc0, 0x4000003ff0, 0x4000007ff8, 0x400000fffc, 0x43f001fffe, 0x47f801fffe, 0x4ffc03f87f,
           0x5ffe03f03f, 0x7fff03f03f, 0x7f3f03f03f, 0x7e1f03f03f, 0x7e1f03f87f, 0x7f3f01fffe, 0x7fff01fffe,
           0x5ffe00fffc, 0x4ffc007ff8, 0x47f8003ff0, 0x43f0000fc0]

eyeClose = [0x4000000000, 0x4000000000, 0x4000000000, 0x4000000000, 0x4000000000, 0x4000000000, 0x4000000000,
            0x4000000000, 0x4000000000, 0x4000000000, 0x4000000000, 0x4000000000, 0x4000000000, 0x4000000000,
            0x5ffe00fffc, 0x4000000000, 0x4000000000, 0x4000000000]
# 二维码
qr = [0x4000c0fc000, 0x4000c0fc000, 0x4ffcf0fcffc, 0x4ffcf0fcffc, 0x4c0ccfccc0c, 0x4c0ccfccc0c, 0x4c0cfcfcc0c,
      0x4c0cfcfcc0c, 0x4c0ccc3cc0c, 0x4c0ccc3cc0c, 0x4ffcfcccffc, 0x4ffcfcccffc, 0x4000cccc000, 0x4000cccc000,
      0x7fffc33ffff, 0x7fffc33ffff, 0x7ff0ff0cccc, 0x7ff0ff0cccc, 0x4f3333cfcff, 0x4f3333cfcff, 0x730cc0fcc03,
      0x730cc0fcc03, 0x4fc3f00fc0f, 0x4fc3f00fc0f, 0x7cc03cc0f33, 0x7cc03cc0f33, 0x7fffccf0fc0, 0x7fffccf0fc0,
      0x4000f00f303, 0x4000f00f303, 0x4ffccc3f00f, 0x4ffccc3f00f, 0x4c0cf3f3ff3, 0x4c0cf3f3ff3, 0x4c0cf0ccc3f,
      0x4c0cf0ccc3f, 0x4c0cf0c3cf0, 0x4c0cf0c3cf0, 0x4ffcf003f0f, 0x4ffcf003f0f, 0x4000f03ccf3, 0x4000f03ccf3]


def initSSD1306():
    # OLED 和 8266 的接线方法：SDL <-> D4(Pin2), SDA <-> D3(Pin0)
    i2c = I2C(-1, Pin(2), Pin(0))
    return ssd1306.SSD1306_I2C(128, 64, i2c)


@micropython.native
def drawBitmap(data, offsetX=0, offsetY=0, show=False):
    for y, i in enumerate(data):
        for x, c in enumerate(bin(i)[3:]):
            buff.pixel(x + offsetX, y + offsetY, int(c))
    show and buff.show()  # 如果传入True则刷新显示器


buff = initSSD1306()
buff.text("Tron Cool Robot", 3, 2)
buff.text("---------------", 3, 10)
buff.fill_rect(0, 16, 128, 48, 1)
drawBitmap(robot, 10, 20)  # 机器人尺寸62 x 39
drawBitmap(qr, 83, 19, True)  # 二维码尺寸42 x 42

while True:
    time.sleep(random.getrandbits(5)/10)  # 随机延时 0-3.2秒
    # 眨一次眼，眼睛偏移机器人13 x 11
    drawBitmap(eyeClose, 23, 31, True)
    drawBitmap(eyeOpen, 23, 31, True)
