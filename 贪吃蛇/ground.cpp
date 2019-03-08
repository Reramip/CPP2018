#include "ground.h"
#include "acllib.h"

Ground::Ground() {
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            position[i][j] = NO;
            direction[i][j] = NO;
        }
    }
}

void Ground::show(){
    int i, j;
    beginPaint();
    clearDevice();
    for (i = 0; i < MAX; ++i) {
        for (j = 0; j < MAX; ++j) {
            if (position[i][j] == SNAKE1) {
                setBrushColor(RED);
                setPenColor(RED);
                ellipse(j*PX, i*PX, (j + 1)*PX, (i + 1)*PX);
            }
            else if (position[i][j] == SNAKE2) {
                setBrushColor(BLUE);
                setPenColor(BLUE);
                ellipse(j*PX, i*PX, (j + 1)*PX, (i + 1)*PX);
            }
            else if (position[i][j] == FOOD) {
                setBrushColor(GREEN);
                setPenColor(GREEN);
                rectangle(j*PX+PX/8, i*PX+PX/8, (j + 1)*PX-PX/8, (i + 1)*PX-PX/8);
            }
        }
    }
    endPaint();
}

Ground ground;
