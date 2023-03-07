#include "Complex.h"

Complex Complex::make_complex(float a, float b) const {
    Complex c;
    c.x = a;
    c.y = b;
    return c;
}

Complex Complex::operator+(const Complex &c) const {
    return Complex::make_complex(x + c.x, y + c.y);
}

Complex Complex::operator-(const Complex &c) const {
    return Complex::make_complex(x - c.x, y - c.y);
}

Complex Complex::operator*(const Complex &c) const {
    return Complex::make_complex(x * c.x - y * c.y, y * c.x + x * c.y);
}

Complex Complex::operator*(float lambda) const {
    return Complex::make_complex(lambda * x, lambda * y);
}