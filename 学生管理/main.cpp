/*main.cpp*/

#include"manager.h"

int main() {
    Manager m;
    m.showMessage();
    while (1) {
        m.control();
    }

    return 0;
}
