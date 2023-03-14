#include "Complex.h"

Complex::Complex(float a, float b) {
    x = a;
    y = b;
}

Complex Complex::operator+(const Complex &c) const {
    return Complex(x + c.x, y + c.y);
}

Complex Complex::operator-(const Complex &c) const {
    return Complex(x - c.x, y - c.y);
}

Complex Complex::operator*(const Complex &c) const {
    return Complex(x * c.x - y * c.y, y * c.x + x * c.y);
}

Complex Complex::operator*(float lambda) const {
    return Complex(lambda * x, lambda * y);
}