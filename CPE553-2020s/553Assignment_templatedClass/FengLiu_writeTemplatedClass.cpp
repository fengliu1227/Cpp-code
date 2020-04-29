#include <iostream>
#include <fstream>
#include <unordered_map>
#include <iterator>
using namespace std;
/*
 * Author: Feng Liu
 */
template <typename T>
class spellCheck{
private:
    unordered_map<T,int> dict;
    unordered_map<T,int> test;
    T temp1;
    T temp2;
public:
    spellCheck(char* a , char* b) {
        ifstream f(a);
        if (f.is_open()) {
            int i = 1;
            while (!f.eof()) {
                f >> temp1;
                dict[temp1] = i++;
            }
        }
        ifstream f2(b);
        if(f2.is_open()){
            int i = 1;
            while(!f2.eof()){
                f2 >> temp2;
                test[temp2] = i++;
            }
        }
    }
    void Test(){
        auto iterator = test.begin();
        int a = 0;
        while (iterator != test.end()) {
            if(dict.find(iterator->first) == dict.end()){
                cout << iterator->first << endl;
                ++a;
            }
            ++iterator;
        }
        if(a == 0){
            cout << "thesame"<< endl;
        }
    }


    void print(){
        auto iterator = dict.begin();//find()返回一个指向2的迭代器
        while (iterator != dict.end()) {
            cout << endl << iterator->first << "," << iterator->second << endl;
            iterator++;
        }

    }

};
int main(int argc, char* argv[]) {
    argv[1] = "dict.txt";
    argv[2] = "dict.txt";
   spellCheck<string> spell(argv[1],argv[2]);
   spell.Test();

    return 0;
}
