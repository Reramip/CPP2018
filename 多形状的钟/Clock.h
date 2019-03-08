#pragma once
const int LENGTH = 300;
const int HEIGHT = 200;



class Clock {
    int h, m, s;
    int status;
    void now();
public:
    Clock();
    int getH();
    int getM();
    int getS();
    void timeGet(int& h,int& m,int& s);
    void addOne();
    virtual void changeStatus(int st)=0;
    virtual void show(int x, int y, int length, int height)=0;
};
