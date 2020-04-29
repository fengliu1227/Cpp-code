// Siyang Wu
// Assignment # 2 CPE 593 Algorithms and Data Structures
// Spring 2020
// Instructor: Dr. Aftab Ahmad
// I certifiy that no plagiarism or cheating was done
// in doing this assignment.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <math.h>
using namespace std;
using namespace std::chrono;

class Matrix {
private:
    int size;
    int **m;
public:
    Matrix (int size) : size(size) {
        m = new int *[size];
        for (int i = 0; i < size; i ++) {
            m[i] = new int[size];
        }
        // srand(time(NULL));
        for (int i = 0; i < size; i ++) {
            for (int j = 0; j < size; j ++) {
                m[i][j] = rand() % (size);
            }
        }
    }

    Matrix& operator =(const Matrix& M) {
        this->size = M.size;
        this->m = new int *[size];
        for (int i = 0; i < size; i ++) {
            this->m[i] = new int[size];
        }
        for (int i = 0; i < size; i ++) {
            for (int j = 0; j < size; j ++) {
                m[i][j] = M.m[i][j];
            }
        }
        return *this;
    }

    friend Matrix operator *(const Matrix& A, const Matrix& B) {
        Matrix C(A.size);
        for (int i = 0; i < A.size; i ++) {
            for (int j = 0; j < A.size; j ++) {
                C.m[i][j] = 0;
            }
        }
        for (int i = 0; i < A.size; i ++) {
            for (int j = 0; j < A.size; j ++) {
                for (int k = 0; k < A.size; k ++) {
                    C.m[i][j] += A.m[i][k] * B.m[k][j];
                }
            }
        }
        return C;
    }

    friend Matrix operator +(const Matrix& A, const Matrix& B) {
        Matrix C(A.size);
        for (int i = 0; i < A.size; i ++) {
            for (int j = 0; j < A.size; j ++) {
                C.m[i][j] = 0;
                C.m[i][j] = A.m[i][j] + B.m[i][j];
            }
        }
        return C;
    }

    friend Matrix operator -(const Matrix& A, const Matrix& B) {
        Matrix C(A.size);
        for (int i = 0; i < A.size; i ++) {
            for (int j = 0; j < A.size; j ++) {
                C.m[i][j] = 0;
                C.m[i][j] = A.m[i][j] - B.m[i][j];
            }
        }
        return C;
    }

    friend Matrix Strassen (Matrix& A, Matrix& B) {
        int N = A.size;
        Matrix C(N);
        if (A.size != B.size) {
            cout << "Error" << endl;
        }
        if (N == 1) {
            C = A * B;
        } else {
            int n = N / 2;
            Matrix A1(n);
            Matrix A2(n);
            Matrix A3(n);
            Matrix A4(n);
            Matrix B1(n);
            Matrix B2(n);
            Matrix B3(n);
            Matrix B4(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    A1.m[i][j] = A.m[i][j];
                    A2.m[i][j] = A.m[i][n + j];
                    A3.m[i][j] = A.m[i + n][j];
                    A4.m[i][j] = A.m[i + n][j + n];
                    B1.m[i][j] = B.m[i][j];
                    B2.m[i][j] = B.m[i][n + j];
                    B3.m[i][j] = B.m[i + n][j];
                    B4.m[i][j] = B.m[i + n][j + n];
                }
            }
            Matrix S1 = B2 - B4;
            Matrix S2 = A1 + A2;
            Matrix S3 = A3 + A4;
            Matrix S4 = B3 - B1;
            Matrix S5 = A1 + A4;
            Matrix S6 = B1 + B4;
            Matrix S7 = A2 - A4;
            Matrix S8 = B3 + B4;
            Matrix S9 = A1 - A3;
            Matrix S10 = B1 + B2;
            Matrix M1 = Strassen(A1, S1);
            Matrix M2 = Strassen(S2, B4);
            Matrix M3 = Strassen(S3, B1);
            Matrix M4 = Strassen(A4, S4);
            Matrix M5 = Strassen(S5, S6);
            Matrix M6 = Strassen(S7, S8);
            Matrix M7 = Strassen(S9, S10);
            Matrix C1 = M5 + M4 - M2 + M6;
            Matrix C2 = M1 + M2;
            Matrix C3 = M3 + M4;
            Matrix C4 = M5 + M1 - M3 - M7;
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < n; j ++) {
                    C.m[i][j] = C1.m[i][j];
                    C.m[i][n + j] = C2.m[i][j];
                    C.m[i + n][j] = C3.m[i][j];
                    C.m[i + n][j + n] = C4.m[i][j];
                }
            }
        }
        return C;
    }

    ~Matrix() {
        for (int i = 0; i < size; i ++) {
            delete []m[i];
        }
        delete m;
    }

    void Display() {
        for (int i = 0; i < size; i ++) {
            for (int j = 0; j < size; j ++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
};

void run_time(Matrix& A, Matrix& B, float* t1, float* t2) {
    auto start = high_resolution_clock::now();
    A * B;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds> (stop - start);
    *t1 = 1.0 * duration.count();
    start = high_resolution_clock::now();
    Strassen(A,B);
    cout << endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds> (stop - start);
    *t2 = 1.0 * duration.count();
}

float time_per_item(float* t1) {
    float t2 = 0.0;
    for (int k = 0; k < 10; k ++) {
        t2 += t1[k];
    }
    t2 = t2 / 1398100; // 2 * 2 + 2^2 * 2^2 + 2^3 * 2^3.... + 2^10 * 2^10
    return t2;
}

void output_run_times(float ThreeForLoop_item_t, float Strassen_item_t, float* ThreeForLoop_t, float* Strassen_t) {
    int n = 2;
    int i = 0;
    while (i < 10) {
        cout << n << "\t\t" << ThreeForLoop_t[i] << "\t\t" << ThreeForLoop_item_t * n * n * n;
        cout << "\t\t" << Strassen_t[i] << "\t\t" << Strassen_item_t * pow(n, 2.81);
        cout << endl;
        ++ i;
        n *= 2;
    }
}

int main() {
    srand(time(NULL));
    float ThreeFor[10];
    float Strassen[10];
    float ThreeFor_timeperitem;
    float Strassen_timeperitem;
    unsigned int size = 2;
    unsigned int loop = 0;
    while (size <= 1024) {
        Matrix A (size);
        Matrix B (size);
        run_time(A, B, &ThreeFor[loop], &Strassen[loop]);
        size *= 2;
        loop ++;
    }
    ThreeFor_timeperitem = time_per_item(ThreeFor);
    Strassen_timeperitem = time_per_item(Strassen);
    cout << "\n#n\t\tThreeFor_t\t\tThreeFor_O\t\tStrassen_t\t\tStrassen_O\n\n";
    output_run_times(ThreeFor_timeperitem, Strassen_timeperitem, ThreeFor, Strassen);
}
