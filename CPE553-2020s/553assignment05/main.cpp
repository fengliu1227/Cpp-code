#include <iostream>
using namespace std;

//// fill the array x with zeros (using pointer)
//void fill(int x[], int size) {
//    int *p;// NO, use pointer!!! *p++ = 0
//    for (int i = 0; i <= size; i ++) {
//        p = &x[i]; // p = x; x = x + 1;
//        cout << "i =  " << i << "  " << x[i]<<"  end " << endl ;
//    }
//}
//
//// add 1 to every element of x
//void increment(int x[], int size) {
//    int *p = x;
//    for (int i = 0; i <= size; i ++) {
//        ++ *(p + i); //  ++(*p), p = p + 1
//    }
//}
//
//// double every element of x
//void doubleMe(int x[], int size) {
//    int *p = x;
//    // int *p;
//    // p = x;
//    for (int i = 0; i <= size; i ++) {
//        *p = (*p) * 2;
//        p ++;
//    }
//}
//
//// print out every element of x separated by spaces  then newline
//void print(int x[], int size) {
//    int * p;
//    p = x;
//    for (int i = 0; i <= size; i ++) {
//        cout << *p << " ";
//        p ++;
//    }
//    cout << endl;
//}
//
//int main() {
//    int x[10] = {1};
//    const int size = sizeof(x)/sizeof(int);
//    print(x, size);
//    fill(x, size);
//    print(x, size);
//    increment(x, size);
//    print(x, size);
//    doubleMe(x, size);
//    print(x, size);
//}
//class A{
//private : double a;
//public: A(double a): a(a){}
//double geta() const{return a;}
//};
//class B : public A{
//public:   B(double a):A(a){
//    }
//    void print(){
//    cout<< A::geta() << endl;
//}
//};
void A(int& i){
    cout << i <<endl;
    ++i;
}
int main(){
    for(int i = 0; i < 10; ++i){
        A(i);
    }
}