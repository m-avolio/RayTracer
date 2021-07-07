#include "Matrix.h"

Matrix::Matrix(int size): size{size} {
    std::vector<std::vector<float>> temp(size, std::vector<float>(size, 0));
    matrix = temp;
}

std::vector<float> & Matrix::operator[](int index) {
    return matrix[index];
}

void Matrix::init(std::vector<std::vector<float>> m) {
    matrix = m;
}
