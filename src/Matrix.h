#ifndef MATRIX_H
#define MATRIX_H
#include "Tuple.h"
#include <vector>
#include <iostream>
#include <cassert>

// only need 2x2, 3x3 and 4x4 matrix
class Matrix {
    //access with row, column
    public:
        int size;
        Matrix(int size, std::string typ="none");
        std::vector<float> & operator[](int index);
        Matrix operator*(const Matrix &b) const;
        Tuple operator*(const Tuple &b) const;
        void init(std::vector<std::vector<float>> m);
        void print() const;
        Matrix transpose() const;
        float determinant() const;
        Matrix submatrix(int row, int col) const;
        float cofactor(int row, int col) const;
        bool invertible() const;
        Matrix inverse() const;

    private:
        std::vector<std::vector<float>> matrix;
};

bool equal(Matrix a, Matrix b);

const Matrix IDENTITY(4, "id");

#endif