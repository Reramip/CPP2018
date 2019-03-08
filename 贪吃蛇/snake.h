#pragma once

class Snake {
    int xHead, yHead, length, direction, number;
    int xTail, yTail;
    bool alive;
    void collision();
public:
    Snake(int num);
    bool isAlive();
    void changeDirection(int direction);
    void move();
    void eat();
    int getLength();
};
