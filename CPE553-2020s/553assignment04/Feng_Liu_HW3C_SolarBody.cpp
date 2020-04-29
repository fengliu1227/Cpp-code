#include <iostream>
using namespace std;

/*
 * Author: Feng Liu
 */

class Body{
public:
    Body(string name, double mass, double x, double y, double z, double radius){
        this -> name = name;
        this -> mass = mass;
        this -> x = x;
        this -> y = y;
        this -> z = z;
        this -> radius = radius;
    }

    friend ostream& operator << (ostream& s, const Body& a);

private:
    string name;
    double mass, x, y, z, radius;
};

ostream& operator << (ostream& s, const Body& a){
    return s << a.name << ' ' << a.mass << ' ' << a.x << ' ' << a.y << ' ' << a.z << ' ' << a.radius << endl;
}
int main() {
    //         name      mass(kg) x y z  radius (m)
    Body earth("earth", 5.972e24, 0,0,0, 6.371e6);
    Body moon("moon",   7.34767309e22, 384.400e6,0,0,  1.737e6);
    cout << earth << '\n';
    cout << moon << '\n';
}
