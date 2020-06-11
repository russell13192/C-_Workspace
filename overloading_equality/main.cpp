#include <iostream>

#include "Complex.h"
using namespace std;

int main() {
    Complex c1(3, 2);
    Complex c2(3, 2);

    if (c2 == c1) {
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }
    return 0;
}