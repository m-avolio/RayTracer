#ifndef MATRIX_H
#define MATRIX_H
#include "Tuple.h"
#include <vector>

// only need 2x2, 3x3 and 4x4 matrix
class Matrix {
    //access with row, column
    public:
        int size;
        Matrix(int size);
        std::vector<float> & operator[](int index);
        Matrix operator*(const Matrix &b);
        Tuple operator*(const Tuple &b);
        void init(std::vector<std::vector<float>> m);

    private:
        std::vector<std::vector<float>> matrix;
};

bool equal(const Matrix &a, const Matrix &b);

#endif
