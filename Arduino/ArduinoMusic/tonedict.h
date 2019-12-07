#ifndef TONE_DEFINE
#define TONE_DEFINE

int melody(char s) {  // 频率
    if (s == 'w') { return  349; }   // 低音4#
    else if (s == 'x') { return  392; }   // 低音5#
    else if (s == 'y') { return  440; }   // 低音6#
    else if (s == 'z') { return  494; }   // 低音7#
    else if (s == '1') { return  523; }   // 中音1#
    else if (s == '2') { return  578; }   // 中音2#
    else if (s == '3') { return  659; }   // 中音3#
    else if (s == '4') { return  698; }   // 中音4#
    else if (s == '5') { return  784; }   // 中音5#
    else if (s == '6') { return  880; }   // 中音6# 
    else if (s == '7') { return  988; }   // 中音7#
    else if (s == 'a') { return  1046; }  // 高音1#
    else if (s == 'b') { return  1175; }  // 高音2#
    else if (s == 'c') { return  1318; }  // 高音3#
    else { return  0; }
}

int port(char s) { // 点亮LED的端口
    if (s == 'x') { return  1; }   // 低音5#
    else if (s == 'y') { return  2; }   // 低音6#
    else if (s == 'z') { return  3; }   // 低音7#
    else if (s == '1') { return  4; }   // 中音1#
    else if (s == '2') { return  5; }   // 中音2#
    else if (s == '3') { return  6; }   // 中音3#
    else if (s == '4') { return  7; }   // 中音4#
    else if (s == '5') { return  8; }   // 中音5#
    else if (s == '6') { return  9; }   // 中音6#
    else if (s == '7') { return  10; }  // 中音7#
    else if (s == 'a') { return  11; }  // 高音1#
    else if (s == 'b') { return  12; }  // 高音2#
    else { return  0; }
}

int duration(char s, int speed) {  // 算出节拍时长
    float unit = 60000 / speed;
    if (s == 'x') { return  int(unit * 4); }   // 4拍
    else if (s == 'y') { return  int(unit * 3); }   // 3拍
    else if (s == 'z') { return  int(unit * 2); }   // 2拍
    else if (s == '1') { return  int(unit * 1); }   // 1拍
    else if (s == '2') { return  int(unit / 2); }   // 1/2拍
    else if (s == '3') { return  int(unit / 4); }   // 1/4拍
    else if (s == '4') { return  int(unit / 8); }   // 1/8拍
    else { return  0; }
}


#endif
