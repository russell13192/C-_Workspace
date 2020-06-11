#include <iostream>
using namespace std;

class Parent {
    int dogs{5};
    string text{"hello"};

public:

    Parent(): Parent("hello") {
        // dogs = 5;
        cout << "No parameter parent constructor" << endl;
    }

    Parent(string text) {
        // dogs = 5;
        // this->text = text;
        cout << "string parent constructor" << endl;
    }

};

class Child: public Parent {

public:
    // Child(): Parent("hello") {
    Child() = default;
};

int main(int argc, char const *argv[])
{
    
    Parent parent("Hello");
    Child child;
    return 0;
}
