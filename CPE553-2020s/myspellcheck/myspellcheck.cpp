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
    unordered_map<T,int> test1;
    unordered_map<T,int> test2;
    T temp;
    T temp1;
    T temp2;
public:
    spellCheck(char* a , char* b) {
        ifstream dictreader("dict.txt");
        if (dictreader.is_open()) {
            int i = 1;
            while (!dictreader.eof()) {
                dictreader >> temp;
                dict[temp] = i++;
            }
        }
        ifstream f(a);
        if (f.is_open()) {
            int i = 1;
            while (!f.eof()) {
                f >> temp1;
                test1[temp1] = i++;
            }
        }
        ifstream f2(b);
        if(f2.is_open()){
            int i = 1;
            while(!f2.eof()){
                f2 >> temp2;
                test2[temp2] = i++;
            }
        }
    }
    void Test(){
        cout << "for book1:" << endl;
        auto it1 = test1.begin();
        while (it1 != test1.end()) {
            if(dict.find(it1->first) != dict.end()){
                cout << it1->first << endl;
            }
            ++it1;
        }
        cout << "==========================" << endl;
        cout << "for book2:" << endl;
        auto it2 = test2.begin();
        while (it2 != test2.end()) {
            if(dict.find(it2->first) != dict.end()){
                cout << it2->first << endl;
            }
            ++it2;
        }
    }


    void print(){
        auto iterator = test1.begin();
        while (iterator != test1.end()) {
            cout << endl << iterator->first << "," << iterator->second << endl;
            iterator++;
        }

    }

};
int main(int argc, char* argv[]) {
//    argv[1] = "book1.txt";
//    argv[2] = "book2.txt";
    spellCheck<string> spell(argv[1],argv[2]);
    spell.Test();

    return 0;
}
