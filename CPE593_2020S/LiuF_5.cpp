//Feng Liu
// Assignment # 5 CPE 593 Algorithms and Data Structures
// Spring 2020
// Instructor: Dr. Aftab Ahmad
// I certifiy that no plagiarism or cheating was done
// in doing this assignment.

#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <chrono>
#include <iomanip>
//#include <algorithm>
using namespace std;
using namespace std::chrono;

int* copyArray(int* array, int size);
double* copyArray2(double* array, int size);
int* initialize_ran_array(int size, int min, int max);
int* initializeA(const int* array, int size);
double* initializeB(const int* array, int size);
// Solution 3(a)
int randomized_partition(int* A, int left, int right);
int randomized_selection(int* array, int left, int right, int i);
// Solution 3(b)
void counting_sort(int* arrayA, int* arrayD, int size, int max);
int getMax(int* array, int size);
// Solution 3(c)
void bucket_sort(double* A, int size);

void run_time(int* A, double* B, int* C, int* D, float* t1, float* t2, float* t3, int size);
void output_run_times(float* t1, float* t2, float* t3, int loop);
void print(const int* p, int size);
void print2(const double* p, int size);
int main(){
//    float t1[4];
//    float t2[4];
//    float t3[4];
//    int loop = 0;
//    int* randomArray = initialize_ran_array(1000,1,13);
//    int* A = initializeA(randomArray,1000);
//    double* B = initializeB(A,1000);
//    int* C = copyArray(A,13);
//    int* D = new int[13];
//    run_time(A, B, C, D, &t1[loop], &t2[loop], &t3[loop], 13);
//    print(randomArray,1000);
//    print(A,13);
//    print2(B,13);
//    print(C,13);
//    print(D,13);

    float t1[4];
    float t2[4];
    float t3[4];
    int loop = 0;
    int n = 10;
    while(n <= 1000){
        int* randomArray = initialize_ran_array(n,1,13);
        int* A = initializeA(randomArray,n);
        double* B = initializeB(A,n);
        int* C = copyArray(A,13);
        int* D = new int[13];
        double* E = copyArray2(B,13);
        run_time(A, E, C, D, &t1[loop], &t2[loop], &t3[loop], 13);
        ++loop;

        cout << "when n = " << n << ":\n";
        //randomized select
        cout << "for randomized select : \n";
        bool b1 = true;
        bool b2 = true;
        int l1 = randomized_selection(C, 0, 13 , 14);
        int unl1 = randomized_selection(C, 0, 13 , 1);
        int timel1 = 0;
        int timeunl1 = 0;
        double p1 = D[12] / (double)n;
        double unp1 = D[0] / (double)n;
        for(int i = 0; i < 13; ++i){
            if(A[i] == D[12] && b1){
                l1 = i;
                timel1 = A[i];
                b1 = false;
            }
            else if(A[i] == D[0] && b2){
                unl1 = i;
                timeunl1 = A[i];
                b2 = false;
            }
        }
        cout << "lucky number is:   " << setw(4)<< l1 << "\t\tIt wins "<< timel1 <<" times"  << "\t\tprobability : " << p1 << endl;
        cout << "unlucky number is: " << setw(4)<< unl1 << "\t\tIt wins "<< timeunl1 <<" times" << "\t\tprobability : " << unp1 << "\n";

        //counting sort
        cout << "for counting sort : \n";
        b1 = true;
        b2 = true;
        int l2 = D[12];
        int unl2 = D[0];
        double p2 = l2 / (double)n;
        double unp2 = unl2 / (double)n;
        int timel2 = 0;
        int timeunl2 = 0;
        for(int i = 0; i < 13; ++i){
            if(A[i] == l2 && b1){
                l2 = i;
                timel2 = A[i];
                b1 = false;
            }
            else if (A[i] == unl2 && b2){
                unl2 = i;
                timeunl2 = A[i];
                b2 = false;
            }
        }
        cout << "lucky number is:   " << setw(4)<< l2 << "\t\tIt wins "<< timel2 <<" times"  << "\t\tprobability : " << p2 << endl;
        cout << "unlucky number is: " << setw(4)<< unl2 << "\t\tIt wins "<< timeunl2 <<" times" << "\t\tprobability : " << unp2 << "\n";

        //bucket sort
        cout << "for bucket sort : \n";
        b1 = true;
        b2 = true;
        double p3 = E[12];
        double unp3 = E[0];
        int l3 = 0;
        int unl3 = 0;
        int timel3 = 0;
        int timeunl3 = 0;
        for(int i = 0; i < 13; ++i){
            if(B[i] == p3 && b1){
                l3 = i;
                timel3 = B[i] * n;
                b1 = false;
            }
            else if(B[i] == unp3 && b2){
                unl3 = i;
                timeunl3 = B[i] * n;
                b2 = false;
            }
        }
        cout << "lucky number is:   " << setw(4)<< l3 << "\t\tIt wins "<< timel3 <<" times"  << "\t\tprobability : " << p3 << endl;
        cout << "unlucky number is: " << setw(4)<< unl3 << "\t\tIt wins "<< timeunl3 <<" times" << "\t\tprobability : " << unp3 << "\n\n";

        if(n == 10){
            n = 100;
        }
        else if(n == 100){
            n = 500;
        }
        else if(n == 500){
            n = 1000;
        }
        else{
            n = 10000;
        }
        delete randomArray; delete A; delete B; delete C; delete[] D;
    }
    cout <<  "\n#n\t\trandomized_selection\t\tcounting_sort\t\tbucket_sort\n";
    output_run_times( t1,  t2,  t3, loop);
}

int* copyArray(int* array, int size){
    int* result = new int[size];
    for(int i = 0; i < size; ++i){
        result[i] = array[i];
    }
    return result;
}
double* copyArray2(double* array, int size){
    double* result = new double[size];
    for(int i = 0; i < size; ++i){
        result[i] = array[i];
    }
    return result;
}
int* initialize_ran_array(int size, int min, int max){
    int* result = new int[size];
    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<unsigned> u(min,max);
    for(int i = 0; i < size; ++i){
        result[i] = u(rng);
    }
    return result;

}
int* initializeA(const int* array, int size){
    int* result = new int[13];
    for(int i = 0; i < 13; ++i){
        result[i] = 0;
    }
    for(int i = 0; i < size; ++i){
        int temp = array[i];
        ++result[temp - 1];
    }
    return result;
}
double* initializeB(const int* array, int size){
    double* result = new double[13];
    for(int i = 0; i < 13; ++i){
        result[i] = array[i] / (double)size;
    }
    return result;
}

// Solution 3(a)
int randomized_partition(int* A, int left, int right) {
    int r = rand() % (right - left + 1) + left;
    int Temp = A[r];
    swap(A[r], A[left]);
    while (left < right) {
        while (left < right && A[right] >= Temp) {
            right --;
        }
        swap(A[left], A[right]);
        while (left < right && A[left] <= Temp) {
            left ++;
        }
        swap(A[left], A[right]);
    }
    return left;
}
int randomized_selection(int* array, int left, int right, int i) { // i not the index, order
    if (left == right) {
        return array[left];
    }
    int point = randomized_partition(array, left, right);
    int middle = point - left + 1;
    if  (i == middle) {
        return array[point];
    } else if (i < middle) {
        return randomized_selection(array, left, point - 1, i);
    } else {
        return randomized_selection(array, point + 1, right, i - middle);
    }
}



// Solution 3(b)
void counting_sort(int* arrayA, int* arrayD, int size, int max) {
    int* C = new int[max + 1];
    for(int i = 0; i < max + 1; ++i){
        C[i] = 0;
    }
    for(int i = 0; i < size; ++i){
        ++C[arrayA[i]];
    }
    for(int i = 1; i < max + 1; ++i){
        C[i] = C[i] + C[i-1];
    }
    for(int i = size - 1; i >= 0; --i){
        arrayD[C[arrayA[i]] - 1] = arrayA[i];
        --C[arrayA[i]];
    }
    delete C;
}
int getMax(int* array, int size){
    int max = array[0];
    for(int i = 1; i < size; ++i){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}

// Solution 3(c)
void bucket_sort(double* A, int size){
    int nums = 10;
    vector<double> bucket[nums];
    double min = A[0];
    double max = A[0];
    for(int i = 0; i < size; ++i){
        if(A[i] > max){
            max = A[i];
        }
        if(A[i] < min){
            min = A[i];
        }
    }
    double range = (max - min) / (nums-1);

    for(int i = 0; i < size; ++i){
        int index = (A[i] - min) / range;
        bucket[index].push_back(A[i]);
    }
    for(int i = 0; i < nums; ++i){
        sort(bucket[i].begin(), bucket[i].end());
    }
    int idx = 0;
    for(int i = 0; i < nums; ++i){
        for(int j = 0; j < bucket[i].size(); ++j){
            A[idx++] = bucket[i][j];
        }
    }
}
void bucketSort(double* A, int size){
    int nums = 10;
    vector<double> bucket[nums];
    double min = A[0];
    double max = A[0];
    for(int i = 0; i < size; ++i){
        if(A[i] > max){
            max = A[i];
        }
        if(A[i] < min){
            min = A[i];
        }
    }
    double range = (max - min) / (nums-1);

    for(int i = 0; i < size; ++i){
        int index = (A[i] - min) / range;
        bucket[index].push_back(A[i]);
    }
    for(int i = 0; i < nums; ++i){
        sort(bucket[i].begin(), bucket[i].end());
    }
    int idx = 0;
    for(int i = 0; i < nums; ++i){
        for(int j = 0; j < bucket[i].size(); ++j){
            A[idx++] = bucket[i][j];
        }
    }
}
void run_time(int* A, double* B, int* C, int* D, float* t1, float* t2, float* t3, int size){
    auto start1 = high_resolution_clock::now();
    randomized_selection(C, 0, size , 1);
    randomized_selection(C, 0, size , size + 1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
    *t1 = 1.0 * duration1.count();

    auto start2 = high_resolution_clock::now();
    int max = getMax(A,size);
    counting_sort(A,D,size,max);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
    *t2 = 1.0 * duration2.count();


    auto start3 = high_resolution_clock::now();
    bucket_sort(B,size);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<nanoseconds>(stop3 - start3);
    *t3 = 1.0 * duration3.count();
}
void output_run_times(float* t1, float* t2, float* t3, int loop){
    int n = 10;
    for(int i = 0; i < loop; ++i){
        if(n == 10){
            cout << n << setw(16) << t1[i]<< setw(25) << t2[i] << setw(15) << t3[i]<<endl;
            n = 100;
        }
        else if(n == 100){
            cout << n << setw(15) << t1[i]<< setw(25) << t2[i] << setw(15) << t3[i]<<endl;
            n = 500;
        }
        else if(n == 500){
            cout << n << setw(15) << t1[i]<< setw(25) << t2[i] << setw(15) << t3[i]<<endl;
            n = 1000;
        }
        else{
            cout << n << setw(14) << t1[i]<< setw(25) << t2[i] << setw(15) << t3[i]<<endl;
        }
    }
}
void print(const int* p, int size){
    for(int i = 0; i < size; ++i){
        cout<< p[i] << ' ';
    }
    cout <<endl;
}

void print2(const double* p, int size){
    for(int i = 0; i < size; ++i){
        cout<< p[i] << ' ';
    }
    cout <<endl;
}