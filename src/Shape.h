#ifndef SHAPE_H
#define SHAPE_H
#include "Ray.h"
    
class Shape {
    public:
        Shape(){}
        std::vector<Intersection> intersect(Ray ray, Intersections *i=NULL);
};

#endif