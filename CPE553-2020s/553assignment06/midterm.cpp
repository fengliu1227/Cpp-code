//#include <iostream>
//using namespace std;
//
//class C{
//    int x;
//public:
//    C() : x(0){}
//    virtual void f() = 0;
//};
//
//class D : public C{
//public:
//    void f(){
//        cout << "hello";
//    }
//};
//
//class E : public C{
//public:
//    void f(){
//        cout << "bye";
//    }
//};
//
//int main(){
//    C c1;
//    C c2();
//    C* cp; //Y
//    D d1; //Y
//    E e1; //Y
//    D d2();
//    cp = new C();
//    cp = new D(); //Y
//    cp = &d1; //Y
//    cp = &e1; //Y
//    D* dp = &d1; //Y
//    dp = &e1;
//}

//==================================================

//#include <iostream>
//using namespace std;
//
//class C{
//    int x;
//public:
//    C(int x) : x(x){}
//    virtual void f() = 0;
//};
//
//class D : public C{
//    int y;
//public:
//    D(int x, int y) : C(x),y(y) {}
//};
//
//class F : public D{
//public:
//    F(int x, int y) : D(x,y){}
//    void f(){
//        cout << "F";
//    }
//};
//
//int main(){
//    C c1;
//    C c2(3);
//    C c3(int x);
//    C* cp; //Y
//    D d1;
//    D d2(1,2);
//    d1.f();
//    F f1(1,2); //Y
//    f1.f(); //Y
//}

//==================================================

//#include <iostream>
//using namespace std;
//
//class C{
//private:
//    int x;
//public:
//    C(int x) : x(x){}
//    virtual void f(){}
//};
//
//class D : public C{
//private:
//    int y;
//public:
//    D(int x, int y) : C(x),y(y) {}
//    virtual void g() = 0;
//};
//
//class F : public D{
//private:
//    int y;
//public:
//    F(int x, int y) : D(x,y){}
//    void f(){
//        cout << "F";
//    }
//};
//
//class G : public F{
//private:
//public:
//    G(int x, int y) : F(x,y){}
//    void g() {cout << "G"; }
//};
//
//int main(){
//    C c1(1,2);
//    C c2(2);//Y
//    D d1(1,2);
//    F f1(1,2);
//    G = g1(1,2);//Y
//    G g2;
//    G* gp = &g1;//Y
//    C* cp = &g1;//Y
//    g1.g();//Y
//    cp -> g();//Y
//}

//==================================================

//#include <iostream>
//using namespace std;
//
//class DynamicArray{
//private:
//    int* p;
//    int size;
//public:
//    DynamicArray() : p(nullptr), size(0) {}
//    void add(int v){
//        int* temp = p;
//        p = new int [size + 1];
//        for(int i = 0; i < size; ++i){
//            p[i] = temp[i];
//        }
//        p[size++] = v; //*(p + size) = v; ++size;
//        delete[] temp;
//    }
//
//    ~DynamicArray(){
//        delete[] p;
//    }
//
//    friend ostream& operator << (ostream& s, const DynamicArray& d){
//        for(int i = 0; i < d.size; ++i){
//            s << d.p[i] << ' ';
//            return s;
//        }
//    }
//
//    DynamicArray (const DynamicArray& orig) : size(orig.size){
//        p = new int[size];
//        for(int i = 0; i < size; ++i){
//            p[i] = orig.p[i];
//        }
//    }
//
//    DynamicArray& operator = (DynamicArray copy){
//        size = copy.size;
//        swap(p, copy.p );
//        return *this;
//    }
//};
//
////goal: build array amd print it out
//int main(){
//    DynamicArray a;
//    for(int i = 0; i < 100; ++i){
//        a.add(i);
//    }
//    cout << a << "\n";
//}

//==================================================

//#include <iostream>
//using namespace std;
//
//class Shape{
//public:
//    virtual double area() const = 0;
//    virtual double perimeter() const = 0;
//}
//};
//
//class Line : public Shape{ // abstract
//public:
//    double area() const {return 0;}
//};
//
//class Circle : public Shape{
//
//public:
//    double area() const {return PI * r * r; }
//    double perimeter() const {return 2 * PI * r;}
//};

//==================================================

//#include <iostream>
//using namespace std;
//
//class Airplane{
//public:
//    void fly(){
//        cout << "flap, flap";
//    }
//};
//
//class passengerAirplane : public Airplane {
//public:
//    void serveCoffee();
//    void serveCoronaVirus();
//};
//
//class FighterPlane : public Airplane {
//private:
//    int bullets;
//public:
//    FighterPlane() : bullets(100) {}
//    void shoot(){
//        cout << bullets << "Remaining\n";
//        bullets--;
//    }
//};
//
//int main(){
//    Airplane a1;  // Y
//    a1.fly();     // Y
//    FighterPlane f1;  // Y
//    f1.fly();         // Y
//    f1.shoot();       // Y
//    a1.shoot();
//    FighterPlane* fp = &a1;
//    FighterPlane* fp2 = (FighterPlane*)&a1;
//    fp2 -> shoot();
//
//}

//==================================================

//#include <iostream>
//using namespace std;
//
//int main(){
//    int a = 2;
//    const int b = 3;
//    const int c; // bad idea 报错　
//    int* p = &a;
//    *p = 99; // a = 99. *p is an alias for a
//    p = &b;// illeagal -> const int* q = &b; promise to only read b;
//
//    int* q = &b; // illeagal
//
//    p = (int*) &b; // that works
//    *p = 99; // every shoot misses
//
//    cout << b << '\n';  //output: b still equal to 3.
//
//    const double PI = 3.14159265358979;
//    double* dp = (double*)&PI;
//    *dp = 4;//It doesn't work
//}

//==================================================

#include <cstdlib>
using namespace std;

int main(){   //pointer bigger than integer
    int* p = new int[10000000];
    delete[] p;

    int* q = new int;
    delete q;

    int* r = (int*)malloc(1024);
    free(r);
}