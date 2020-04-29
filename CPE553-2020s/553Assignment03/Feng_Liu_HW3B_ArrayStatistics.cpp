#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

/*
 *  Author: Feng Liu
 */

double getMax (double a[], int len){
    double max = a[0];
    for(int i = 1; i < len; ++i){
        if(a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

double getMin (double a[], int len){
    double min = a[0];
    for(int i = 1; i < len; ++i){
        if(a[i] < min){
            min = a[i];
        }
    }
    return min;
}

double getVar (double a[], int len, double mean){
    double sum = 0.0;
    double result = 0.0;
    for(int i = 0; i < len; ++i){
        sum += pow((a[i] - mean), 2.0);
        result = sum / len;
    }
    return result;
}

int main() {
    int numsOfEle = 0.0;
    double temp = 0.0;
    double temp2 = 0.0;
    double sum = 0.0;
    double mean = 0.0;
    ifstream f("3B.dat");

    if(f.is_open()){
        while(!f.eof()){
            f >> temp;
//            if(temp == temp2){
//                break;
//            }
//            temp2 = temp;
            ++numsOfEle;
            cout << numsOfEle << "\t";

        }

    }
    f.close();
    double data[numsOfEle];
    int i = 0;
    ifstream f2("3B.dat");
    if(f2.is_open()){
        while(!f2.eof()){
            if(i >= numsOfEle){
                break;
            }
            f2 >> data[i];
            sum += data[i];
            ++i;
        }
        mean = sum / numsOfEle;
        cout << "Elemets = " << numsOfEle << endl;
        cout << "Max = " << getMax(data, numsOfEle) << endl;
        cout << "Min = " << getMin(data, numsOfEle) << endl;
        cout << "Mean = " << mean << endl;
        cout << "Var = " << getVar(data,numsOfEle,mean) << endl;
    }
    f2.close();
    return 0;
}
