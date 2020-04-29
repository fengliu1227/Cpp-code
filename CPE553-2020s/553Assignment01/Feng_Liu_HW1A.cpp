#include <iostream>
using namespace std;

/*
 * author : Feng Liu
 */

int main() {
    int n;
    cout << "Please enter a positive integer:" << endl;
    cin >> n;
    while (n <= 0) {
        cout << "incorrect input types" << endl;
        cout << "Please enter a positive integer:" << endl;
        cin >> n;
    }

    do {
        if (n % 2 == 1) {
            n = 3 * n + 1;
        } else {
            n /= 2;
        }
        cout << n << ' ';
    }while( n > 1);
    return 0;
}
