//
// Created by Leo on 4/8/20.
//

template<class A>
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
    GrowArray(const GrowArray& orig) : capacity(orig.capacity), data(orig.data) {
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
        a.data = nullptr; // we'll talk more about this line below
    }

    GrowArray& operator=(GrowArray&& a)
    {
        // Self-assignment detection
        if (&a == this)
            return *this;

        // Release any resource we're holding
        delete [] data;

        // Transfer ownership of a.m_ptr to m_ptr
        data = a.data;
        a.m_ptr = nullptr; // we'll talk more about this line below

        return *this;
    }

    void add(const T& v) {
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

//    void add(const T& v) {
//        data.push_back(v);
//        ++capacity;
//    }
//    void removeEnd(){
//        data.pop_back();
//        --capacity;
//    }
//    friend ostream& operator <<(ostream& s, const GrowArray& array) {
//        for (int i = 0; i < array.capacity; i++) {
//            s << array.data[i] << ' ';
//        }
//        return s;
//    }
};


template <typename T>
class List {
private:
    int capacity;
    T* data;
public:
    List() : capacity(0), data(nullptr){}
    ~List(){
        delete [] data;
    }
    List(const List& orig) : capacity(orig.capacity), data(new T[orig.capacity]){
        memcpy(data, orig.data, capacity * sizeof(T));
    }
    List& operator = (const List& copy){
        capacity = copy.capacity;
        swap(data,copy.data);
        return *this;
    }
    void add(const T& a){
        T* old = data;
        data = new T[capacity + 1];
        for(int i = 0; i < capacity; ++i){
            data[i] = old[i];
        }
        data[capacity++] = a;
        delete [] old;
    }

    void removeEnd(){
        T* old = data;
        data = new T[--capacity];
        for(int i = 0; i < capacity; ++i){
            data[i] = old[i];
        }
        delete [] old;
    }

    friend ostream& operator << (ostream& s, const List list){
        for(int i = 0; i < list.capacity; ++i){
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

    List<string> b;
    b.add("hello");
    string s[] = { "test", "this", "now" };

    for (int i = 0; i < sizeof(s)/sizeof(string); i++)
        b.add(s[i]);
    cout << b << '\n';

}