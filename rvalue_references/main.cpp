#include <iostream>
#include <memory.h>
#include<vector>
using namespace std;

class Test {

private:
    static const int SIZE=100;
    int *_pBuffer;

public:
    Test() {
        cout << "constructor" << endl;
        _pBuffer = new int[SIZE]{}; // <- {} sets all the bytes in the buffer to zero
        // memset(_pBuffer, 0, sizeof(int)*size);

    }
    Test(int i) {
        cout << "parameterized constructor" << endl;
        _pBuffer = new int[SIZE]{};

        for(int i = 0; i < SIZE; i++) {
            /* code */
            _pBuffer[i] = 7 * i;
        }
        
    }
    Test(const Test &other) {
        cout << "copy constructor" << endl;
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
    }
    Test &operator=(const Test &other) {
        cout << "assignment" << endl;
        _pBuffer = new int[SIZE]{};
        memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
        return *this;
    }

    ~Test() {
        cout << "destructor" << endl;
        delete [] _pBuffer;
    }
    friend ostream &operator <<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test) {
    out << "Hello from test me";
    return out;
}

Test getTest() {
    return Test();
}

void check(const Test &value) {
    cout << "lValue function!" << endl;
}

void check(Test &&value) {
    cout <<"rValue function!" << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    Test test1 = getTest(); // Test is a LValue, ie name value, and is on the left side of the statement

    cout << test1 << endl;
    vector<Test> vec;
    vec.push_back(Test());

    Test &ltest1 = test1; // lvalue reference

    Test &&rtest1 = getTest(); // rvalue reference -> can only bind to rvalue references
    check(test1);
    check(getTest());
    check(Test());
}
