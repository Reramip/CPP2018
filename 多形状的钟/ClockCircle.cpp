#include"ClockCircle.h"
#include"acllib.h"
#include<time.h>
#include<math.h>

#define RAD(x) ((x) / 360.0 * 2 * 3.1415926535)

void ClockCircle::changeStatus(int st){
    ;
}

void ClockCircle::draw(int x, int y, int length, int height) {
    int r = length;
    int ox = (x + r) / 2;
    int oy = (y + r) / 2;
    int hl = (r / 4 - r / 7);
    int ml = r / 5;
    int sl = r / 3;
    int i = 0;
    beginPaint();
    //Label!
    setPenWidth(3);
    setPenColor(BLACK);
    int len1 = r / 2 - r / 8;
    int len2 = len1 + 10;
    for (i = 0; i < 12; i++) {
        moveTo(ox + len1*sin(RAD(180 - i * 30)), oy + len1*cos(RAD(180 - i * 30)));
        lineTo(ox + len2*sin(RAD(180 - i * 30)), oy + len2*cos(RAD(180 - i * 30)));
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
    setTextColor(BLACK);
    setTextBkColor(WHITE);
    setTextSize(16);
    setTextFont("Calibri");
    paintText(0, 0, "按1圆形,按2方形,按3数字(24h),按4数字(12h),按Q退出");
    endPaint();
}

void ClockCircle::show(int x, int y, int length, int height) {
    int r = length*1.2;
    int ox = (x + r) / 2;
    int oy = (y + r) / 2;
    beginPaint();
    clearDevice();
    //Circle!
    setPenWidth(2);
    setPenColor(RED);
    setBrushColor(WHITE);
    ellipse(x, y, r, r);
    endPaint();
    draw(x, y, r);
}

