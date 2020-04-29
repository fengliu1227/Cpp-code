#include <iostream>
using namespace std;

/*
 * Author: Feng Liu
 */

class Complex{
public:
    Complex(double a, double b){
        this -> a = a;
        this -> b = b;
    }

    void print() const{
        cout << "(" << this -> a << "," << this -> b << ")" << endl;
    }

    Complex add(Complex a) const{
        return Complex(this -> a + a.a, this -> b + a.b);
    }

//    friend Complex operator + (Complex a , Complex b);
    friend Complex operator + (const Complex&  a, const Complex& b) {
        return Complex (a.a + b.a, a.b + b.b);
    }
    Complex operator - () const{
      return Complex (-this -> a, -this -> b);
   }

private:
    double a;
    double b;
};

//Complex operator + (Complex a, Complex b){
//    return Complex (a.a + b.a, a.b + b.b);
//}
long long factorical(int a){
    long long result = 1;
    for(int i = a; i > 0; --i){
        result *= i;
    }
    return result;
}
int main() {
    const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
    const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
    const Complex c = a + b;   // overload operator + using a friend function
    c.print(); // should print the following to cout: (1.5,2.0)
    // (member syntax).  Should look the same as method add where the name add
    // is replaced by operator +
    const Complex d = a.add(b); // this should be the same as the above except the name
    d.print();
    Complex e = -d; // implement unary - using a member operator. Since it has one parameter which is this should have ZERO PARAMETERS!!!
    e.print();
}
