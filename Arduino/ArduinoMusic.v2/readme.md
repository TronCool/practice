#### 说明
v2版本，LED灯随机点亮。每个节拍切换的时候变换一次LED

#### 文件含意
|文件名|含义|
|--|--|
|ArduinoMusic.ino|主文件，歌曲数据以及播放代码|
|Tonelib.h|头文件，定义了每个音调频率和节拍长短|

#### 转换工具
[点此进入转换工具](//troncool.github.io/practice/Arduino/ArduinoMusic/transfer.html)

#### 接线方式
1. 喇叭，接9和GND。9可以在程序里设置成其它Pin。
2. LED, +接2-8这7个Pin，每个节拍随机亮灭。

![接线图](figv3.png)


