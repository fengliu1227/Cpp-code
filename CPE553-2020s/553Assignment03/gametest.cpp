//Game of Life
#include <iostream>
#include <fstream>
#include <cmath>
const int size=3;
const int length=size+2;
using namespace std;
class Life{
private:
    int board[length][length]={0};
    int next[length][length]={0};
    int generation,printEvery;
public:
    Life(int gen,int printE){
        //this->board[length][length]={0};
        //this->next[length][length]={0};
        this->generation=gen;
        this->printEvery=printE;
    }
    void calculation(char array[size][size],int generation, int printEvery){
        for(int p=0;p<size;p++){
            for(int q=0;q<size;q++){
                if(array[p][q]=='*'){
                    this->board[p+1][q+1]=1;
                }
            }
        }
    }
    void game(int generation, int printEvery){
        //Life ans(generation,printEvery);

        for(int m=1;m<=size;m++){
            for(int n=1;n<=size;n++){
                this->next[m][n]=this->board[m-1][n-1]+this->board[m-1][n]+this->board[m-1][n+1]+this->board[m][n-1]+this->board[m][n+1]+this->board[m+1][n-1]+this->board[m+1][n]+this->board[m+1][n+1];
                if(this->board[m][n]==0){
                    if(this->next[m][n]==3){
                        this->next[m][n]=1;
                    }
                    else{
                        this->next[m][n]=0;
                    }
                }
                else{
                    if(this->next[m][n]<2)
                        this->next[m][n]=0;
                    else if((this->next[m][n]==2)||(this->next[m][n]==3))
                        this->next[m][n]=1;
                    else
                        this->next[m][n]=0;
                }
            }
        }
        //return ans;
        for(int p=1;p<=size;p++){
            for(int q=1;q<=size;q++){
                this->board[p][q]=this->next[p][q];
            }
        }
    }
    void step(){
        for(int i=1;i<=size;i++){
            for(int j=1;j<=size;j++){
                if(this->next[i][j]==0)
                    cout<<"."<<"\t";
                else
                    cout<<"*"<<"\t";
            }
            cout<<endl;
        }
    }
    void initialization() {
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                if (this->board[i][j] == 0)
                    cout << "." << "\t";
                else
                    cout << "*" << "\t";
            }
            cout << endl;
        }
    }
};
int main() {
    char board[size][size];
    ofstream fout("hw3b.dat");
    cout<<"please input every element in the array board["<<size<<"]["<<size<<"]:"<<endl;
    char ch;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cin>>ch;
            fout<<ch;
        }
    }

    fout.close();
    char g;
    ifstream fin("hw3b.dat");
    while(!fin.eof()){
        for(int m=0;m<size;m++){
            for(int n=0;n<size;n++){
                //fin >> g;
                fin.get(g);
                if (fin.fail())
                    break;
                board[m][n]=g;
            }
        }
    }
    fin.close();

    int gen,printE;
    cout<<"please input a number of generations to compute: ";
    cin>>gen;
    cout<<"please input a number to identify how often to print the field: ";
    cin>>printE;
    Life arrayInt(gen,printE);
    arrayInt.calculation(board,gen,printE);
    cout<<"print the "<<0<<" generation: "<<endl;
    arrayInt.initialization();
    for(int k=1;k<=gen;k++){
        arrayInt.game(gen,printE);
        if(k%printE==0){
            cout<<"print the "<<k<<" generation: "<<endl;
            arrayInt.step();
        }
    }
//    for(int i=0;i<size;i++){
//        for(int j=0;j<size;j++){
//            cout<<board[i][j]<<"\t";
//        }
//    }
    return 0;
