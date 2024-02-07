//Answer of 1

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

class Complex {
private:
    double real;
    double imaginary;

public:
       Complex() : real(0), imaginary(0) {}

       Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

      Complex(const std::string& complexStr) {
        std::stringstream ss(complexStr);
        char delim;
        ss >> real >> delim >> imaginary;
    }

       double getReal() const {
        return real;
    }

      double getImaginary() const {
        return imaginary;
    }

      double magnitude() const {
        return sqrt(real * real + imaginary * imaginary);
    }

   
    double angle() const {
        return atan2(imaginary, real);
    }

       Complex conjugate() const {
        return Complex(real, -imaginary);
    }

       Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const {
        double newReal = real * other.real - imaginary * other.imaginary;
        double newImaginary = real * other.imaginary + imaginary * other.real;
        return Complex(newReal, newImaginary);
    }

    Complex operator/(const Complex& other) const {
        double divisor = other.real * other.real + other.imaginary * other.imaginary;
        double newReal = (real * other.real + imaginary * other.imaginary) / divisor;
        double newImaginary = (imaginary * other.real - real * other.imaginary) / divisor;
        return Complex(newReal, newImaginary);
    }

    void print() const {
        std::cout << "(" << real << ", " << imaginary << ")\n";
    }
};

int main() {
    Complex a(3, 4);
    Complex b("5, 6");

    Complex sum = a + b;
    Complex difference = a - b;
    Complex product = a * b;
    Complex quotient = a / b;

    std::cout << "Sum: ";
    sum.print();
    std::cout << "Difference: ";
    difference.print();
    std::cout << "Product: ";
    product.print();
    std::cout << "Quotient: ";
    quotient.print();

    return 0;
}

