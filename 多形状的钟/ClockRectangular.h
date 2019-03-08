#pragma once
#include"Clock.h"

class ClockRectangular :public Clock {
public:
    void changeStatus(int st = 0);
    void draw(int x = 0, int y = 0, int width = LENGTH, int height = LENGTH);
    void show(int x = 0, int y = 0, int length = LENGTH, int height = HEIGHT);
};
