#include <iostream>
using namespace std;
/*
 * Author : Feng Liu
 */

bool isPrime(int num){
    if(num <= 1){
        return false;
    }
    for(int i = 2; i < num;++i){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int countPrimes(int min, int max){
    int result = 0;
    for(int i = min; i <= max; ++i){
        if(isPrime(i)){
            result++;
        }
    }
    return result;
}
 int main(){
    int a;
    int b;
    int amount;
    cout << "Please enter a positive integer as the minimum:" << endl;
    cin >> a;
    cout << "Please enter a positive integer as the maximum:" << endl;
    cin >> b;
    amount = countPrimes(a,b);
    cout << "There are " << amount << " primes in the range [" << a << "," << b << "]" << endl;
 }