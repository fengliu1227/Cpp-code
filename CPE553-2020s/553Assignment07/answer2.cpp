//
// Created by Leo on 4/2/20.
//
#include <iostream>
#include <cmath>
using namespace std;
double answer (int n, double x){
    double result = 0.0;
    for(int i = 1; i <= n; ++i){
        if(i % 2 == 0){
            result -= 1.0 / i * pow((x - 1),n);
        }
        else {
            result += 1.0 / i * pow((x - 1), n);
        }
    }
    return result;
}
int main(){
    int n = 2;
    double x = 2;
    cout << answer(3,2);
}