#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/*
 *  Author: Feng Liu
 */

class GameOfLife{
public:
    GameOfLife(){
        this -> Gene = 100;
        this ->starting();
    }

    GameOfLife(int Gene ,int period, int l[10][10]){
        this -> Gene = Gene;
        this -> period = period;
        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                life[i][j] = l[i][j];
            }
        }
        this ->starting();
    }

    inline void print(){
        cout << "The " << g << " Generation : " << endl;

        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < 10; ++j){

                if(g == 0){
                    life2[i][j]=life[i][j];
                }
                if(life[i][j] == 0){ // 0 for life
                    cout << setw(3) << "*" ;
                }
                else{
                    cout << setw(3) << ".";
                }

            }
            cout << '\n';
        }

    }

    inline void copy(){

        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                life2[i][j]=life[i][j];
            }
        }
    }
    void starting(){

            this -> print();
            ++g;


        int surDot = 0;
        for(; g <= Gene ;++g) {
            this -> copy();
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {


                    if (life2[i][j] == 0) {//点活着的时候

                        int step = 0;
                            for (int temp1 = i - 1; temp1 <= i + 1; ++temp1) {//计算相邻8个里活着的点
                                for (int temp2 = j - 1; temp2 <= j + 1; ++temp2) {
                                    ++step;
                                    if (temp1 < 0 || temp1 > 9 || temp2 < 0 || temp2 > 9) {
                                        continue;
                                    }
                                    if(temp1 == i && temp2 == j){
                                        continue;
                                    }
                                    if (life2[temp1][temp2] == 0) {
                                        surDot++;


                                    }

                                }
                            }


                        if (surDot == 2 || surDot == 3) { //判断点是否活着
                            life[i][j] = 0;
                        }
                        else{
                            life[i][j] = 1;
                        }
                    } else {// 点死的时候

                            for (int temp1 = i - 1; temp1 <= i + 1; ++temp1) {//计算相邻8个里活着的点
                                for (int temp2 = j - 1; temp2 <= j + 1; ++temp2) {
                                    if (temp1 < 0 || temp1 > 9 || temp2 < 0 || temp2 > 9) {
                                        continue;
                                    }
                                    if(temp1 == i && temp2 == j){
                                        continue;
                                    }
                                    if (life2[temp1][temp2] == 0) {
                                        surDot++;
                                    }
                                }
                            }
                        if (surDot == 3) { //判断点是否活着
                            life[i][j] = 0;
                        }
                    }
                    surDot = 0;
                }
            }
            if(g  % period == 0){
                this -> print();
            }
        }
    }
private:
   int life[10][10]; /* = {1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
                        0 , 0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
                        1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
                        0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
                        0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
                        1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
                        1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
                        1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
                        1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
                        1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,};*/
    int life2[10][10];
    int Gene = 0;
    int g = 0;
    int period = 0;
};
int main(){
    char star = ' ';
    int period = 0;
    int lifetime = 0;
    int l[10][10];
    ifstream f("hw3b.dat");
    f >> lifetime >> period;
        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                f >> star;
                if(star == '*'){
                    l[i][j] = 0;
                }
                else{
                    l[i][j] = 1;
                }
            }
        }
    GameOfLife(lifetime, period, l);
}
