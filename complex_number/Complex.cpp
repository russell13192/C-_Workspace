#include "Complex.h"


ostream &operator<<(ostream &out, const Complex &c) {
    out << "(" << c.getReal() << "," << c.getImg() << ")";
    return out;
}

Complex::Complex(): real(0), img(0) {}

Complex::Complex(double real, double img) : real(real), img(img) {}

Complex::Complex(const Complex &other) {
    cout << "Copy" << endl;
    real = other.real;
    img = other.img;
}

const Complex &Complex::operator==(const Complex &other) {
    real = other.real;
    img = other.img;

    return *this;
}
Complex::~Complex() {}

double Complex::getReal() const {
    return real;
}

double Complex::getImg() const {
    return img;
}