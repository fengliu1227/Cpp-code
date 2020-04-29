//Feng Liu
// Assignment # 1 CPE 593 Algorithms and Data Structures
// Spring 2020
// Instructor: Dr. Aftab Ahmad
// I certifiy that no plagiarism or cheating was done
// in doing this assignment.

#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <map>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

class ArrayOfJob{
private:
    int* A;
    int* B;
    int* C;
    double timeA = 0;
    double timeB = 0;
    double timeC = 0;
    double sortingTime = 0;
    double reverseTime = 0;
public:
    int* getA(){
        return A;
    }

    int* getB(){
        return B;
    }

    int* getC(){
        return C;
    }


    void swap(int* B, int a, int b){
        int temp = B[a];
        B[a] = B[b];
        B[b] = temp;
    }

    void quickSort(int left, int right){
        if(left >= right){
            return;
        }
        int pivot = B[left + (right - left) / 2] ;
        int i = left;
        int j = right;
        while(i <= j) {
            while (i <= j && B[i] < pivot) {
                ++i;
            }
            while (i <= j && B[j] > pivot) {
                --j;
            }

            if (i <= j) {
                swap(B, i++, j--);
            }
        }

        quickSort(left , j);
        quickSort(i, right);
    }

    void initializeA(int n){
        A = new int[n];
        mt19937 rng;
        rng.seed(random_device()());
        uniform_int_distribution<unsigned> u(1,100);
        for(int i = 0; i < n; ++i){
            this -> A[i] = u(rng);
        }
    }

    void initializeB(int* A, int size){
        B = new int[size];
        for(int i = 0; i < size; ++i){
            B[i] = A[i];
        }

        auto start = high_resolution_clock::now();
        quickSort(0, size - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop-start);
        sortingTime = 1.0 * duration.count();

    }

    void initializeC(int size){
        C = new int[size];
        auto start = high_resolution_clock::now();
        for(int i = 0; i < size; ++i){
            C[i] = B[size - i - 1];
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop-start);
        reverseTime = 1.0 * duration.count() + sortingTime;
    }

    double calculateTime(int type, int size, int n) {
        if (type == 1) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j <= i; ++j) {
                    timeA += A[j];
                }
            }
            timeA /= n;
            return timeA;
        } else if (type == 2) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j <= i; ++j) {
                    timeB += B[j];
                }
            }
            timeB /= n;
            timeB += sortingTime / n;
            return timeB;
        } else {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j <= i; ++j) {
                    timeC += C[j];
                }
            }
            timeC /= n;
            timeC += reverseTime / n;
            return timeC;
        }
    }

    double getWaitingTime(int type, int n, int size){
        double waitingTime = 0.0;
        if (type == 1) {
            for (int i = 0; i < n; ++i) {
                waitingTime += A[i];
            }
            return waitingTime;
        } else if (type == 2) {
            for (int i = 0; i < n; ++i) {
                waitingTime += B[i];
            }
            waitingTime += sortingTime / size * n;
            return waitingTime;
        } else {
            for (int i = 0; i < n; ++i) {
                waitingTime += C[i];
            }
            waitingTime += reverseTime / size * n;
            return waitingTime;
        }
    }
    ~ArrayOfJob(){
        delete [] A;
        delete [] B;
        delete [] C;

    }
};

int main(){
    cout << setw(30) << "A" << setw(40) << "B" << setw(40) << "C" << endl;
    cout << setw(6) << "#n" << setw(10) << "AveTime" << setw(10) << "n/3" << setw(10)<< "2n/3" << setw(10) << "n";
    cout << setw(10) << "AveTime" << setw(10) << "n/3" << setw(10)<< "2n/3" << setw(10) << "n";
    cout << setw(10) << "AveTime" << setw(10) << "n/3" << setw(10)<< "2n/3" << setw(10) << "n" << endl;
    for(int i = 10; i <= 1010; i += 100){
        ArrayOfJob job;
        job.initializeA(i);
        job.initializeB(job.getA(), i);
        job.initializeC(i);
        cout << setw(6) << i << setw(10) << job.calculateTime(1,i,i) << setw(10)<< job.getWaitingTime(1,i/3,i) << setw(10) << job.getWaitingTime(1,2*i/3,i) << setw(10) << job.getWaitingTime(1,i,i);
        cout << setw(10) << job.calculateTime(2,i,i) << setw(10)<< job.getWaitingTime(2,i/3,i) << setw(10) << job.getWaitingTime(2,2*i/3,i) << setw(10) << job.getWaitingTime(2,i,i);
        cout << setw(10) << job.calculateTime(3,i,i) << setw(10)<< job.getWaitingTime(3,i/3,i) << setw(10) << job.getWaitingTime(3,2*i/3,i) << setw(10) << job.getWaitingTime(3,i,i);
        cout << endl;
    }
}