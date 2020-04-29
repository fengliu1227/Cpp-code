#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    ofstream outfile("hw3b.dat", ofstream::app);
    //ofstream outfile("E:\\myfile.txt", ofstream::app);

    string temp = "100 10";  //写入内容
    string line1 = "..........";
    string line2 = "***.......";
    string line3 = "..........";
    string line4 = "**........";
    string line5 = "**........";
    string line6 = "..........";
    string line7 = "..........";
    string line8 = "..........";
    string line9 = "..........";
    string line10 = "..........";
    if(outfile.is_open())
    {
//        outfile << temp << endl;
        outfile<<temp<<"\n"<<line1<<"\n"<< line2<< "\n"<<line3<<"\n"<<line4<<"\n"<<line5<<"\n"<<line6<<"\n"<<line7<<"\n"<<line8<<"\n"<<line9<<"\n"<<line10<<"\n";
        outfile.close();
        cout << "ok" << endl;
    }
    else
    {
        cout<<"can not open the file \n"<<endl;
        return -1;
    }
    return 0;

}