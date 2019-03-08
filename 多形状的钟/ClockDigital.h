#pragma once
#include"Clock.h"

class ClockDigital:public Clock {
    int status;//24 ±÷”0,12 ±÷”1
    int getStatus();
public:
    ClockDigital();
    void changeStatus(int st = 0);
    void draw(int x = 0, int y = 0, int length = LENGTH, int height = HEIGHT);
    void show(int x = 0, int y = 0, int length = LENGTH, int height = HEIGHT);
};
