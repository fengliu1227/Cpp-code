#include <iostream>
using namespace std;

int x;
void f(int x) {
    static int y = 1;
    x++;
    cout << x << ::x << y++;
    ::x--;
}
class A {
private:
    int *m;
public:
    A() {
        m = new int[1024];
    }
};

int main() {
    int x = 2;
    f(x);
    cout << x;
    f(x);
}