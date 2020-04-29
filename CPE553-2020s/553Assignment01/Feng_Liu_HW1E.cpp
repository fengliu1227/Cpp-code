#include <iostream>
using namespace std;
/*
 * author : Feng Liu
 */

int main() {
    double n = 0;
    int fact = 1;
    cout << "Please type in a positive integer from the keyboard" << endl;
    cin >> n;

    if(n <= 0) {
        while (n <= 0) {
            cout << "It's negative" << "\n" << "Please enter a positive number:" << endl;
            cin >> n;
        }
    }
    if(n != (int)n){
        while (n != (int)n) {
            cout << "It's a decimal" << "\n" << "Please enter a positive number:" << endl;
            cin >> n;
        }
    }

    for(int i = n; i >= 1; --i){
        fact *= i;
    }

    cout << fact << endl;

    return 0;
}

