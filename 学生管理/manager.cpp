/*manager.cpp*/

#include"manager.h"

Class A;

void Manager::showMessage(char ch){
    switch (ch) {
    case 0:
        cout << "Over.\n"; break;
    case 1:
        init();
        cout << "Welcome to the student data manager.\n";
        cout << "Please enter:\n";
        cout << "   \"1\" to add a student.\n";
        cout << "   \"2\" to change an existing student data(read file first if there exists).\n";
        cout << "   \"3\" to delete an existing student data(read file first if there exists).\n";
        cout << "   \"4\" to sort the students' data.\n";
        cout << "   \"5\" to show the students' data.\n";
        cout << "   \"6\" to add lots of students.\n";
        cout << "   \"f\" to find a student and show his/her score.\n";
        cout << "   \"s\" to save.\n";
        cout << "   \"r\" to read data from file.\n";
        cout << "   \"e\" to clear the screen.\n";
        cout << "   \"q\" to quit.\n"; break;
    case 2:
        cout << "Enter the student's data(ID name Chinese Math English):\n"; break;
    case 20:
        cout << "Enter the number of students you want to add:  "; break;
    case 21:
        cout << "All over.\n"; break;
    case 3:
        cout << "Enter the student's ID, Chinese, Maths, and English score to change it.\n"; break;
    case 4:
        cout << "Enter the student's ID to delete the student's data.\n"; break;
    case 5:
        cout << "Enter:\n";
        cout << "   \"1\" to sort by average score.\n";
        cout << "   \"2\" to sort by Chinese score.\n";
        cout << "   \"3\" to sort by Maths score.\n";
        cout << "   \"4\" to sort by English score.\n";
        cout << "   \"5\" to sort by id.\n"; break;
    case 50:
        cout << "Enter:\n";
        cout << "   \"h\" to sort from high to low.\n";
        cout << "   \"l\" to sort from low to high.\n"; break;
    case 6:
        cout << "Enter:\n";
        cout << "   \"1\" to show all students.\n";
        cout << "   \"2\" to show students whose score is above average.\n";
        cout << "   \"3\" to show students who failed.\n";
        cout << "   \"4\" to show the stastics of students.\n"; break;
    case 7:
        cout << "Enter the filename(without extension):  ";break;
    case 8:
        cout << "Enter the student's id:  "; break;
    case 9:
        cout << "Input error.\n"; break;
    case 90:
        cout << "Failed!\n"; break;
    default:break;
    }
}

void Manager::init() {
    system("cls");
    system("color 0B");
}

void Manager::addItem() {
    showMessage(2);
    string id, name, chnS, mthS, engS;
    float chn, mth, eng;
    cin >> id >> name >> chnS >> mthS >> engS;
    try {
        chn=stof(chnS);
        mth=stof(mthS);
        eng=stof(engS);
    }
    catch (...) {
        showMessage(9);
        return;
    }
    if (A.addStudent(id, name, chn, mth, eng)) {
        showMessage(0);
    }
    cin.ignore(256, '\n');
}

void Manager::addItem(string& id, string& name, string& chnS, string& mthS, string& engS) {
    float chn, mth, eng;
    try {
        chn = stof(chnS);
        mth = stof(mthS);
        eng = stof(engS);
    }
    catch (...) {
        showMessage(9);
        return;
    }
    if (!A.addStudent(id, name, chn, mth, eng)) {
        throw("Add failed!");
    }
}

void Manager::addItemMultiple() {
    showMessage(20);
    int n;
    cin >> n;
    while (n--) {
        addItem();
    }
    showMessage(21);
}

void Manager::change(){
    showMessage(3);
    string id, chnS, mthS, engS;
    float chn, mth, eng;
    cin >> id >> chnS >> mthS >> engS;
    try {
        chn = stof(chnS);
        mth = stof(mthS);
        eng = stof(engS);
    }
    catch (...) {
        showMessage(9);
        return;
    }
    if (A.changeStu(id, chn, mth, eng)) {
        showMessage(0);
    }
    cin.ignore(256, '\n');
}

void Manager::delItem(){
    showMessage(4);
    string id;
    cin >> id;
    if (A.deleteStu(id)) {
        showMessage(0);
    }
    cin.ignore(256, '\n');
}

void Manager::sortItem1(){
    A.rankingAvg();
}

void Manager::sortItem2() {
    A.rankingChn();
}

void Manager::sortItem3() {
    A.rankingMth();
}

void Manager::sortItem4() {
    A.rankingEng();
}

void Manager::sortItem5() {
    A.rankingId();
}

void Manager::reverse() {
    A.reverse();
}

void Manager::showItem1(){
    A.showAll();
}

void Manager::showItem2(){
    A.showAboveAvg();
}

void Manager::showItem3() {
    A.showFailed();
}

void Manager::showItem4(){
    A.showStastics();
}

void Manager::showFind() {
    showMessage(8);
    string id;
    cin >> id;
    try {
        A.findStu(id).show();
    }
    catch (const char* err) { cout << err << endl; return; }
    showMessage(0);
}

void Manager::save() {
    string f;
    showMessage(7);
    cin >> f;
    f += ".0v0";
    const char* file = f.c_str();
    fstream ftmp(file, ios_base::out | ios_base::trunc);
    ftmp.close();
    A.showFile(file);
    showMessage(0);
}

void Manager::read() {
    string f;
    showMessage(7);
    cin >> f;
    f += ".0v0";
    const char* file = f.c_str();
    fstream fin(file, ios_base::in | ios_base::binary);
    string id, name, chnS, mthS, engS;
    while (1) {
        try {
            fin >> id >> name >> chnS >> mthS >> engS;
            if (fin.eof()) break;
            addItem(id, name, chnS, mthS, engS);
        }
        catch (...) {
            showMessage(90);
            Class B;
            A = B;
            return;
        }
    }
    showMessage(0);
}

void Manager::controlSort() {
    showMessage(5);
    char ch;
    cin >> ch;
    cin.ignore(256, '\n');
    switch (ch) {
    case '1':sortItem1(); break;
    case '2':sortItem2(); break;
    case '3':sortItem3(); break;
    case '4':sortItem4(); break;
    case '5':sortItem5(); break;
    default:showMessage(9); return;
    }
    showMessage(50);
    cin >> ch;
    cin.ignore(256, '\n');
    switch (ch) {
    case 'h':break;
    case 'l':reverse(); break;
    default:showMessage(9); return;
    }
    showMessage(0);
}

void Manager::controlShow() {
    showMessage(6);
    char ch;
    cin >> ch;
    cin.ignore(256, '\n');
    switch (ch) {
    case '1':showItem1(); break;
    case '2':showItem2(); break;
    case '3':showItem3(); break;
    case '4':showItem4(); break;
    default:showMessage(9); break;
    }
    showMessage(0);
}

void Manager::control() {
    char ch;
    cin >> ch;
    if (cin.peek() != '\n') {
        ch = 0;
    }
    cin.ignore(256, '\n');
    switch (ch) {
    case '1':
        addItem(); break;
    case '2':
        change(); break;
    case '3':
        delItem(); break;
    case '4':
        controlSort(); break;
    case '5':
        controlShow(); break;
    case '6':
        addItemMultiple(); break;
    case 'f':
        showFind(); break;
    case 's':
        save(); break;
    case 'r': 
        read(); break;
    case 'q':
        exit(0);
    case 'e':
        showMessage(); break;
    default:
        showMessage(9); break;
    }
}
