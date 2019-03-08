/*manager.h*/

#pragma once
#include"student.h"

class Manager {
    void init();
    void addItem();
    void addItem(string& id, string& name, string& chnS, string& mthS, string& engS);
    void addItemMultiple();
    void change();
    void delItem();
    void sortItem1();
    void sortItem2();
    void sortItem3();
    void sortItem4();
    void sortItem5();
    void reverse();
    void showItem1();
    void showItem2();
    void showItem3();
    void showItem4();
    void showFind();
    void save();
    void read();
    void controlSort();
    void controlShow();
public:
    Manager(){}
    ~Manager(){}
    void showMessage(char ch = 1);
    void control();
};
