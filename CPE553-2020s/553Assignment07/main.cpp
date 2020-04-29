//
// Created by Leo on 4/2/20.
//
#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double A;
    double B;
public: Complex (double a, double b) {
        this -> A = a;
        this -> B = b;
    }

    Complex add(Complex a) const { // if the object is const, then use const
        return Complex(this->A + a.A, this->B + a.B);
    }

    friend Complex operator - (Complex a);
    friend ostream& operator << (ostream& s, const Complex& a);
    friend double abs(Complex v);

    Complex operator + (Complex a) const {
        return Complex (a.A + this -> A, a.B + this -> B);
    }

    static double abs(Complex v) {
        double A = v.A * v.A;
        double B = v.B * v.B;
        return sqrt(A + B);
    }
};

ostream& operator << (ostream& s, const Complex& a){
    return s << '(' << a.A << ',' << a.B << ')';
}

Complex operator - (Complex a) {
    return Complex (-a.A, -a.B);
}

double abs(Complex v) {
    double A = v.A * v.A;
    double B = v.B * v.B;
    return sqrt(A + B);
}



int main() {
    const Complex v1(2.5,5.1);
    const Complex v2(2.2, -1.5);
    cout << v1 + v2 << '\n'; // use a member for operator +
    cout << -v1 << '\n'; // use a friend for unary operator -
    cout << abs(v1) << '\n'; // use a friend function to calculate the absolute value (length) of the complex number
    cout << Complex::abs(v1) << '\n'; //Write a static function to do the same thing as the abs.
};