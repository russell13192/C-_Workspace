#ifndef RING_H_
#define RING_H_

#include <iostream>
using namespace std;

template <class T>
class Ring
{
  public:
    class iterator;
};


template<class T>
class Ring<T>::iterator
{
  public:
    void print() {
        cout << "Hello from iterator: " << T() << endl;
    }
};



#endif // ! RING_H_#define RING_H_
