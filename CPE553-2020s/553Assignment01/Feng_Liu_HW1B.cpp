#include <iostream>
#include <math.h>
using namespace std;

/*
 * author : Feng Liu
 */

int main(){
    const double P = 3.1415926;
    double R = 1.0;
    double A;

    for(int n = 3; n <= 1000000; ++n){
        A = (n - 2) * P / n;
        R = R / sin(A / 2);


        if(n == 10){
            cout << "n = 10" << "\t\t\t" << "Radius = " << R << endl;
        }

        if(n == 100){
            cout << "n = 100" << "\t\t\t" << "Radius = " << R << endl;
        }

        if(n == 1000){
            cout << "n = 1000" << "\t\t" << "Radius = " << R << endl;
        }

        if(n == 10000){
            cout << "n = 10000" << "\t\t" << "Radius = " << R << endl;
        }

        if(n == 100000){
            cout << "n = 100000" << "\t\t" << "Radius = " << R << endl;
        }

        if(n == 1000000){
            cout << "n = 1000000" << "\t\t" << "Radius = " << R << endl;
        }
    }

    return 0;
}