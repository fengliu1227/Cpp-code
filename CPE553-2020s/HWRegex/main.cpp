#include <iostream>
#include <regex>

using namespace std;

const char s[] = "class A {\n"
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
                 "class F2_VeryLong : public VeryLongClassName_123{\n"
                 "};";

int main() {
    regex r( "class\\s+([a-zA-Z_][a-zA-Z0-9_]*)");

    cmatch m;

    const char* p = s;
    if (regex_search (p,m,r)) {
        cout << m[0] << '\n';
        cout << m[1] << '\n';
        cout << m[2] << '\n';
        cout << m.position() << "\t" << m.length() << "\n";
        cout << m.position(1) << "\t" << m.length(1) << '\n';
    }
}
