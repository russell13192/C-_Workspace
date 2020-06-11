#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    /* code */
    int one = 1;
    int two = 2;
    int three = 3;
    // Capture one and two by value
    [one, two](){ cout << one <<", " << two << endl; }();
    // Capture all local variables by value
    [=](){ cout << one <<", " << two << endl; }();
    // Capture all local variables by value, but capture three by reference
    [=, &three](){ three = 7; cout << one <<", " << two << ", " << three << endl; }();
    // Capture all local variables by reference
    [&](){ three = 9, two = 4, one = 3; cout << one <<", " << two << ", " << three << endl; }();
    // Capture all local variables by reference, but capture two and three by value
    [&, two, three](){ one = 5; cout << one <<", " << two << ", " << three << endl; }();

    return 0;
}
