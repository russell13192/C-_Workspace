#include <iostream>
using namespace std;

void test(void (*pFunc)()) {
    pFunc();
}

int main() {


    // Should always use auto when working with Lambda expressions. Type of 
    // variable varies from lambda function to Lambda expression. 
    auto func = [](){ cout << "Hello" << endl;};

    func();
    test(func);

    test([](){ cout << "Hello again" << endl; });

    return 0;
}