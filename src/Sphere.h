#ifndef SPHERE_H
#define SPHERE_H
#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include "Tuple.h"
#include "Shape.h"

class Sphere: public Shape {
    public:
        Sphere(){}
        Intersections intersect(Ray ray);
        Matrix transform = IDENTITY;
};

#endif