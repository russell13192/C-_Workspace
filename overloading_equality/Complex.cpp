#include "Complex.h"


ostream &operator<<(ostream &out, const Complex &c) {
    out << "(" << c.getReal() << "," << c.getImg() << ")";
    return out;
}
Complex operator+(const Complex &c1, const Complex &c2) {
    return Complex(c1.getReal() + c2.getReal(), c1.getImg() + c2.getImg());
}

Complex operator+(const Complex &c1, double d) {
    return Complex(c1.getReal() + d, c1.getImg());
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

bool Complex::operator==(const Complex &other) const {
    return (real == other.real) && (img == other.img);
}
Complex::~Complex() {}

double Complex::getReal() const {
    return real;
}

double Complex::getImg() const {
    return img;
}