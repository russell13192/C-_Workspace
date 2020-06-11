#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex
{
private:
    /* data */
    double real, img;
public:
    Complex(/* args */);
    Complex(double, double = 0);
    Complex(const Complex &other);
    const Complex &operator==(const Complex &other);
    double getReal() const;
    double getImg() const;
    ~Complex();
    bool operator==(const Complex &other) const;

};

ostream &operator<<(ostream &out, const Complex &c);
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c1, double d);
#endif