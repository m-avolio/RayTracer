#include "Tuple.h"
#include <cassert>
#include <iostream>

int main() {
    float x{4.482}; 
    float y{4.482};
    float z{12.321};
    assert(equal(x, y) == true);
    assert(equal(x, z) == false);

    Tuple a(1, 2, 3, 0);
    Vector b(1, 2, 3);
    Point c(1, 2, 3);
    assert(equal(a, b) == true);
    assert(equal(b, c) == false);

    Tuple a1(3, -2, 5, 1);
    Tuple a2(-2, 3, 1, 0);
    assert(equal(Tuple(1, 1, 6, 1), a1 + a2));

    Point p1(3, 2, 1);
    Point p2(5, 6, 7);
    assert(equal(Vector(-2, -4, -6), p1 - p2));
    
    Vector v1(5, 6, 7);
    assert(equal(Point(-2, -4, -6), p1 - v1));
    Vector v2(3, 2, 1);
    assert(equal(Vector(-2, -4, -6), v2 - v1));

    Vector zero(0, 0, 0);
    v1 = Vector(1, -2, 3);
    assert(equal(Vector(-1, 2, -3), zero - v1));

    a = Tuple(1, -2, 3, -4);
    assert(equal(Tuple(-1, 2, -3, 4), -a));

    std::cout << ("ALL TESTS PASSED") << std::endl;
    return 0;
}