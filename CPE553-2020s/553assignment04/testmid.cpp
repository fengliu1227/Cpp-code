#include <iostream>
using namespace std;

//class A {
//public:
//    A(){cout << 'x';}
//};
//
//class B : public A{
//private:
//    int x;
//public:
//    B(int x) : A(), x(x){cout << x << 't';}
//};
//
//class C{
//private:
//    A a;
//    B b;
//public:
//    C(int x) : b(x){cout << 'r';}
//};
//
//void f(){
//    A a1;
//    B b1(2);
//    C c1(3);
//}
//
//int main(){
//    cout << "bienvenue!\n";
//    f();
//    cout << "au revoire!\n";
//}

int main(){
    int a = 3;
    int b = 4;
    int* r = &b;
    ++*r;
    cout << b << endl;
    cout << *r << endl;
    int* p = &a;
    int x[6] = {9,2,7};
    p = (int*)&x + 2;
    cout << *p << endl;

    int q = *p++;

    int* s = &q;

    *s = 22;


    *p++ = 11;
    *++p;
    *--p += 3;
    int j = --*p;
    cout << j << '\n';
    for(int i = 0; i < b; ++i){
        cout << x[i] << ',';
    }
    cout << '\n';

}