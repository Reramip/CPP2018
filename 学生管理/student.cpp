/*student.cpp*/

#include"student.h"

Class::Student::Student(string& i, string& n, float cn, float ma, float en) :id(i), name(n), Chinese(cn), Maths(ma), English(en) {
    sum = Chinese + Maths + English;
}

Class::Student::Student(const Student& s):id(s.id),name(s.name),Chinese(s.Chinese),Maths(s.Maths),English(s.English) {
    sum = Chinese + Maths + English;
}

void Class::Student::show()const {
    cout << id << ' ' << name << ' ' << fixed << setprecision(2) << "Chinese:" << Chinese << ' ' << "Maths:" << Maths << ' ' << "English:" << English << ' ' << "Average:" <<sum/COURSENUM <<endl;
}

void Class::Student::showFile(const char* file) const{
    fstream fout(file, ios_base::out | ios_base::binary | ios_base::app);
    fout << ' ' << id << ' ' << name << ' ' << fixed << setprecision(2) << Chinese << ' ' << Maths << ' ' << English << endl;
}

bool Class::Student::pass() const{
    return (Chinese>=60&&Maths>=60&&English>=60);
}

bool Class::Student::operator==(const Student & s) const{
    return (id == s.id);
}

class Class::Student::avgSort {
public:
    bool operator()(const Student& s1, const Student& s2)const {
        return (s1.sum > s2.sum);
    }
};
class Class::Student::chnSort {
public:
    bool operator()(const Student& s1, const Student& s2)const {
        return (s1.Chinese > s2.Chinese);
    }
};
class Class::Student::mthSort {
public:
    bool operator()(const Student& s1, const Student& s2)const {
        return (s1.Maths > s2.Maths);
    }
};
class Class::Student::engSort {
public:
    bool operator()(const Student& s1, const Student& s2)const {
        return (s1.English > s2.English);
    }
};
class Class::Student::idSort {
public:
    bool operator()(const Student& s1, const Student& s2)const {
        return (s1.id > s2.id);
    }
};

Class::Class(const Class& c) {
    cId = c.cId;
    cName = c.cName;
    sum = c.sum;
    stu = c.stu;
    numFail = num60 = num70 = num85 = num95 = 0;
}

bool Class::addStudent(string& i, string& n, float cn, float ma, float en) {
    Student s(i, n, cn, ma, en);
    if (cn > 100 || ma > 100 || en > 100) {
        cout << "Wrong score.\n";
        return false;
    }
    list<Student>::iterator it;
    for (it = stu.begin(); it != stu.end(); it++) {
        if (it->getId() == i) {
            cout << "Inserting an existing student.\n";
            return false;
        }
    }
    stu.push_back(s);
    sum += s.getSum();
    return true;
}

void Class::stastics(){
    num95 = num85 = num70 = num60 = numFail = 0;
    list<Student>::iterator it;
    for (it = stu.begin(); it != stu.end(); it++) {
        if (it->getSum() >= 285) num95++;
        else if (it->getSum() >= 255) num85++;
        else if (it->getSum() >= 210)num70++;
        else if (it->getSum() >= 180)num60++;
        else numFail++;
    }
}

void Class::showStastics() {
    stastics();
    cout << "Average :" << fixed << setprecision(2) << sum / getNum() /COURSENUM << endl;
    cout << "[0,60)  :" << numFail << endl;
    cout << "[60,70) :" << num60 << endl;
    cout << "[70,85) :" << num70 << endl;
    cout << "[85,95) :" << num85 << endl;
    cout << "[95,100]:" << num95 << endl;
}

void Class::showFailed(){
    list<Student>::iterator it;
    for (it = stu.begin(); it != stu.end(); it++) {
        if (!it->pass())it->show();
    }
}

int Class::getNum()const {
    return stu.size();
}

void Class::showAll() {
    list<Student>::iterator it;
    for (it = stu.begin(); it != stu.end(); it++) {
        it->show();
    }
}

void Class::showAboveAvg() {
    list<Student>::iterator it;
    for (it = stu.begin(); it != stu.end(); it++) {
        if (it->getSum() > (sum / (float)getNum())) {
            it->show();
        }
    }
}

Class::Student& Class::findStu(string& id) {
    list<Student>::iterator it;
    for (it = stu.begin(); it != stu.end(); ++it) {
        if (it->getId() == id) {
            return *it;
        }
    }
    throw "Not found.\n";
}

bool Class::changeStu(string& id,float Chinese,float Maths,float English){
    try {
        if (Chinese > 100 || Maths > 100 || English > 100) {
            cout << "Wrong score.\n";
            return false;
        }
        Student& s = findStu(id);
        float sum = Chinese + Maths + English;
        this->sum -= s.getSum();
        s.changeScore(Chinese, Maths, English);
        this->sum += sum;
        return true;
    }
    catch (const char* err) {
        cout << err;
        return false;
    }
}

bool Class::deleteStu(string& id){
    try {
        Student& s = findStu(id);
        stu.remove(s);
        return true;
    }
    catch (const char* err) {
        cout << err;
        return false;
    }
}

void Class::rankingAvg() {
    stu.sort(Student::avgSort());
}

void Class::rankingChn(){
    stu.sort(Student::chnSort());
}

void Class::rankingMth(){
    stu.sort(Student::mthSort());
}

void Class::rankingEng(){
    stu.sort(Student::engSort());
}

void Class::rankingId() {
    stu.sort(Student::idSort());
}

void Class::reverse() {
    stu.reverse();
}

void Class::showFile(const char* file){
    list<Student>::iterator it;
    for (it = stu.begin(); it != stu.end(); it++) {
        it->showFile(file);
    }
}
