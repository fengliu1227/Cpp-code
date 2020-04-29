#include <iostream>
#include <cmath>
using namespace std;

/*
 * Author : Feng Liu
 */
int main() {
    cout << "Please type in a positive integer" << endl;
    uint32_t n;
    float sum1 = 0;
    float sum2 = 0;
    float sum3 = 0;
    float result1;
    float result2;
    float result3;
    cin >> n;

//    while(n <= 0 || n % 1 != 0){
//        cout << "Error, Make sure it's a positive integer" << endl;
//        cin >> n;
//    }

    //sum1 and result1
    for(int i = 1; i <= n; ++i){
        sum1 += 1 / pow(i,2);
    }

    result1 = sqrt(6*sum1);
    cout << "result1 = "<< result1 << endl;

    n = 9999999;

    //sum2 and result2
    for(int i = 1; i <= n; ++i){
        sum2 += 1 / pow(i,2);
    }

    result2 = sqrt(6*sum2);
    cout << "result2 = "<< result2 << endl;

    //sum3 and result3
    for(int i = n; i > 0; --i){
        sum3 += 1 / pow(i,2);
    }

    result3 = sqrt(6*sum3);
    cout << "result3 = " << result3 << endl;
    return 0;
}
