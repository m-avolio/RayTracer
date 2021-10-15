#ifndef MATRIX_H
#define MATRIX_H
#include "Tuple.h"
#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>

#define PI M_PI

// only need 2x2, 3x3 and 4x4 matrix
class Matrix {
    //access with row, column
    public:
        int size;
        Matrix(int size, std::string typ="none");
        std::vector<float> & operator[](int index);
        Matrix operator*(const Matrix &b) const;
        Tuple operator*(const Tuple &b) const;
        Point operator*(const Point &b) const;
        Vector operator*(const Vector &b) const;
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
Matrix translation(float x, float y, float z);
Matrix scaling(float x, float y, float z);
Matrix rotationX(float r);
Matrix rotationY(float r);
Matrix rotationZ(float r);
Matrix shearing(float xy, float xz, float yx, float yz, float zx, float zy);

const Matrix IDENTITY(4, "id");

#endif