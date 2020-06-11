#include <iostream>

using namespace std;


class Test {
private:
    int one{1};
    int two{2};
public:
    void run() {
        int three{3};
        int four{4};
        auto pLambda = [this, three, four](){
            one = 11;
            cout << one << endl; // Because of the this keyword above we can now calculate instance variables.
            cout << two << endl; // Because of the this keyword above we can now calculate instance variables.
            cout << three << endl;
            cout << four << endl;
        };
        pLambda();
    }
};

int main(int argc, char const *argv[])
{
    Test test;
    test.run();
    
    return 0;
}
