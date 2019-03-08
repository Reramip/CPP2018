#include"utility.h"
#include"acllib.h"
#include"food.h"
#include"snake.h"
#include"ground.h"
#include<string>
using namespace std;

extern Ground ground;
extern Food food;
Snake snake1(SNAKE1);
Snake snake2(SNAKE2);
bool restart = false;

void keyboardEvent(int key,int _event) {
    if (_event != KEY_DOWN) {
        return;
    }
    if (key == 0x57) {//W
        snake1.changeDirection(UP);
    }
    if (key == 0x53) {//S
        snake1.changeDirection(DOWN);
    }
    if (key == 0x41) {//A
        snake1.changeDirection(LEFT);
    }
    if (key == 0x44) {//D
        snake1.changeDirection(RIGHT);
    }
    if (key == VK_UP) {
        snake2.changeDirection(UP);
    }
    if (key == VK_DOWN) {
        snake2.changeDirection(DOWN);
    }
    if (key == VK_LEFT) {
        snake2.changeDirection(LEFT);
    }
    if (key == VK_RIGHT) {
        snake2.changeDirection(RIGHT);
    }
}

void timerEvent(int id) {
    if (id == 0) {
        snake1.move();
        snake2.move();
        if (!snake1.isAlive() && snake2.isAlive()) {
            cancelTimer(0);
            string length1 = "RED: "+to_string(snake1.getLength());
            string length2 = "BLUE: "+to_string(snake2.getLength());
            beginPaint();
            setTextBkColor(EMPTY);
            setTextSize(80);
            setTextColor(BLUE);
            paintText((MAX/2)*PX-160, (MAX/3)*PX, "BLUE WIN");
            setTextColor(RED);
            setTextSize(40);
            paintText((MAX / 3)*PX, (MAX / 3)*PX + 80, length1.c_str());
            setTextColor(BLUE);
            setTextSize(40);
            paintText((MAX / 3)*PX, (MAX / 3)*PX + 120, length2.c_str());
            endPaint();
        }
        else if (!snake2.isAlive() && snake1.isAlive()) {
            cancelTimer(0);
            string length1 = "RED: " + to_string(snake1.getLength());
            string length2 = "BLUE: " + to_string(snake2.getLength());
            beginPaint();
            setTextBkColor(EMPTY);
            setTextSize(80);
            setTextColor(RED);
            paintText((MAX/2)*PX-128, (MAX/3)*PX, "RED WIN");
            setTextColor(RED);
            setTextSize(40);
            paintText((MAX / 3)*PX, (MAX / 3)*PX + 80, length1.c_str());
            setTextColor(BLUE);
            setTextSize(40);
            paintText((MAX / 3)*PX, (MAX / 3)*PX + 120, length2.c_str());
            endPaint();
        }
        else if (!snake1.isAlive() && !snake2.isAlive()) {
            cancelTimer(0);
            string length1 = "RED: " + to_string(snake1.getLength());
            string length2 = "BLUE: " + to_string(snake2.getLength());
            beginPaint();
            setTextBkColor(EMPTY);
            setTextSize(80);
            setTextColor(GREEN);
            paintText((MAX/2)*PX-184, (MAX/3)*PX, "DRAW GAME");
            setTextColor(RED);
            setTextSize(40);
            paintText((MAX / 3)*PX, (MAX / 3)*PX + 80, length1.c_str());
            setTextColor(BLUE);
            setTextSize(40);
            paintText((MAX / 3)*PX, (MAX / 3)*PX + 120, length2.c_str());
            endPaint();
        }
    }
}

int Setup() {
    initWindow("Snake!", 0, 0, MAX*PX, MAX*PX);
    ground.show();
    food.create();
    food.show();
    registerKeyboardEvent(keyboardEvent);
    registerTimerEvent(timerEvent);
    startTimer(0, 120);

    return 0;
}

