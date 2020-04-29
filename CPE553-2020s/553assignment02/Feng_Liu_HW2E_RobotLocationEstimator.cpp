#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

/*
 * Author : Feng Liu
 */

using namespace std;
double PI = 3.14159265358979323846;

void Polar2Rect(double r, double theta, double &x, double &y) {
    theta = (theta / 360) * 2 * PI ;
    x = x + r * sin(theta);
    y = y + r * cos(theta);
}

int main() {
    double r = 0;
    double theta = 0;
    double x = 0;
    double y = 0;
    double a = 0;
    double b = 0;
    ifstream f("HW2E.txt");
    if (f.is_open()) {
        while (!f.eof()) {
            f >> theta >> r;
            if (theta != - 1 && r != - 1) {
                Polar2Rect(r, theta, x, y); // no "&"
                a = round(x * 10000) / 10000;
                b = round(y * 10000) / 10000;
                cout << "New robot position (X,Y): " << "(" << a << ", " << b << ")" << endl;
            } else {
                cout << "Robot has reached final destination." << endl;
                break;
            }
        }
    }
    f.close();
}