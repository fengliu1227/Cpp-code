#include <iostream>
using namespace std;

/*
 * author : Feng Liu
 */

int main() {
    float sum1F = 0.0f;
    float sum2F = 0.0f;

    double sum1D = 0.0;
    double sum2D = 0.0;

    for( float i = 1.0 ; i <= 100.0; ++i){
        sum1F += 1 / i;
    }
    for( float i = 100.0 ; i >= 1.0; --i){
        sum2F += 1 / i;
    }

    for( double i = 1.0 ; i <= 100.0; ++i){
        sum1D += 1 / i;
    }
    for( double i = 100.0 ; i >= 1.0; --i) {
        sum2D += 1 / i;
    }

    cout << "sum1F = " << sum1F << " , " << "sum2F = " << sum2F << "\n"
         << "sum1D = " << sum1D << " , " << "sum2D = " << sum2D << "\n"
         << "sum1F - sum2F = " << sum1F - sum2F << "\n"
         << "sum1D - sum2D = " << sum1D - sum2D << "\n" << endl;

    return 0;
}
