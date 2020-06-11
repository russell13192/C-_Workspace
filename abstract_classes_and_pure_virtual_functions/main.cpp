#include <iostream>
using namespace std;

// Animal is an abstract class because it has only virtual functions
// Abstract classes can't be instantiated
class Animal {
public:
    virtual void run() = 0;
    virtual void speak() = 0; // Pure Virtual Function
};

class Dog: public Animal {
public:
    virtual void speak() {
        cout << "Woof!" << endl;
    }
};

class Labrador: public Dog {
public:
    Labrador() {
        cout << "New Labrador" << endl;
    }
    virtual void run() {
        cout << "Labrador running" << endl;
    }
};

void test(Animal &a) {
    a.run();
}


// If you implement all of the virtual functions in animal then you can instantiate animal
int main() {
    //Animal animals[]; -> Can't do this because when you try to create an array it tries to run the constructos
                            // of the objects
    //Dog dog;
    //dog.speak();
    Labrador lab;
    lab.run();
    lab.speak();
    
    
    Animal *animals[5];
    animals[0] = &lab; // Animals index 0 is equal to the memory address of lab
    animals[0]->speak(); // Syntax for calling methods on references
    //Labrador labs[5];
    test(lab);
    return 0;
}