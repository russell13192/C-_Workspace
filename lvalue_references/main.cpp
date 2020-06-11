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

int main(int argc, char const *argv[])
{
    /* code */
    Test test1 = getTest(); // Test is a LValue, ie name value, and is on the left side of the statement

    cout << test1 << endl;

    vector<Test> vec;
    vec.push_back(Test());

    Test &rTest1 = test1;

    const Test &rTest2 = getTest(); // const lvalue references can bind to rvalues
    Test test2(Test(2));

}
