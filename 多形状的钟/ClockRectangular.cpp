#include"ClockRectangular.h"
#include"acllib.h"
#include<time.h>
#include<math.h>

#define RAD(x) ((x) / 360.0 * 2 * 3.1415926535)

void GetXY(int x0, int y0, int r, int angle, int &x, int &y) {
    if ((angle >= 0 && angle<45) || (angle >= 315 && angle<360)) {
        x = x0 + r*tan(RAD(angle));
        y = y0 - r;
    }
    else if (angle >= 45 && angle<135) {
        x = x0 + r;
        y = y0 + r / tan(RAD(angle));
    }
    else if (angle >= 135 && angle<225) {
        x = x0 + r*tan(RAD(angle));
        y = y0 + r;
    }
    else if (angle >= 225 && angle<315) {
        x = x0 - r;
        y = y0 + r / tan(RAD(angle));
    }
}


void ClockRectangular::changeStatus(int st){
    ;
}

void ClockRectangular::draw(int x, int y, int length, int height) {
    int ox = x + length / 2;//150;
    int oy = y + height / 2;//150;
    int min = length<height ? length : height;
    int hl = min / 4 - min / 7;//46;
    int ml = min / 3 - min / 6;//74;
    int sl = min / 2 - min / 5;//120;
    int i;
    beginPaint();
    setPenWidth(2);
    setPenColor(RED);
    setBrushColor(WHITE);
    rectangle(x, y, x + length, y + height);
    // label
    setPenWidth(1);
    setPenColor(BLACK);
    int r1 = length * 6 / 16, r2 = length * 7 / 16;
    for (i = 0; i<12; ++i)
    {
        GetXY(ox, oy, r1, i * 30, x, y);
        moveTo(x, y);
        GetXY(ox, oy, r2, i * 30, x, y);
        lineTo(x, y);
    }
    //Hour!
    setPenWidth(8);
    setPenColor(BLACK);
    moveTo(ox, oy);
    lineTo(ox + hl*sin(RAD(180 - getH() * 30 - getM()*0.5)), oy + hl*cos(RAD(180 - getH() * 30 - getM()*0.5)));
    //Minute!
    setPenWidth(4);
    setPenColor(BLUE);
    moveTo(ox, oy);
    lineTo(ox + ml*sin(RAD(180 - getM() * 6 - getS()*0.1)), oy + ml*cos(RAD(180 - getM() * 6 - getS()*0.1)));
    //Second!
    setPenWidth(2);
    setPenColor(RED);
    moveTo(ox, oy);
    lineTo(ox + sl*sin(RAD(180 - getS() * 6)), oy + sl*cos(RAD(180 - getS() * 6)));
    endPaint();
}

void ClockRectangular::show(int x, int y, int length, int height) {
    int r = length;
    int ox = (x + r) / 2;
    int oy = (y + r) / 2;
    beginPaint();
    clearDevice();
    //Circle!
    setPenWidth(2);
    setPenColor(RED);
    setBrushColor(WHITE);
    ellipse(x, y, r, r); 
    setTextColor(BLACK);
    setTextBkColor(WHITE);
    setTextSize(16);
    setTextFont("Calibri");
    paintText(0, 0, "按1圆形,按2方形,按3数字(24h),按4数字(12h),按Q退出");
    endPaint();
    draw(x, y, r);
}
