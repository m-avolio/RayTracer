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
    //determinant of 2x2 matrix
    Matrix d(2);
    d.init({{1, 5},
            {-3, 2}});
    assert(d.determinant() == 17);
    //submatrix
    Matrix e(3);
    e.init({{1, 3, 5},
            {4, 5, 12},
            {-3, 44, 2}});
    assert(equal(d, e.submatrix(1, 1)));
    //cofactor 
    assert(-44 == e.cofactor(0,1));
    //determinant of 4x4 matrix
    a.init({{6, 4, 4, 4},
            {5, 5, 7, 6},
            {4, -9, 3, -7},
            {9, 1, 7, -6}});
    assert(-2120 == a.determinant());
    //inverting a matrix
    a.init({{8, -5, 9, 2},
            {7, 5, 6, 1},
            {-6, 0, 9, 6},
            {-3, 0, -9, -4}});
    Matrix inv(4);
    inv.init({{-0.15385, -0.15385, -0.28205, -0.53846},
              {-0.07692, 0.12308, 0.02564, 0.03077},
              {0.35897, 0.35897, 0.43590, 0.92308},
              {-0.69231, -0.69231, -0.76923, -1.92308}});
    assert(equal(inv, a.inverse()));
    assert(equal(a, (a*b)*(b.inverse())));
    //translating a point
    Point p(-3, 4, 5);
    assert(equal(Point(2, 1, 7), translation(5, -3, 2)*p));
    std::cout << "ALL TESTS PASSED" << std::endl;
    //X rotation
    p = Point(0, 1, 0);
    assert(equal(Point(0, sqrt(2)/2, sqrt(2)/2), rotationX(PI/4)*p));
    //Y rotations
    p = Point(0, 0, 1);
    assert(equal(Point(sqrt(2)/2, 0, sqrt(2)/2), rotationX(PI/4)*p));
    //Z rotations
    p = Point(0, 1, 0);
    assert(equal(Point(-sqrt(2)/2, sqrt(2)/2, 0), rotationX(PI/4)*p));
    //shearing
    p = Point(2, 3, 4);
    assert(equal(Point(5, 3, 4), shearing(1, 0, 0, 0, 0, 0)*p));
    return 0;
}