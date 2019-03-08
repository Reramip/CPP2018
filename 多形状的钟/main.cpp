#include"Clocks.h"
#include"acllib.h"

void timerEvent(int id);
void keyboardEvent(int key, int event);

Clock* c;


int Setup() {
    c = new ClockCircle;
    initWindow("Clocks", DEFAULT, DEFAULT, 400, 400);
    registerTimerEvent(timerEvent);
    startTimer(0, 1000);
    registerKeyboardEvent(keyboardEvent);
    return 0;
}

void timerEvent(int id) {
    if (id == 0) {
        c->addOne();
        c->show(50, 50);
    }
}

void keyboardEvent(int key, int event)
{
    if (event != KEY_DOWN)
        return;
    switch (key) {
    case 0x51://Q
        exit(0);
    case 0x31://1
        c = new ClockCircle;
        break;
    case 0x32://2
        c = new ClockRectangular;
        break;
    case 0x33://3
        c = new ClockDigital;
        c->changeStatus(0);
        break;
    case 0x34://4
        c = new ClockDigital;
        c->changeStatus(1);
        break;
    }
}
