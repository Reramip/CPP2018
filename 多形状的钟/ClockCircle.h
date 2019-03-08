#pragma once
#include"Clock.h"

class ClockCircle :public Clock {
public:
    void changeStatus(int st = 0);
    void draw(int x = 0, int y = 0, int length = LENGTH, int height = HEIGHT);
    void show(int x = 0, int y = 0, int length = LENGTH, int height = HEIGHT);
};
