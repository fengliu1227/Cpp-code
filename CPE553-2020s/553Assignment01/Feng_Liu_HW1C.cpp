#include <iostream>
using namespace std;

/*
 *  author : Feng Liu
 */
int main(){
    int n = 100;
    int sumOfGauss = 0;
    int sumOfLoop = 0;

    sumOfGauss = (n * (n + 1)) / 2;

    for(int i = 1; i <= n; ++i){
        sumOfLoop += i;
    }

    if(sumOfGauss == sumOfLoop){
        cout << "Gauss Result:" << sumOfGauss << "\n" << "Loop Result:" << sumOfLoop << "\n" << "Both results are the same." << endl;
    }

    else {
        cout << "Gauss Result:" << sumOfGauss << "\n" << "Loop Result:" << sumOfLoop << "\n" << "Two results are not same." << endl;
    }

    return 0;
}