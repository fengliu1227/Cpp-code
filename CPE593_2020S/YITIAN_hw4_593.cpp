#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <math.h>
using namespace std;
using namespace std::chrono;
//The following function sets array b = array a
void assign_array(int* b, int* a, int n);
void reverse_assign_array(int* b, int* a, int n);

// The following function initializes the array A by having
// each of the elements from A[0] to A[max] get a random
// number between 1 and max)value
void initialize_rand_array(int* A, int n, int max_value);

// QUICK-SORT
void quickSort(int *array, int l, int r); //run-time measure

template <typename T>
void print_array(T Arr, int n);

void run_time(int* B, int* C, int n1, float* t_sort, float* t_reverse);

float get_queueing_time(int* A,int size, float sort_per_item);

float get_waiting_time(int* A,int index, float sort_per_item);

int main() {
    srand(time(NULL));
    cout << setw(30) << right << "Array A" << setw(44) << right << "Array B"<<setw(44) << right << "Array C"<<endl;
    cout<<setw(8)<<left<<"#n";
    for (int k = 0; k < 3; ++k) {
        cout<<setw(11)<<left<<"Ave"<<setw(11)<<left<<"n/3"<<setw(11)<<left<<"2n/3"<<setw(11)<<left<<"n";
    }
    cout<<endl;
    for (int j = 10; j <=1010 ; j+=100) {
        unsigned int size = j;
        int* a = new int[size];
        int* b = new int[size];
        int* c = new int[size];
        float sort_time,reverse_time;
        initialize_rand_array(a, size, 100);
        assign_array(b, a, size);
//    cout<<"Array A"<<endl;
//    print_array(a,size);
        run_time(b,c,size,&sort_time,&reverse_time);
//    cout<<"Array B"<<endl;
//    print_array(b,size);
//    cout<<"Array C"<<endl;
//    print_array<int*>(c,size);
        float time_arr[12];
        time_arr[0]=get_queueing_time(a,size,0)/size;
        time_arr[4]=get_queueing_time(b,size,sort_time/size)/size;
        time_arr[8]=get_queueing_time(c,size,reverse_time/size)/size;

        for (int i = 1; i <=3 ; i++) {
            time_arr[i]=get_waiting_time(a,i*size/3,0);
            time_arr[i+4]=get_waiting_time(b,i*size/3,sort_time/size);
            time_arr[i+8]=get_waiting_time(c,i*size/3,reverse_time/size);
        }
        cout<<setw(8)<<left<<size;
        print_array<float*>(time_arr,12);
    }
}
void initialize_rand_array(int* array, int n, int max_value) {
    for (int k = 0; k < n; ++k)
        array[k] = 1 + rand() % (max_value);

}
void assign_array(int* b, int* a, int n) {
    for (int i = 0; i < n; ++i)
        b[i] = a[i];
}
void reverse_assign_array(int* b, int* a, int n){
    for (int i = 0; i < n; ++i) {
        b[i]=a[n-1-i];
    }
}
template <typename T>
void print_array(T Arr, int n){
    for (int i = 0; i < n; ++i) {
        cout<<setw(11)<<left<< Arr[i];
    }
    cout<<endl;
}
void quickSort(int *array, int l, int r)
{
    if(l < r)
    {
        int pivot = array[l];
        int low = l, high = r;
        while(low < high)
        {
            while(array[high] >= pivot && low < high)
                high--;
            array[low] = array[high];

            while(array[low] <= pivot && low < high)
                low++;
            array[high] = array[low];
        }
        array[low] = pivot;

        quickSort(array, l, low - 1);
        quickSort(array, low + 1, r);
    }
}
void run_time(int* B, int* C, int n1, float* t_sort, float* t_reverse) {
    auto start_reverse = high_resolution_clock::now();
    auto start = high_resolution_clock::now();
    quickSort(B, 0,n1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    *t_sort = 1.0*duration.count();
    reverse_assign_array(C,B,n1);
    auto stop_reverse = high_resolution_clock::now();
    auto reverse_duration = duration_cast<microseconds>(stop-start);
    *t_reverse = 1.0*reverse_duration.count();
}
float get_queueing_time(int* A,int size, float sort_per_item){
    float total_queue_time=0;
    for (int i = 0; i < size; ++i) {
        float item_queue_time=0;
        for (int j = 0; j <= i; ++j) {
            item_queue_time+=(A[j]+sort_per_item);
        }
        total_queue_time+=item_queue_time;
    }
    return total_queue_time;
}
float get_waiting_time(int* A,int index, float sort_per_item){
    float waiting_time=0;
    for (int i = 0; i < index; ++i) {
        waiting_time+=A[i]+sort_per_item;
    }
    return waiting_time;
}
