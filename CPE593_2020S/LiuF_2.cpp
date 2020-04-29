//Feng Liu
// Assignment # 1 CPE 593 Algorithms and Data Structures
// Spring 2020
// Instructor: Dr. Aftab Ahmad
// I certifiy that no plagiarism or cheating was done
// in doing this assignment.

//this file runs extremely slow
#include <iostream>
#include <iomanip>
#include <math.h>
#include <chrono>
#include <fstream>
#include <random>
using namespace std;
using namespace std::chrono;

class Matrix{
private:
    int size;
    int* matrix;
    Matrix(int size, const char *) {
        matrix = new int [size*size];
    }
public:
    Matrix(int size) : size(size){
        matrix = new int [size*size];

        mt19937 rng;
        rng.seed(random_device()());
        uniform_int_distribution<unsigned> u (0,size);
        for (int i = 0; i < size*size; ++i){
                matrix[i] = u(rng);
        }

    }

    void print(){
        for (int i = 0; i < size * size; ++i){
               cout << matrix[i] << setw(4)<<'\t';
               if( i + 1 % size == 0) {
                   cout << '\n';
               }
        }
        cout << '\n';
    }

    friend Matrix operator * (const Matrix& a, const Matrix& b){
        Matrix result(a.size, "private");
        if(a.size != b.size)
            throw "badsize";
        for (int i = 0; i < a.size; ++i) {
            for (int j = 0; j < a.size; ++j) {
                    double dot = 0;
                    for(int k = 0; k < a.size; ++k){
//                         dot += a.matrix[i] * b.matrix[i * b.size];
                    }
                result.matrix[i][j]=dot;
                }
            }
        }
        else{
            cout << "cannot do this operation" << endl;
            return 0;
        }

        return result;
    }

    friend Matrix operator + (const Matrix& a, const Matrix& b){
        Matrix result(a.size);
        if(a.size == b.size) {
            for (int i = 0; i < a.size; ++i) {
                for (int j = 0; j < a.size; ++j) {
                        result.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
                }
            }
        }
        else{
            cout << "cannot do this operation" << endl;
            return 0;
        }

        return result;
    }

    friend Matrix operator - (const Matrix& a, const Matrix& b){
        Matrix result(a.size);
        if(a.size == b.size) {
            for (int i = 0; i < a.size; ++i) {
                for (int j = 0; j < a.size; ++j) {
                    result.matrix[i][j] = 0;
                        result.matrix[i][j] += a.matrix[i][j] - b.matrix[i][j];
                }
            }
        }
        else{
            cout << "cannot do this operation" << endl;
            return 0;
        }
        return result;
    }

    friend Matrix Strassen(Matrix& a, Matrix& b){
        int N = a.size;
        if(a.size != b.size){
            cout << "cannot do this operation" << endl;
            return 0;
        }
        else if(N < 2){
            Matrix result = a * b;
            return result;

        }
        else{
            int halfSize = a.size / 2;
            Matrix result(a.size);
            Matrix A11(halfSize);
            Matrix A12(halfSize);
            Matrix A21(halfSize);
            Matrix A22(halfSize);
            Matrix B11(halfSize);
            Matrix B12(halfSize);
            Matrix B21(halfSize);
            Matrix B22(halfSize);

            for (int i = 0; i < halfSize; i++) {
                for (int j = 0; j < halfSize; j++) {
                    A11.matrix[i][j] = a.matrix[i][j];
                    A12.matrix[i][j] = a.matrix[i][j + halfSize];
                    A21.matrix[i][j] = a.matrix[i + halfSize][j];
                    A22.matrix[i][j] = a.matrix[i + halfSize][j + halfSize];
                    B11.matrix[i][j] = b.matrix[i][j];
                    B12.matrix[i][j] = b.matrix[i][j + halfSize];
                    B21.matrix[i][j] = b.matrix[i + halfSize][j];
                    B22.matrix[i][j] = b.matrix[i + halfSize][j + halfSize];
                }
            }

            Matrix S1 = B12 - B22;
            Matrix S2 = A11 + A12;
            Matrix S3 = A21 + A22;
            Matrix S4 = B21 - B11;
            Matrix S5 = A11 + A22;
            Matrix S6 = B11 + B22;
            Matrix S7 = A12 - A22;
            Matrix S8 = B21 + B22;
            Matrix S9 = A11 - A21;
            Matrix S10 = B11 + B12;
            Matrix M1 = Strassen(A11,S1);
            Matrix M2 = Strassen(S2,B22);
            Matrix M3 = Strassen(S3,B11);
            Matrix M4 = Strassen(A22,S4);
            Matrix M5 = Strassen(S5,S6);
            Matrix M6 = Strassen(S7,S8);
            Matrix M7 = Strassen(S9,S10);

            Matrix C1 = M5 + M4 - M2 + M6;
            Matrix C2 = M1 + M2;
            Matrix C3 = M3 + M4;
            Matrix C4 = M5 + M1 - M3 - M7;
            for (int i = 0; i < halfSize; i++) {
                for (int j = 0; j < halfSize; j++) {
                    result.matrix[i][j] = C1.matrix[i][j];
                    result.matrix[i][j + halfSize] = C2.matrix[i][j];
                    result.matrix[i + halfSize][j] = C3.matrix[i][j];
                    result.matrix[i + halfSize][j + halfSize] = C4.matrix[i][j];
                }
            }

//            for(int i = 0; i < halfSize; ++i){
//                delete[] A11.matrix[i]; delete[] A12.matrix[i]; delete[] A21.matrix[i]; delete[] A22.matrix[i];
//                delete[] B11.matrix[i]; delete[] B12.matrix[i]; delete[] B21.matrix[i]; delete[] B22.matrix[i];
//                delete[] S1.matrix[i]; delete[] S2.matrix[i]; delete[] S3.matrix[i]; delete[] S4.matrix[i]; delete[] S5.matrix[i];
//                delete[] S6.matrix[i]; delete[] S7.matrix[i]; delete[] S8.matrix[i]; delete[] S9.matrix[i]; delete[] S10.matrix[i];
//                delete[] M1.matrix[i]; delete[] M2.matrix[i]; delete[] M3.matrix[i]; delete[] M4.matrix[i];
//                delete[] M5.matrix[i]; delete[] M6.matrix[i]; delete[] M7.matrix[i];
//                delete[] C1.matrix[i]; delete[] C2.matrix[i]; delete[] C3.matrix[i]; delete[] C4.matrix[i];
//            }
//            delete[] A11.matrix; delete[] A12.matrix; delete[] A21.matrix; delete[] A22.matrix;
//            delete[] B11.matrix; delete[] B12.matrix; delete[] B21.matrix; delete[] B22.matrix;
//            delete[] S1.matrix; delete[] S2.matrix; delete[] S3.matrix; delete[] S4.matrix; delete[] S5.matrix;
//            delete[] S6.matrix; delete[] S7.matrix; delete[] S8.matrix; delete[] S9.matrix; delete[] S10.matrix;
//            delete[] M1.matrix; delete[] M2.matrix; delete[] M3.matrix; delete[] M4.matrix;
//            delete[] M5.matrix; delete[] M6.matrix; delete[] M7.matrix;
//            delete[] C1.matrix; delete[] C2.matrix; delete[] C3.matrix; delete[]C4.matrix;

            return result;
        }
    }
    ~Matrix(){
        delete[]  matrix;
    }


};

void run_time(Matrix& A, Matrix& B, float* t1, float* t2);

float time_per_item(float* t1);

void output_run_times(float IS_item_t, float MS_item_t, float* IS_t,float* MS_t);


int main(){
    float Runtime_SQUARE[10];
    float Runtime_STRASSEN[10];
    float item_SQUARE;
    float item_STRASSEN;
    int size = 2;
    unsigned int loop = 0;
    int times = 1;

    while(times <= 10){
        Matrix A(size);
        Matrix B(size);
        if(size == 4){
            A.print();
            B.print();
            Matrix C = A * B;
            Matrix D = Strassen(A,B);
            C.print();
            D.print();
        }
        run_time(A,B,&Runtime_SQUARE[loop],&Runtime_STRASSEN[loop]);
        size *= 2;
        cout << "loop = " << loop << "  size =  " << size << endl;
        ++loop;
        ++times;
    }
    for(float a: Runtime_SQUARE){
        cout << a;
    }
    item_SQUARE = time_per_item(Runtime_SQUARE);
    item_STRASSEN = time_per_item(Runtime_STRASSEN);

    cout << "\n#n\t\tRuntime_SQUARE\t\tBound_SQUARE\t\tRuntime_STRASSEN\t\tBound_STRASSEN\n\n";
    output_run_times(item_SQUARE,item_STRASSEN,Runtime_SQUARE,Runtime_STRASSEN);
}

 void run_time(Matrix& A, Matrix& B, float* t1, float* t2) {

    auto start = high_resolution_clock::now();
    A * B;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    *t1 = 1.0*duration.count();

    start = high_resolution_clock::now();
    Strassen(A,B);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    *t2 = 1.0*duration.count();
}

float time_per_item(float* t1) {
    float t2 = 0.0;
    for (int k = 0; k <= 10; ++k){
        t2 += t1[k];
    }
    t2 = t2/1398100.0;
    return t2;
}

void output_run_times(float item_SQUARE, float item_STRASSEN , float* Runtime_SQUARE,float* Runtime_STRASSEN){
    int n = 2;
    int i = 0;

    while (i < 10) {
        cout << n << "\t\t" << Runtime_SQUARE[i] << "\t\t" << item_SQUARE * n * n * n;
        cout << "\t\t" << Runtime_STRASSEN[i] << "\t\t" << item_STRASSEN * pow(n, 2.81);
        cout << endl;
        ++i;
        n *= 2;
    }
}