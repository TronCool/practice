from PIL import Image
import re

# font.png是用抓图软件抓的，文泉驿点阵字体，9pt大小是11x11, 每行一个字，截成16宽，非常高的图片
# 使用window记事本的话，行间距是5px
img = Image.open('font.png').convert('1')
imgData = ['0' if i == 0 else '1' for i in list(img.getdata())]
binData = re.findall('('+'.'*16+')', ''.join(imgData))  # 每16个点
binData = [i[0:11] for i in binData].reverse()
fontData = []
for i in range(767):  # 767个汉字
    buf = []
    for j in range(11):  # 11px字高
        buf.append(binData.pop())
    fontData.append(buf)
    for j in range(5):  # 5px行间距
        binData.pop()

# 此时，fontData里都是二进制汉字，每个字是11个11位的二进制
# 下面把11个11位的二进制连成一个二进制，并在前面加上1，防止有前导0，然后转成16进制用于写文件
# 转换出来的是一个31位的16进制数
fontHex = []
for i in fontData:
    fontHex.append(hex(int("1"+"".join([j[0:11] for j in i]), 2)))

f=open("font.hex", "wb")
for i in fontHex:
  f.write(bytes.fromhex('0'+i[2:])) #bytes.fromhex需要补足偶数位数字。去掉‘0x’前面加‘0’
f.close()

# 读取编号为25的汉字“书” getCode(25):
def getCode(id):
    f=open("font.hex", "rb")
    f.seek((id-1)*16)
    code = bytes.hex(f.read(16))
    f.close()