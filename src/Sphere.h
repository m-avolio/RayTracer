#ifndef SPHERE_H
#define SPHERE_H
#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include "Shape.h"

class Sphere: public Shape {
    public:
        Sphere(){}
        Intersections intersect(Ray ray);
        Vector normal_at(Point world_point);
};

#endif