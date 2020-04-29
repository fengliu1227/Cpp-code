#include <iostream>
#include <regex>
#include <string>
using namespace std;

/*
 * Author : Feng Liu
 */

int main() {
    string word1 = "class\\s+([a-zA-Z_][a-zA-Z0-9_]*)";
    string word2 = "(public|private)\\s+([a-zA-Z_][a-zA-Z0-9_]*)";
    string word3 = "private\\s+([a-zA-Z_][a-zA-Z0-9_]*)";
    string test = "class A {\n"
                  "};\n"
                  "\n"
                  "/* it's ok not to find this one.  That's hard.\n"
                  "If you want to do it, use multiline\n"
                  "*/\n"
                  "class A1\n"
                  "{\n"
                  "};\n"
                  "class    B    \t:  public A {\n"
                  "};\n"
                  "class C :private A {\n"
                  "};\n"
                  "\n"
                  "class\t\tD123: public A {\n"
                  "};\n"
                  "\n"
                  "class E :public A{\n"
                  "};\n"
                  "\n"
                  "class F2_VeryLong :public VeryLongClassName_123{\n"
                  "};";
    string test2 = test;
    regex r1(word1);
    regex r2(word2);

    smatch m;
    smatch m2;
    while (regex_search(test2, m2, r2)) {
        test = m2.prefix();
        while (regex_search(test, m, r1)) {
            int i = 0;
            for (auto x:m) {
                if (i == 1) {
                    i = 0;
                    cout << "The name of Class is: " << x << endl;
                }
                i = 1;
            }
            test = m.suffix();
        }
        int i = 0;
        for (auto x:m2) {
            if(i == 2){
                i = 0;
                cout << "The name of Base is: " << x << endl;
                cout << endl;
            }
            ++i;
        }
        test2 = m2.suffix();
    }
}