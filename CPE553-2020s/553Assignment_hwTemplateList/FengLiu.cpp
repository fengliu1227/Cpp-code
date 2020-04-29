#include <iostream>
#include <vector>
using namespace std;
/*
 * Author: Feng Liu
 */

template<typename T>
class GrowArray {
private:
    int capacity;
    int index = 0;
//    vector<T> data;
    T* data;
public:
    GrowArray(T a) : capacity(0){}
    ~GrowArray() {
//        data.clear();
        delete [] data;
    }
    GrowArray(const GrowArray& orig) : capacity(orig.capacity), data(new T[orig.capacity]) {
        memcpy(data, orig.data, capacity*sizeof(T));
    }


    GrowArray& operator =(GrowArray copy){
        capacity = copy.capacity;
        swap(data, copy.data);
        return *this;
    }
    GrowArray(GrowArray&& a)
            : data(a.data)
    {
        a.data = nullptr;
    }

    GrowArray& operator=(GrowArray&& a)
    {
        if (&a == this)
            return *this;

        delete [] data;

        data = a.data;
        a.m_ptr = nullptr; // we'll talk more about this line below

        return *this;
    }

    GrowArray add(const T& v) {
        GrowArray old2= move(this);
        old2 = move(this);
        T* old = data;
        data = new T[capacity+1]; // your object must contain constructor T()
        for (int i = 0; i < capacity; i++)
            data[i] = old[i];
        data[capacity++] = v;
        delete [] old;
    }
    void removeEnd(){
        T* old = data;
        data = new T[--capacity]; // your object must contain constructor T()
        for (int i = 0; i < capacity; i++)
            data[i] = old[i];
        delete [] old;
    }

    friend ostream& operator <<(ostream& s, const GrowArray& list) {
        for (int i = 0; i < list.capacity; i++) {
            s << list.data[i] << ' ';
        }
        return s;
    }

};


int main() {
    GrowArray<int> a(100);
    for (int i = 0; i < 1000000; i++)
        a.add(i);
    for (int i = 0; i < 999990; i++)
        a.removeEnd();
    // should have 0 1 2 3 4 5 6 7 8 9
    cout << a << '\n';

//    List<string> b;
//    b.add("hello");
//    string s[] = { "test", "this", "now" };
//
//    for (int i = 0; i < sizeof(s)/sizeof(string); i++)
//        b.add(s[i]);
//    cout << b << '\n';

}

