#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // 1. Member Function Overload for '+'
    // Syntax: ReturnType operatorOPERATOR(const ClassName& rhs)
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // 2. Friend Function Overload for '<<'
    // Needed because the left side of 'std::cout << c' is std::ostream, not Complex
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os; // Return stream reference to allow chaining (e.g. cout << a << b;)
    }
};

int main() {
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);

    // Uses the overloaded '+' operator
    Complex sum = c1 + c2; // Equivalent to: c1.operator+(c2)

    // Uses the overloaded '<<' operator
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << "Sum = " << sum << std::endl;

    return 0;
}