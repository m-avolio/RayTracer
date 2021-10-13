#ifndef RAY_H
#define RAY_H
#include "Tuple.h"

class Ray {
    public:
        Ray(Point origin, Vector direction);
        Point origin;
        Vector direction;
        Point position(float distance);

};

#endif