#include <iostream>
using namespace std;
/*
 * Author : Feng Liu
 */
 bool isPrime (int num){
     if(num <= 1){
         return false;
     }
     for(int i = 2; i < num; ++i){
         if (num % i == 0) {
             return false;
         }
     }
     return true;
 }

int main(){
    int n;
    cout << "Please type in a positive integer" << endl;
    cin >> n;

    if(isPrime(n)){
        cout << "The number " << n << " is: " << "PRIME" << endl;
    }else{
        cout << "The number " << n << " is: " << "NOT PRIME" << endl;
    }

}
