#include <iostream>
using namespace std;

/*
 *  Author: Feng Liu
 */

int fact(int x){
    int result = 1;
    if(x <= 0){
        return 0;
    }
    for(int i = x; i > 0; --i){
        result *= i;
    }
    return result;
}

int fact2(int x){
    if(x <= 1){
        return 1;
    }
    return x * fact2(x - 1);
}

int fibo(int x){
    int a = 1;
    int b = 1;
    int result = 0;
    for(int i = x - 2; i > 0 ; --i){
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int fibo2(int x){
    if(x <= 2){
        return 1;
    }
    return fibo2(x - 1) + fibo2(x - 2);
}

uint64_t choose(int x, int y){
    uint64_t result = 1;
    for(int i = x; i >= y; --i){
        result *= i;
    }
    for(int j = y; j > 0; --j){
        result /= j;
    }
    return result;
}
int main(){
    cout << "5!: " << fact(5) << ", " << fact2(5) << '\n';
    cout << "15!: " << fact(15) << ", " << fact2(15) << '\n';
    cout << "5th: " << fibo(5) << ", " << fibo2(5) << '\n';
    cout << "13th: " << fibo(13) << ", " << fibo2(13) << '\n';
    cout << "Lottery: " << choose(52,6) << '\n';
}