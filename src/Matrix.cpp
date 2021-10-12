#include "Matrix.h"

Matrix::Matrix(int size, std::string type): size{size} {
    std::vector<std::vector<float>> temp(size, std::vector<float>(size, 0));
    matrix = temp;
    if (type == "id") {
        this->init({{1, 0, 0, 0},
                    {0, 1, 0, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 1}});
    }
}

std::vector<float> & Matrix::operator[](int index) {
    return matrix[index];
}

void Matrix::init(std::vector<std::vector<float>> m) {
    matrix = m;
}

Matrix Matrix::operator*(const Matrix &b) const{
    int size = this->size;
    Matrix m(size);
    for (int i{0};  i < size; i++) {
        for (int j{0}; j < size; j++) {
            for (int k{0}; k < size; k++) {
                m[i][j] += this->matrix[i][k] * b.matrix[k][j];
            }
        }
    }
    return m;
}

Tuple Matrix::operator*(const Tuple &b) const{
    Tuple tuple;
    tuple.x = matrix[0][0]*b.x + matrix[0][1]*b.y + matrix[0][2]*b.z + matrix[0][3]*b.w;
    tuple.y = matrix[1][0]*b.x + matrix[1][1]*b.y + matrix[1][2]*b.z + matrix[1][3]*b.w;
    tuple.z = matrix[2][0]*b.x + matrix[2][1]*b.y + matrix[2][2]*b.z + matrix[2][3]*b.w;
    tuple.w = matrix[3][0]*b.x + matrix[3][1]*b.y + matrix[3][2]*b.z + matrix[3][3]*b.w;
    return tuple;
}

void Matrix::print() const{
    std::cout.precision(5);
    for (int i{0}; i < this->size; i++) {
        for (int j{0}; j < this->size; j++) {
            std::cout << std::fixed << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }    
}

Matrix Matrix::transpose() const {
    Matrix m(this->size);
    for (int i{0}; i < this->size; i++) {
        for (int j{0}; j < this->size; j++) {
            m[i][j] = this->matrix[j][i];
        }
    }
    return m;       
}

float Matrix::determinant() const {
    float det{0};
    if (this->size == 2) {
        det = this->matrix[0][0]*this->matrix[1][1] - this->matrix[0][1]*this->matrix[1][0]; 
    } else {
        for (int i{0}; i < this->size; i++) {
            det += this->matrix[0][i] * this->cofactor(0,i);
        }
    }
    return det;
}

Matrix Matrix::submatrix(int row, int col) const {
    assert(row < this->size && col < this->size);
    Matrix m(this->size-1);
    m.matrix = this->matrix;
    m.matrix.erase(m.matrix.begin()+row);
    for (int i{0}; i < m.size; i++) {
        m.matrix[i].erase(m.matrix[i].begin()+col);
    }
    return m;
}

float Matrix::cofactor(int row, int col) const {
    return (row+col)%2 == 0 ? submatrix(row, col).determinant() : -submatrix(row, col).determinant(); 
}

bool Matrix::invertible() const {
    return this->determinant() == 0 ? false : true;
}

Matrix Matrix::inverse() const {
    float det = this->determinant();
    assert(det != 0); //check if invertible and get det

    Matrix m(this->size);
    for (int i{0}; i < this->size; i++) {
        for (int j{0}; j < this->size; j++) {
            float cofactor = this->cofactor(i, j);
            m[j][i] = cofactor / det;
        }
    }
    return m;
}

bool equal(Matrix a, Matrix b) {
    if (a.size != b.size) {
        return false;
    } else {
        for (int i{0}; i < a.size; i++) {
            for (int j{0}; j < a.size; j++) {
                if (!equal(a[i][j], b[i][j])) {
                    return false;
                } 
            }
        }
    return true;
    }
}