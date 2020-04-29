//
// Created by Leo on 4/2/20.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Shape{
public:
    virtual double volume() const = 0;
};
class Sphere : public Shape{
private:
    double r;
public:
    Sphere(double r):r(r){}
    friend ostream& operator << (ostream& s){
        return s << "Sphere: the radius = " <<  r;
    }
    double volume() const override{
        double PI = 3.14159265358979323846;
        double result = 4.0 / 3.0 * PI * pow(r,3.0);
        return result;
    }
};

class Cube : public Shape{
private:
    double l;
public:
    Cube(double l) : l(l){}
    ostream& operator << (ostream& s){
        return s << "Cube: the side length = " <<  l;
    }
    double volume()const override{
        double result = pow(l,3.0);
        return result;
    }
};

int main() {
    vector<Shape *> list;
    list.push_back(new Sphere(3.0));
    list.push_back(new Cube(5.0));

    cout << *list[0] << '\n'; // print out the circle
    cout << list[0]->volume() << '\n';
}