#include <iostream>

using namespace std;

template<class T>
void print(T n) {
    cout << "Template version: " << n << endl;

}

void print(int value) {
    cout << "Non Template version: " << value << endl;
}

template<class T>
void show() {
    cout << T() << endl;

}

int main() {
    print<string>("Hello");
    print<int>(5);
    // Type Inference
    print("Hi There");
    print(5);
    print<>(6);
    show<double>();
    return 0;
}