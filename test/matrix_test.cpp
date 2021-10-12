#include "Matrix.h"
#include <iostream>
#include <cassert>

int main() {
    //creating a matrix
    Matrix m(3);
    m.init({{1,2,3}, 
            {1,2,3}, 
            {1,2,3}});
    m.print();
    //multiplying matrixes 
    Matrix a(4), b(4), c(4);
    a.init({{1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 8, 7, 6},
            {5, 4, 3, 2}});
    b.init({{-2, 1, 2, 3},
            {3, 2, 1, -1},
            {4, 3, 6, 5},
            {1, 2, 7, 8}});
    c.init({{20, 22, 50, 48},
            {44, 54, 114, 108},
            {40, 58, 110, 102},
            {16, 26, 46, 42}});
    assert(equal(c, a*b));
    //matrix by identity
    assert(equal(c, c*IDENTITY));
    //transpose
    assert(equal(IDENTITY.transpose(), IDENTITY));
    //mulitplying matrix by tuple
    Tuple tuple(1, 2, 3, 1);
    a.init({{1, 2, 3, 4},
            {2, 4, 4, 2},
            {8, 6, 4, 1},
            {0, 0, 0, 1}});
    assert(equal(a*tuple, Tuple(18, 24, 33, 1)));
    std::cout << "ALL TESTS PASSED" << std::endl;
    return 0;
}