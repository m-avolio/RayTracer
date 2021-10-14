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
        std::vector<Intersection> intersect(Ray ray, Intersections *i=NULL);
};

#endif