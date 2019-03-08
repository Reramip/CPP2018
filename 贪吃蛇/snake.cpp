#include"snake.h"
#include"utility.h"
#include"ground.h"
#include"food.h"
#include"acllib.h"

extern Ground ground;
extern Food food;

Snake::Snake(int num) :number(num), alive(true), length(5), direction(UP){
    if (number == SNAKE1) {
        //beginPaint();
        //setBrushColor(RED);
        //setPenColor(RED);
        for (int i = 0; i < length; ++i) {
            ground.position[MAX - 2 - i][10] = SNAKE1;
            //ellipse( 10 * PX,(MAX - 2 - i)*PX, 11 * PX, (MAX - 1 - i)*PX);
            ground.direction[MAX - 2 - i][10] = UP;
        }
        //endPaint();
        xHead = 10;
        yHead = MAX - 6;
        xTail = 10;
        yTail = MAX - 2;
    }
    else if (number == SNAKE2) {
        //beginPaint();
        //setBrushColor(BLUE);
        //setPenColor(BLUE);
        for (int i = 0; i < length; ++i) {
            ground.position[MAX - 2 - i][MAX - 10] = SNAKE2;
            //ellipse( (MAX - 10) * PX, (MAX - 2 - i)*PX, (MAX - 9) * PX, (MAX - 1 - i)*PX);
            ground.direction[MAX - 2 - i][MAX - 10] = UP;
        }
        //endPaint();
        xHead = MAX-10;
        yHead = MAX - 6;
        xTail = MAX-10;
        yTail = MAX - 2;
    }
}

bool Snake::isAlive(){
    return alive;
}

void Snake::collision(){
    if (xHead<0 || xHead>MAX - 1 || yHead<0 || yHead>MAX - 1) {
        alive = false;
    }
    else if (ground.position[yHead][xHead] == SNAKE1) {
        alive = false;
    }
    else if (ground.position[yHead][xHead] == SNAKE2) {
        alive = false;
    }
    /*int x = xHead;
    int y = yHead;
    if (x<0 || x>MAX - 1 || y<0 || y>MAX - 1) {
        alive = false;
    }
    else {
        ACL_Color temp = WHITE;
        beginPaint();
        temp = getPixel(x*PX + PX / 2, y*PX + PX / 2);
        endPaint();
        if (temp != WHITE && temp != GREEN) {
            alive = false;
        }
    }*/
}

void Snake::move(){
    switch (direction) {
    case UP:
        yHead -= 1;
        break;
    case DOWN:
        yHead += 1;
        break;
    case LEFT:
        xHead -= 1;
        break;
    case RIGHT:
        xHead += 1;
        break;
    default:break;
    }
    collision();
    bool flag = false;
    if (ground.position[yHead][xHead] == FOOD) {
    //if(xHead==food.getX()&&yHead==food.getY()) {
        eat();
        flag = true;
    }
    ground.direction[yHead][xHead] = direction;
    ground.position[yHead][xHead] = number;
    switch (number) {
    case SNAKE1:
        beginPaint();
        setBrushColor(RED);
        setPenColor(RED);
        ellipse(xHead*PX, yHead*PX, (xHead + 1)*PX, (yHead + 1)*PX);
        endPaint();
        break;
    case SNAKE2:
        beginPaint();
        setBrushColor(BLUE);
        setPenColor(BLUE);
        ellipse(xHead*PX, yHead*PX, (xHead + 1)*PX, (yHead + 1)*PX);
        endPaint();
        break;
    default:break;
    }
    if (!isAlive()) {
        return;
    }
    if (!flag) {
        beginPaint();
        setBrushColor(WHITE);
        setPenColor(WHITE);
        rectangle(xTail*PX, yTail*PX, (xTail + 1)*PX, (yTail + 1)*PX);
        endPaint();
        switch (ground.direction[yTail][xTail]) {
        case UP:
            ground.direction[yTail][xTail] = NO;
            ground.position[yTail][xTail] = NO;
            yTail -= 1;
            break;
        case DOWN:
            ground.direction[yTail][xTail] = NO;
            ground.position[yTail][xTail] = NO;
            yTail += 1;
            break;
        case LEFT:
            ground.direction[yTail][xTail] = NO;
            ground.position[yTail][xTail] = NO;
            xTail -= 1;
            break;
        case RIGHT:
            ground.direction[yTail][xTail] = NO;
            ground.position[yTail][xTail] = NO;
            xTail += 1;
            break;
        default:break;
        }
    }
}

void Snake::changeDirection(int direction){
    if (!((direction==UP&&this->direction==DOWN)||(direction==DOWN&&this->direction==UP)||
        (direction==LEFT&&this->direction==RIGHT)||(direction==RIGHT&&this->direction==LEFT))) {
        this->direction = direction;
        ground.direction[yHead][xHead] = direction;
    }
}

void Snake::eat(){
    length++;
    food.create();
    food.show();
}

int Snake::getLength() {
    return length;
}
