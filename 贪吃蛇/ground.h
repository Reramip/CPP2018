#pragma once
#include"utility.h"

class Ground {
    int position[MAX][MAX];
    int direction[MAX][MAX];
public:
    Ground();
    void show();
    friend class Snake;
    friend class Food;
};
