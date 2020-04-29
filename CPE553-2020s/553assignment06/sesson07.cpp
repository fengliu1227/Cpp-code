#include <iostream>
#include <vector>
using namespace std;
//
//class Shape{
//public:
//    virtual void print() const = 0;
//}
//};
//
//class Rect : public Shape{
//private:
//    int w, height;
//public:
//    Rect(int w, int h) : w(w),height(h){}
//    void print() const override {
//        cout << w << " " << height ;
//    }
//};
//
//class Circle : public Shape{
//private:
//    int r;
//public:
//    Circle(int r): r(r){}
//    void print() const override {
//        cout << r ;
//    }
//};
//
//int main(){
//
//}
//

class A{
public:
    A(){
        cout << 'A' ;
    }
    ~A(){
        cout << "~A";
    }
};

class B : public A{
private:
    int x;
public:
    B(int x) : x(x){
        cout << 'B' << x;
    }
    ~B(){
        cout << "~B";
    }
};

int main(){
    B b1(3);
    double sum = 0;
    for (int i = 0; i < 100; i++)
        sum += 0.1;
    bool a = sum == 10;
    int n = 8;
    for(int i = 1; i <= n; i *=2){cout << i << ' ';}
}