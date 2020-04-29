#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <math.h>

using namespace std;
using namespace std::chrono;

void initialize_matrix(int **array, int num);
void SQUARE_MATRIX_MULTIPLY(int **A, int **B, int **C, int n);
void print1(int **A,int n);
void STRASSEN_MATRIX_MULTIPLY(int **A, int **B, int **C, int n);
void MARTIX_SUB(int **A, int **B, int **C,int n);
void MARTIX_ADD(int **A, int **B, int **C,int n);
void run_time(int** A, int** B,int** C, int** D,int n, float* t1, float* t2);
float time_per_item(float*);
void output_run_times(float SQ_item_t,float ST_item_t,float* SQ_t, float*ST_t);

int main()
{
    srand(time(NULL));
    float SQ_runtime[10], ST_runtime[10];
    float SQ_timeperitem = 0.0, ST_timeperitem = 0.0;
    unsigned int n = 2;
    unsigned int loop = 0;
    while (n <= 1024)
    {
        int **A = new int *[n];
        int **B = new int *[n];
        int **C = new int *[n];
        int **D = new int *[n];
        for (int i = 0; i < n; i++)
        {
            A[i] = new int[n];
            B[i] = new int[n];
            C[i] = new int[n];
            D[i] = new int[n];
        }
        initialize_matrix(A, n);
        initialize_matrix(B, n);

        run_time(A,B,C,D,n,&SQ_runtime[loop],&ST_runtime[loop]);
        if(n == 4){
            cout<<"A"<<endl;
            print1(A,n);
            cout<<"B"<<endl;
            print1(B,n);
            cout<<"SQUARE_Matrix product matrix"<<endl;
            print1(C,n);
            cout<<"STRASSEN's method product matrix"<<endl;
            print1(D,n);
        }
        for(int i = 0; i<n; i++){
            delete[] A[i];delete[] B[i]; delete[] C[i]; delete[] D[i];
        }
        delete[] A;delete[] B; delete[] C; delete[] D;
        cout<<n<<endl;
        n = n * 2;
        loop++;

    }
    SQ_timeperitem = time_per_item(SQ_runtime);
    ST_timeperitem = time_per_item(ST_runtime);
    cout<<"\n#n\t\tSQ_t\t\tSQ_O\t\tST_t\t\tST_O\n\n";
    output_run_times(SQ_timeperitem,ST_timeperitem,SQ_runtime,ST_runtime);
}
void STRASSEN_MATRIX_MULTIPLY(int **A, int **B, int **C, int n){
    if(n == 1){
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int halfsize = n / 2;

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
    int **S3 = new int *[halfsize];
    int **S4 = new int *[halfsize];
    int **S5 = new int *[halfsize];
    int **S6 = new int *[halfsize];
    int **S7 = new int *[halfsize];
    int **S8 = new int *[halfsize];
    int **S9 = new int *[halfsize];
    int **S10 = new int *[halfsize];

    int **P1 = new int *[halfsize];
    int **P2 = new int *[halfsize];
    int **P3 = new int *[halfsize];
    int **P4 = new int *[halfsize];
    int **P5 = new int *[halfsize];
    int **P6 = new int *[halfsize];
    int **P7 = new int *[halfsize];

    for(int i = 0; i < halfsize;i++){

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
        S3[i] = new int[halfsize];
        S4[i] = new int[halfsize];
        S5[i] = new int[halfsize];
        S6[i] = new int[halfsize];
        S7[i] = new int[halfsize];
        S8[i] = new int[halfsize];
        S9[i] = new int[halfsize];
        S10[i] = new int[halfsize];

        P1[i] = new int[halfsize];
        P2[i] = new int[halfsize];
        P3[i] = new int[halfsize];
        P4[i] = new int[halfsize];
        P5[i] = new int[halfsize];
        P6[i] = new int[halfsize];
        P7[i] = new int[halfsize];

    }
    for(int i = 0; i < halfsize; i++){
        for(int j = 0; j < halfsize; j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+halfsize];
            A21[i][j] = A[i+halfsize][j];
            A22[i][j] = A[i+halfsize][j+halfsize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+halfsize];
            B21[i][j] = B[i+halfsize][j];
            B22[i][j] = B[i+halfsize][j+halfsize];

        }
    }

    MARTIX_SUB(B12,B22,S1,halfsize);
    MARTIX_ADD(A11,A12,S2,halfsize);
    MARTIX_ADD(A21,A22,S3,halfsize);
    MARTIX_SUB(B21,B11,S4,halfsize);
    MARTIX_ADD(A11,A22,S5,halfsize);
    MARTIX_ADD(B11,B22,S6,halfsize);
    MARTIX_SUB(A12,A22,S7,halfsize);
    MARTIX_ADD(B21,B22,S8,halfsize);
    MARTIX_SUB(A11,A21,S9,halfsize);
    MARTIX_ADD(B11,B12,S10,halfsize);

    STRASSEN_MATRIX_MULTIPLY(A11,S1,P1,halfsize);
    STRASSEN_MATRIX_MULTIPLY(S2,B22,P2,halfsize);
    STRASSEN_MATRIX_MULTIPLY(S3,B11,P3,halfsize);
    STRASSEN_MATRIX_MULTIPLY(A22,S4,P4,halfsize);
    STRASSEN_MATRIX_MULTIPLY(S5,S6,P5,halfsize);
    STRASSEN_MATRIX_MULTIPLY(S7,S8,P6,halfsize);
    STRASSEN_MATRIX_MULTIPLY(S9,S10,P7,halfsize);

    MARTIX_ADD(P5,P4,C11,halfsize);
    MARTIX_SUB(C11,P2,C11,halfsize);
    MARTIX_ADD(C11,P6,C11,halfsize);

    MARTIX_ADD(P1,P2,C12,halfsize);

    MARTIX_ADD(P3,P4,C21,halfsize);

    MARTIX_ADD(P5,P1,C22,halfsize);
    MARTIX_SUB(C22,P3,C22,halfsize);
    MARTIX_SUB(C22,P7,C22,halfsize);

    for(int i = 0; i < halfsize; i++){
        for(int j = 0; j < halfsize; j++){
            C[i][j] = C11[i][j];
            C[i][j+halfsize] = C12[i][j];
            C[i+halfsize][j] = C21[i][j];
            C[i+halfsize][j+halfsize] = C22[i][j];
        }
    }
    // delete[] A11,A12,A21,A22,B11,B12,B21,B22,C11,C12,C21,C22,S1,S2,S3,S4,S5,S6,S7,S8,S9,S10,P1,P2,P3,P4,P5,P6,P7;
    for(int i = 0; i < halfsize; i++){
        delete[] A11[i];delete[] A12[i]; delete[] A21[i]; delete[] A22[i];
        delete[] B11[i];delete[] B12[i]; delete[] B21[i]; delete[] B22[i];
        delete[] C11[i];delete[] C12[i]; delete[] C21[i]; delete[] C22[i];
        delete[] S1[i];delete[] S2[i];delete S3[i];delete[] S4[i];delete[] S5[i];
        delete[] S6[i];delete[] S7[i];delete[] S8[i];delete[] S9[i];delete S10[i];
        delete[] P1[i];delete[] P2[i];delete[] P3[i];delete[] P4[i];
        delete[] P5[i];delete[] P6[i];delete[] P7[i];
    }
    delete[] A11;delete[] A12;delete[] A21;delete[] A22;delete[] B11;delete[] B12;
    delete[] B21;delete[] B22;delete[] C11;delete[] C12;delete[] C21;delete[] C22;
    delete[] S1;delete[] S2;delete[] S3;delete[] S4;delete[] S5;delete[] S6;
    delete[] S7;delete[] S8;delete[] S9;delete[] S10;delete[] P1;delete[] P2;
    delete[] P3;delete[] P4;delete[] P5;delete[] P6;delete[] P7;

}
void MARTIX_ADD(int **A, int **B, int **C,int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void MARTIX_SUB(int **A, int **B, int **C,int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}


void SQUARE_MATRIX_MULTIPLY(int **A, int **B, int **C, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

void print1(int **A, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}
void initialize_matrix(int **array, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[i][j] = rand() % (n);
        }
    }
}
void run_time(int** A, int** B, int** C, int** D,int n,float* t1, float* t2){
    auto start = high_resolution_clock::now();
    SQUARE_MATRIX_MULTIPLY(A,B,C,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    *t1 = 1.0*duration.count();

    start = high_resolution_clock::now();
    STRASSEN_MATRIX_MULTIPLY(A,B,D,n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    *t2 = 1.0 * duration.count();
}
float time_per_item(float* t1){
    float t2 = 0.0;
    int k = 0;
    for(int n = 2 ; n <= 1024;n *= 2 ){
        t2 += t1[k++]/n/n;
    }
    return t2/10;
}
void output_run_times(float SQ_item_t,float ST_item_t,float* SQ_t, float*ST_t){
    int n = 1;
    int i = 0;
    while(i < 10){
        int pow_n = pow(2,n);
        cout<< n << "\t\t"<<SQ_t[i]<<"\t\t"<<SQ_item_t*(pow_n,3);
        cout<<"\t\t"<<ST_t[i]<<"\t\t"<<ST_item_t*pow(pow_n,2.81);
        i++;
        n = n + 1;
    }
}