#include"ClockDigital.h"
#include"acllib.h"
#include<Windows.h>
#include<string>



ClockDigital::ClockDigital() :status(0) {
    ;
}

int ClockDigital::getStatus() {
    return status;
}

void ClockDigital::changeStatus(int st) {
    status = st;
}

void ClockDigital::draw(int x, int y, int length, int height) {
    ;
}

void ClockDigital::show(int x, int y, int length, int height) {
    using namespace std;
    int ox = (x + length) / 2;
    int oy = (y + height) / 2;
    int i = 0;
    int st = getStatus();
    beginPaint();
    clearDevice();
    //Rectangular
    setPenWidth(2);
    setPenColor(RED);
    setBrushColor(WHITE);
    roundrect(x, y, length, height, length / 10, height / 10);
    //Number
    setTextColor(BLACK);
    setTextBkColor(WHITE);
    setTextSize(72);
    setTextFont("Calibri");
    if (st == 1) {
        int h, m, s;
        bool ap=0;
        timeGet(h, m, s);
        if (h >= 12) {
            ap = 1;
            h %= 12;
        }
        else ap = 0;
        string hstr, mstr, sstr;
        hstr = to_string(h);
        mstr = to_string(m);
        sstr = to_string(s);
        if (h < 10) hstr = '0' + hstr;
        if (m < 10) mstr = '0' + mstr;
        if (s < 10) sstr = '0' + sstr;
        string time = hstr + ':' + mstr + ':' + sstr;
        paintText(ox / 3, oy / 2, time.c_str());
        if (ap == 0)paintText(ox / 2, oy, "AM");
        else if(ap==1)paintText(ox,oy,"PM");
    }
    else{
        int h, m, s;
        timeGet(h, m, s);
        string hstr, mstr, sstr;
        hstr = to_string(h);
        mstr = to_string(m);
        sstr = to_string(s);
        if (h < 10) hstr = '0' + hstr;
        if (m < 10) mstr = '0' + mstr;
        if (s < 10) sstr = '0' + sstr;
        string time = hstr + ':' + mstr + ':' + sstr;
        paintText(ox / 3, oy / 2, time.c_str());
    }
    setTextColor(BLACK);
    setTextBkColor(WHITE);
    setTextSize(16);
    setTextFont("Calibri");
    paintText(0, 0, "按1圆形,按2方形,按3数字(24h),按4数字(12h),按Q退出");
    endPaint();
}
