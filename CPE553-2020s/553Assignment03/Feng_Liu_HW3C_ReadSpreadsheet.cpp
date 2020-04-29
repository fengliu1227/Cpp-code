#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/*
 *  Author: Feng Liu
 */
int main(){
    int row = 0;
    int col = 0;
    int a[50][50];
    int temp;
    ifstream f("3C.dat");
    if (f.is_open()) {
        f >> row >> col;
        int a[row][col];
        int sumOfRow[row];
        int sumOfCol[col];
        int sum = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col ;j++)
               f >> a[i][j];
        }

for(int i = 0; i < row; ++i){
            sumOfRow[i] = 0;
        }

        for(int j = 0; j < col; ++j){
            sumOfCol[j] = 0;
        }
        cout << sumOfRow[0] << ' '<< sumOfRow[1]<<endl;
            for(int i = 0; i < row; ++i){ //row = 3
                for(int j = 0; j < col; ++j){ // col = 4
                    a[i][j] = 0;
                    f >> a[i][j];
                    sumOfRow[i] += a[i][j];
                    sumOfCol[j] += a[i][j];
                    if(i == 2){
                        if(j >= 2){
                            cout << a[i][j] << setw(6);
                        }
                        else {
                            cout << a[i][j] << setw(4);
                        }
                    }
                    else{
                        cout << a[i][j]<< setw(5);
                    }

                }
                cout <<"   rowsum ="<< setw(4)<< sumOfRow[i]<< endl;
            }
            cout << "---------------------------------" << endl;
            int totalSum = 0;
            for(int j = 0; j < col; ++j) {
                cout << sumOfCol[j] << setw(5);
                totalSum += sumOfCol[j];
            }
            cout << "   totalsum =" << setw(4) << totalSum;
     }
    f.close();

}
