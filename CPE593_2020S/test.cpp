#include <iostream>
#include <iomanip>
#include <math.h>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

void add(int** A, int** B, int** result, int size);
void sub(int** A, int** B, int** result, int size);
void mul(int** A, int** B, int** result, int size);
void initialM(int** A, int size);
void Strassen(int** A, int** B, int** result,int size);
void SQUARE_MATRIX_MULTIPLY(int **A, int **B, int **C, int n);
void run_time(int** A, int** B, int** C, int** D, float* t1, float* t2, int size);
float time_per_item(float* t1);
void output_run_times(float item_SQUARE, float item_STRASSEN , float* Runtime_SQUARE,float* Runtime_STRASSEN);


int main(){
    float Runtime_SQUARE[10];
    float Runtime_STRASSEN[10];
    float item_SQUARE;
    float item_STRASSEN;
    int size = 2;
    unsigned int loop = 0;
    int times = 1;

    while(times <= 10){
        int** A = new int*[size];
        int** B = new int*[size];
        int** C = new int*[size];
        int** D = new int*[size];

        for(int i = 0; i < size;++i){
            A[i] = new int[size];
            B[i] = new int[size];
            C[i] = new int[size];
            D[i] = new int[size];
        }
        initialM(A, size);
        initialM(B, size);
        run_time(A,B,C,D,&Runtime_SQUARE[loop],&Runtime_STRASSEN[loop],size);
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


void add(int** A, int** B, int** result, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void sub(int** A, int** B, int** result, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void mul(int** A, int** B, int** result, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for(int k = 0; k < size; ++k){
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void initialM(int** A, int size){
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            A[i][j] = rand() % size;
        }
    }
}

void SQUARE_MATRIX_MULTIPLY(int **A, int **B, int **C, int n);
void Strassen(int** A, int** B, int** result,int size){
    if(size < 2){
        result[0][0] = A[0][0] * B[0][0];
        return;
    }
    int halfsize = size / 2;

    int **A11 = new int *[halfsize];
    int **A12 = new int *[halfsize];
    int **A21 = new int *[halfsize];
    int **A22 = new int *[halfsize];
    int **B11 = new int *[halfsize];
    int **B12 = new int *[halfsize];
    int **B21 = new int *[halfsize];
    int **B22 = new int *[halfsize];
    int **C11 = new int *[halfsize];
    int **C12 = new int *[halfsize];
    int **C21 = new int *[halfsize];
    int **C22 = new int *[halfsize];

    int **S1 = new int *[halfsize];
    int **S2 = new int *[halfsize];
//    int **S3 = new int *[halfsize];
//    int **S4 = new int *[halfsize];
//    int **S5 = new int *[halfsize];
//    int **S6 = new int *[halfsize];
//    int **S7 = new int *[halfsize];
//    int **S8 = new int *[halfsize];
//    int **S9 = new int *[halfsize];
//    int **S10 = new int *[halfsize];

    int **P1 = new int *[halfsize];
    int **P2 = new int *[halfsize];
    int **P3 = new int *[halfsize];
    int **P4 = new int *[halfsize];
    int **P5 = new int *[halfsize];
    int **P6 = new int *[halfsize];
    int **P7 = new int *[halfsize];

    for(int i = 0; i < halfsize;++i){

        A11[i] = new int[halfsize];
        A12[i] = new int[halfsize];
        A21[i] = new int[halfsize];
        A22[i] = new int[halfsize];
        B11[i] = new int[halfsize];
        B12[i] = new int[halfsize];
        B21[i] = new int[halfsize];
        B22[i] = new int[halfsize];
        C11[i] = new int[halfsize];
        C12[i] = new int[halfsize];
        C21[i] = new int[halfsize];
        C22[i] = new int[halfsize];

        S1[i] = new int[halfsize];
        S2[i] = new int[halfsize];
//        S3[i] = new int[halfsize];
//        S4[i] = new int[halfsize];
//        S5[i] = new int[halfsize];
//        S6[i] = new int[halfsize];
//        S7[i] = new int[halfsize];
//        S8[i] = new int[halfsize];
//        S9[i] = new int[halfsize];
//        S10[i] = new int[halfsize];

        P1[i] = new int[halfsize];
        P2[i] = new int[halfsize];
        P3[i] = new int[halfsize];
        P4[i] = new int[halfsize];
        P5[i] = new int[halfsize];
        P6[i] = new int[halfsize];
        P7[i] = new int[halfsize];

    }
    for(int i = 0; i < halfsize; ++i){
        for(int j = 0; j < halfsize; ++j){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + halfsize];
            A21[i][j] = A[i + halfsize][j];
            A22[i][j] = A[i + halfsize][j + halfsize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + halfsize];
            B21[i][j] = B[i + halfsize][j];
            B22[i][j] = B[i + halfsize][j + halfsize];

        }
    }

//    sub(B12,B22,S1,halfsize);
//    add(A11,A12,S2,halfsize);
//    add(A21,A22,S3,halfsize);
//    sub(B21,B11,S4,halfsize);
//    add(A11,A22,S5,halfsize);
//    add(B11,B22,S6,halfsize);
//    sub(A12,A22,S7,halfsize);
//    add(B21,B22,S8,halfsize);
//    sub(A11,A21,S9,halfsize);
//    add(B11,B12,S10,halfsize);
//
//    Strassen(A11,S1,P1,halfsize);
//    Strassen(S2,B22,P2,halfsize);
//    Strassen(S3,B11,P3,halfsize);
//    Strassen(A22,S4,P4,halfsize);
//    Strassen(S5,S6,P5,halfsize);
//    Strassen(S7,S8,P6,halfsize);
//    Strassen(S9,S10,P7,halfsize);
    add(A11, A22, S1, halfsize);
    add(B11, B22, S2, halfsize);
    Strassen(S1, S2, P1, halfsize); //now that we need to multiply this , we use the strassen itself .


    //M2[][]
    add(A21, A22, S1, halfsize);              //M2=(A21+A22)B11
    Strassen(S1, B11, P2, halfsize);       //Mul(AResult,B11,M2);

    //M3[][]
    sub(B12, B22, S2, halfsize);              //M3=A11(B12-B22)
    Strassen(A11, S2, P3, halfsize);       //Mul(A11,BResult,M3);

    //M4[][]
    sub(B21, B11, S2, halfsize);           //M4=A22(B21-B11)
    Strassen(A22, S2, P4, halfsize);       //Mul(A22,BResult,M4);

    //M5[][]
    add(A11, A12, S1, halfsize);           //M5=(A11+A12)B22
    Strassen(S1, B22, P5, halfsize);       //Mul(AResult,B22,M5);


    //M6[][]
    sub(A21, A11, S1, halfsize);
    add(B11, B12, S2, halfsize);             //M6=(A21-A11)(B11+B12)
    Strassen(S1, S2, P6, halfsize);    //Mul(AResult,BResult,M6);

    //M7[][]
    sub(A12, A22, S1, halfsize);
    add(B21, B22, S2, halfsize);             //M7=(A12-A22)(B21+B22)
    Strassen(S1, S2, P7, halfsize);     //Mul(AResult,BResult,M7);

    //C11 = M1 + M4 - M5 + M7;
    add(P1, P4, S1, halfsize);
    sub(P7, P5, S2, halfsize);
    add(S1, S2, C11, halfsize);

    //C12 = M3 + M5;
    add(P3, P5, C12, halfsize);

    //C21 = M2 + M4;
    add(P2, P4, C21, halfsize);

    //C22 = M1 + M3 - M2 + M6;
    add(P1, P3, S1, halfsize);
    sub(P6, P2, S2, halfsize);
    add(S1, S2, C22, halfsize);

//    add(P5,P4,C11,halfsize);
//    sub(C11,P2,C11,halfsize);
//    add(C11,P6,C11,halfsize);
//
//    add(P1,P2,C12,halfsize);
//
//    add(P3,P4,C21,halfsize);
//
//    add(P5,P1,C22,halfsize);
//    sub(C22,P3,C22,halfsize);
//    sub(C22,P7,C22,halfsize);

    for(int i = 0; i < halfsize; ++i){
        for(int j = 0; j < halfsize; ++j){
            result[i][j] = C11[i][j];
            result[i][j + halfsize] = C12[i][j];
            result[i + halfsize][j] = C21[i][j];
            result[i + halfsize][j+halfsize] = C22[i][j];
        }
    }

    for (int i = 0; i < halfsize; i++)
    {
        delete[] A11[i]; delete[] A12[i]; delete[] A21[i]; delete[] A22[i];
        delete[] B11[i]; delete[] B12[i]; delete[] B21[i]; delete[] B22[i];
        delete[] C11[i]; delete[] C12[i]; delete[] C21[i]; delete[] C22[i];
        delete[] S1[i];delete[] S2[i];
//        delete[] S1[i];delete[] S2[i];delete S3[i];delete[] S4[i];delete[] S5[i];
//        delete[] S6[i];delete[] S7[i];delete[] S8[i];delete[] S9[i];delete S10[i];
        delete[] P1[i]; delete[] P2[i]; delete[] P3[i]; delete[] P4[i];
        delete[] P5[i]; delete[] P6[i]; delete[] P7[i];

    }
    delete[] A11; delete[] A12; delete[] A21; delete[] A22;
    delete[] B11; delete[] B12; delete[] B21; delete[] B22;
    delete[] C11; delete[] C12; delete[] C21; delete[] C22;
    delete[] S1;delete[] S2;
//    delete[] S1;delete[] S2;delete S3;delete[] S4;delete[] S5;
//    delete[] S6;delete[] S7;delete[] S8;delete[] S9;delete S10;
    delete[] P1; delete[] P2; delete[] P3; delete[] P4; delete[] P5;
    delete[] P6; delete[] P7;

}

void run_time(int** A, int** B, int** C, int** D, float* t1, float* t2,int size) {

    auto start = high_resolution_clock::now();
    mul(A,B,C,size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    *t1 = 1.0*duration.count();

    start = high_resolution_clock::now();
    Strassen(A,B,D,size);
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