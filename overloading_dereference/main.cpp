#include <iostream>
#include "Complex.h"

using namespace std;

int main() {

    Complex c1(2, 4);

    cout << *c1 + *Complex(4, 3) << endl;
    return 0;
}