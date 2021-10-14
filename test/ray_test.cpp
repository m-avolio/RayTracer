#include "Ray.h"
#include "Sphere.h"
#include <iostream>
#include <cassert>

int main() {
    // computing point from a distance
    Ray ray(Point(2,3,4), Vector(1,0,0));
    assert(equal(ray.position(2.5), Point(4.5,3,4)));
    // intersections with sphere
    // two points
    ray.origin = Point(0, 0, -5);
    ray.direction = Vector(0, 0, 1);
    Sphere sphere;
    std::vector<Intersection> x = sphere.intersect(ray);
    assert(x[0].t == 4.0 && x[1].t == 6.0);
    // intersects at tangent
    ray.origin = Point(0, 1, -5);
    x.clear();
    x = sphere.intersect(ray);
    assert(x[0].t == 5.0 && x[1].t == 5.0);
    assert(x[0].object == &sphere);
    // no intersection
    ray.origin = Point(0, 2, -5);
    x.clear();
    x = sphere.intersect(ray);
    assert(x.size() == 0);
    // test hit
    Intersections intersections;
    intersections.put(Intersection(5, &sphere));
    intersections.put(Intersection(-7, &sphere));
    intersections.put(Intersection(1, &sphere));
    intersections.put(Intersection(2, &sphere));
    Intersection final = *intersections.hit();
    assert(final.t == 1);
    std::cout << "ALL TESTS PASSED" << std::endl;
    return 0;
}