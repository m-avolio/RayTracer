#include "Ray.h"
#include <iostream>
#include <cassert>

int main() {
    //computing point from a distance
    Ray ray(Point(2,3,4), Vector(1,0,0));
    assert(equal(ray.position(2.5), Point(4.5,3,4)));

    std::cout << "ALL TESTS PASSED" << std::endl;
    return 0;
}