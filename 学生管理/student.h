/*student.h*/

#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>//控制输出格式
#include<string>
#include<list>

using namespace std;
const int PASS = 180;
const int COURSENUM = 3;

class Class {
    class Student;
    string cId;
    string cName;
    float sum;
    list<Student> stu;
    int numFail, num60, num70, num85, num95;
    int getNum()const;
    void stastics();
public:
    Class() :sum(0) {}
    Class(string& i, string& n) :cId(i), cName(n), sum(0) {}
    Class(const Class& c);
    ~Class() {}
    Student& findStu(string& id);
    void rankingAvg();
    void rankingChn();
    void rankingMth();
    void rankingEng();
    void rankingId();
    void showAll();
    void showAboveAvg();
    bool changeStu(string& id,float Chinese,float Maths,float English);
    bool deleteStu(string& id);
    bool addStudent(string& i, string& n, float cn, float ma, float en);
    void showStastics();
    void showFailed();
    void reverse();
    void showFile(const char* file);
    friend class Manager;
};

class Class::Student {
    string id;
    string name;
    float Chinese;
    float Maths;
    float English;
    float sum;
public:
    Student() {}
    Student(string& i, string& n, float cn, float ma, float en);
    Student(const Student& s);
    ~Student() {}
    float getSum()const { return sum; }
    string getId()const { return id; }
    void changeScore(float cn, float ma, float en) { Chinese = cn; Maths = ma; English = en; sum = cn + ma + en; }
    void show()const;
    void showFile(const char* file)const;
    bool pass()const;
    bool operator==(const Student& s)const;
    class avgSort;
    class chnSort;
    class mthSort;
    class engSort;
    class idSort;
};
