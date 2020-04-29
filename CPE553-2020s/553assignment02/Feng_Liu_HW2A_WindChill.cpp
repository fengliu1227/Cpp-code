#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*
 * Author : Feng Liu
 */

using namespace std;

int main() {
    int T = -45;
    double V = 60;
    double F;
    for (int v = 0; v <= 60; v = v + 5) {
        for (int t = 40; t >= T; t = t - 5) {
            if (v == 0) {
                if (t == 40) {
                    cout << setw(5) << " " << setw(4) << t;
                } else {
                    cout << " " << setw(4) << t;
                }
            } else {
                if (t == 40) {
                    cout << setw(4) << v << " ";
                }
                F = 35.74 + 0.6215 * t - 35.75 * pow(v, 0.16) + 0.4275 * t * pow(v, 0.16);
                cout << setw(4) << round(F) << " ";
            }
        }
        cout << endl;
    }
}

