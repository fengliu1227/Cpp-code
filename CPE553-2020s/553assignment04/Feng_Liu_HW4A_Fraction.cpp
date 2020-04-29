#include <iostream>
#include <sstream>
using namespace std;

/*
 * Author: Feng Liu
 */

class Fraction{
public:
    Fraction(){
        this -> num = 1;
        this -> den = 1;
    }

    Fraction(int num) : num(num), den(1){}

    Fraction(int num, int den){
        this -> num = num;
        this -> den = den;
    }

    Fraction add(Fraction a) const{
        return Fraction(this -> num * a.den + a.num * this -> den, this -> den * a.den);
    }

    Fraction sub(Fraction a){
        return Fraction(a.num * this -> den - this -> num * a.den, this -> den * a.den);
    }

    friend string print(const Fraction& a);
    friend int gcd(Fraction a, Fraction b);

private:
    int num,den;
};

int gcd(Fraction a, Fraction b) {//Why cannot write this fuction in class Fraction
    int d1 = a.den;
    int d2 = b.den;
    int result = 1;
    if (d1 > d2){
        for(int i = d2; i <= d1; ++i){
            if(i % d2 == 0 && d1 % i == 0){
                result = i;
            }
            else{
                continue;
            }
        }
        return result;
    }
    else if(d1 < d2){
        for(int i = d1; i <= d2; ++i){
            if (i % d1 == 0 && d2 % i == 0){
                result = i;
            }
            else{
                continue;
            }
        }
        return result;
    }
    else{
         result = d2;
         return result;
    }
}

string print(const Fraction& a){ //Why cannot write this fuction in class Fraction
    ostringstream result;
    result << "(" << a.num << "/" << a.den << ")";
    return result.str();
//    return "(" + "/" + ")"; // why cannot use this method which is useful in JAVA
}

int main() {
    // Main() Section 1
    Fraction f1;		// 1/1, Assume num and den are 1
    const Fraction f2(1,2); // 1/2
    Fraction f3(5);         // 5/1, Given number is num, assume den is 1
    Fraction f4(1,3);       // 1/3

    // Main() Section 2
    Fraction f5 = f2.add(f4); // 1/2 + 1/3 = 5/6
    Fraction f6 = f4.sub(f3); // 5/1 - 1/3 = 14/3

    // Main() Section 3
    int r = gcd(f2, f5); // greatest common denominator, 6

    // Main() Section 4
    cout << "f1: " << print(f1) << '\n'; // print format: (1/1)
    cout << "f2: " << print(f2) << '\n';
    cout << "f3: " << print(f3) << '\n';
    cout << "f4: " << print(f4) << '\n';
    cout << "f5: " << print(f5) << '\n';
    cout << "f6: " << print(f6) << '\n';
    cout << "r: " << r << '\n';

}
