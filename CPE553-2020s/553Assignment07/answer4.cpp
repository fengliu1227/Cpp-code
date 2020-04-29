//
// Created by Leo on 4/2/20.
//
#include <iostream>
using namespace std;
class Matrix{
private:
    uint32_t rows, cols;
    double* p;
public:
    Matrix(uint32_t rows, uint32_t cols, uint32_t num) : rows(rows), cols(cols){
        for(int i = 0; i < rows * cols; ++i){
            p[i] = num;
        }
    }
    ~Matrix(){
        delete [] p;
    }

    Matrix& operator = (Matrix copy){
        rows = copy.rows;
        cols = copy.cols;
        swap(p, copy.p);
        return *this;
    }

    Matrix(const Matrix& orig) : rows(orig.rows), cols(orig.cols), p(orig.p){
        memcpy(p, orig.p, sizeof(uint32_t) * rows * cols);
    }

    Matrix(Matrix&& orig) : rows(orig.rows), cols(orig.cols), p(orig.p){
        orig.p = nullptr;
    }

    double operator() (int a, int b){
        return p[a * cols + rows];
    }
    friend Matrix operator + (const Matrix& a, const Matrix& b){
        Matrix result(a.rows,a.cols,0);
            for (int i = 0; i < a.rows * a.cols ; ++i) {
                    result.p[i] = a.p[i] + b.p[i];
                }

        return result;
    }
    friend ostream& operator << (ostream& s, const Matrix& a){
        for(int i = 0; i < a.rows * a.cols; ++i){
            if(i % (a.cols + 1) ==0 && i != 0){
                s << '\n';
            }
            s << a.p[i];
        }
        return s;
    }
};
int main() {
    Matrix a(3, 4, 0.0); // create a matrix with 3 rows, 4 cols, all zero
    /*
        0.0  0.0  0.0  0.0
        0.0  0.0  0.0  0.0
        0.0  0.0  0.0  0.0
     */
    a(2,3) = 2.5;        // overload operator() indexing into block is m[2*rows+3]
    /*
        0.0  0.0  0.0  0.0
        0.0  0.0  0.0  0.0
        0.0  0.0  0.0  2.5
    */
    Matrix b(3, 4, 1.0); // same but all 1.
    /*
        1.0  1.0  1.0  1.0
        1.0  1.0  1.0  1.0
        1.0  1.0  1.0  1.0
     */
    Matrix c = a + b;    // create a new matrix
    /*
        1.0  1.0  1.0  1.0
        1.0  1.0  1.0  1.0
        1.0  1.0  1.0  2.5

matrices are to be stored in row major order. In other words, a single block of memory like this:
     0    1    2    3    4    5    6    7    8    9    10   11
        1.0  1.0  1.0  1.0	1.0  1.0  1.0  1.0	1.0  1.0  1.0  2.5
     */

    cout << c; // print out the matrix

    /*
        1.0  1.0  1.0  1.0
        1.0  1.0  1.0  1.0
        1.0  1.0  1.0  2.5
    */

    Matrix d = a;
    Matrix e(c);
    e = d;
}