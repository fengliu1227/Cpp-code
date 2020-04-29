#include <string>
#include <iostream>
#include <fstream>
using namespace std;


#include <iostream>
#include <fstream>
using namespace std;

double Max(double a[], int len) { // change the array already ~ careful !
    double temp = 0;
    for (int i = 0; i < len - 1; i ++) { // mind the length !
        if (a[i] > a[i + 1]) {
            a[i + 1] = a[i];
            temp = a[i + 1];
        } else {
            temp = a[i + 1];
        }
    }
    return temp;
}

double Min(double a[], int len) { // change the array already~ careful !
    double temp = 0;
    for (int i = 0; i < len - 1; i ++) { // mind the length !
        if (a[i + 1] > a[i]) {
            a[i + 1] = a[i];
            temp = a[i + 1];
        } else {
            temp = a[i + 1];
        }
    }
    return temp;
}

double Var(double a[], int len, double mean) {
    double sum = 0.0;
    for (int i = 0; i < len; i ++) {
        sum = sum + (a[i] - mean) * (a[i] - mean);
    }
    return sum / len;
}

int main() {
    double a [100];
    double b [100];
    double c [100];
    double sum = 0.0;
    double mean;
    int steps = 0;
    ifstream f("test.dat");
    if (f.is_open()) {
        int i = 0;
        while (!f.eof()) { // 文件不为空
            f >> a[i];
            b[i] = a[i];
            c[i] = a[i];
            sum = sum + a[i];
            steps++;
            cout << "steps = " << steps << "  i = " << i << "  a[i] = "<< a[i] << endl;
            i = i + 1;
        }
        mean =  sum / i;
        cout << "Elements = " << i << endl;
        cout << "Max = " << Max(a, i) << endl;
        cout << "Min = " << Min(c, i) << endl;
        cout << "Mean = " << mean << endl;
        cout << "Var = " << Var(b, i, mean) << endl;
    }
    f.close();
}

