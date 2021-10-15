#ifndef SHAPE_H
#define SHAPE_H
#include "Ray.h"
#include "Tuple.h"
#include "Colour.h"
#include "Material.h"

class Shape {
    public:
        Shape() {}
        virtual ~Shape() {}
        virtual Intersections intersect(Ray ray)=0;
        virtual Vector normal_at(Point world_point)=0;
        Matrix transform = IDENTITY;
        Material material;
};

Vector reflect(Vector in, Vector normal);

#endif