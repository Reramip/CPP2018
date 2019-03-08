#include"Clock.h"
#include"acllib.h"
#include<time.h>
#include<math.h>
#include<string>
#include<iostream>

#define RAD(x) ((x) / 360.0 * 2 * 3.1415926535)
using namespace std;


Clock::Clock() :h(0), m(0), s(0), status(0){
    now();
}

int Clock::getH() {
    return h;
}

int Clock::getM() {
    return m;
}

int Clock::getS() {
    return s;
}

void Clock::now() {
    time_t time_seconds = time(0);
	struct tm now_time;
	localtime_s(&now_time,&time_seconds);
    h = now_time.tm_hour;
    m = now_time.tm_min;
    s = now_time.tm_sec;
}


void Clock::timeGet(int& h,int& m,int& s) {
    h = this->h;
    m = this->m;
    s = this->s;
}

void Clock::addOne(){
    ++s;
    if (s >= 60) {
        s = 0;
        ++m;
        if (m >= 60) {
            m = 0;
            ++h;
            if (h >= 24) {
                h = 0;
            }
        }
    }
}


