#include"food.h"
#include"ground.h"
#include"acllib.h"
#include<ctime>
#include<cstdlib>

extern Ground ground;

Food::Food() {
    ;
}

void Food::create(){
    srand((unsigned int)time(NULL));
    x = rand() % MAX;
    y = rand() % MAX;
    //beginPaint();
    //ACL_Color temp = getPixel(x*PX + PX / 2, y*PX + PX / 2);
    while (ground.position[y][x] != NO) {
        x = rand() % MAX;
        y = rand() % MAX;
    }
    ground.position[y][x] = FOOD;
}

void Food::show() {
    beginPaint();
    setBrushColor(GREEN);
    setPenColor(GREEN);
    rectangle(x*PX+PX/8, y*PX+PX/8, (x + 1)*PX-PX/8, (y + 1)*PX-PX/8);
    endPaint();
}

Food food;
