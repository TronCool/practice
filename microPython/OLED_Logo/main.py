from robot import robot, eyeOpen, eyeClose, qr
from rainbow import base36, rainbow
from machine import I2C, Pin
import micropython
import ssd1306
import random
import time
import re


def initSSD1306():
    # OLED 和 8266 的接线方法：SDL <-> D4(Pin2), SDA <-> D3(Pin0)
    i2c = I2C(-1, Pin(2), Pin(0))
    return ssd1306.SSD1306_I2C(128, 64, i2c)


def drawBitmap(bitmap, x=0, y=0, w=0, show=False):
    w = w or getAutoWidth(bitmap)
    for dy, i in enumerate(bitmap):
        for dx, c in enumerate(('0'*w+bin(i)[2:])[-w:]): #左侧剪掉"0b1"三个字符, bitmap每一行前有个1是为了避免bitmap里转16进制保存的时候有前导0被压缩
            buff.pixel(dx + x, dy + y, int(c))
    show and buff.show()  # 如果传入True则刷新显示器

def getAutoWidth(bitmap): #获取bitmap里最宽的一行宽度
    return max([len(bin(i)[2:]) for i in bitmap])

def explode(s, w): # 字串按指定长度切成数组
    return re.sub('(' + '.' * w + ')', r'\1,', s).strip(',').split(',') # python3: re.findall('(' + '.' * w + ')', s) 


def getFontCode(num):
    f = open('font.hex', 'rb')
    f.seek((base36[num[0]] * 36 + base36[num[1]] - 1) * 16)
    code = "".join([hex(i|256)[3:] for i in f.read(16)]) # python3: bytes.hex(f.read(16))
    f.close()
    return code


def h2b(h): # 16进制变成2进制
    return bin(int(h, 16))[2:]


def getFontBitmap(fontCode): # 16进制数字转成可以供画图的数据数num组
    return [int(i,2) for i in explode(h2b(fontCode)[1:], 11)]


buff = initSSD1306()
buff.text("Tron Cool Robot", 3, 2)
buff.text("---------------", 3, 10)


def robotBlink():
    buff.fill_rect(0, 16, 128, 48, 1)
    drawBitmap(robot, 10, 20, 62)  # 机器人显示在10,20的位置，宽62高39
    drawBitmap(qr, 83, 19, 42, True)  # 二维码显示在83,19的位置，宽42高42
    times = 3
    while times:
        time.sleep(random.getrandbits(5)/10)  # 随机延时 0-3.2秒
        # 眨眼，眼睛偏移机器人13,11，所以显示在23,31的位置，宽38高18
        drawBitmap(eyeClose, 23, 31, 38, True)
        drawBitmap(eyeOpen, 23, 31, 38, True)
        times -= 1


def rainbowWord():
    buff.fill_rect(0, 16, 128, 48, 0)
    word = explode(rainbow[random.getrandbits(8) % 226], 2)
    x, y = 0, 18
    for h in word:
        drawBitmap(getFontBitmap(getFontCode(h)), x, y, 11)
        x += 13
        if x > 128:
            x = 0
            y += 16
    buff.show()
    time.sleep(2 + random.getrandbits(5)/10)  # 随机延时 0-3.2秒


runTimes = 100
while runTimes:
    robotBlink()
    rainbowWord()
    runTimes -= 1
