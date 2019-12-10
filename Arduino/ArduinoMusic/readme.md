#### 文件含意
|文件名|含义|
|--|--|
|ArduinoMusic.ino|主文件，歌曲数据以及播放代码|
|Tonelib.h|头文件，定义了每个音调频率，音调对应点亮的LED，和节拍长短|
|transfer.html|乐谱转换工具，直观输入乐谱转换为程序可用的编码|
|ArduinoMusic.fzz|接线图纸文件|

#### 转换工具
[点此进入转换工具](//troncool.github.io/practice/Arduino/ArduinoMusic/transfer.html)

#### 接线方式
1. 喇叭，接A2和GND。A2可以在程序里设置成其它Pin。
2. LED, 低音567，中音1234567，高音12对应12个led。按顺序接线Pin为 A0,2,3,4,5,6,7,8,9,10,11,12。可以在Tonelib.h里的port方法中设置成其它Pin。

![接线图](wire_connection.png)


