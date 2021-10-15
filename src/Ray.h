#ifndef RAY_H
#define RAY_H
#include <queue>
#include "Tuple.h"
#include "Matrix.h"

class Shape;

class Ray {
    public:
        Ray(Point origin, Vector direction);
        Ray() {}
        Point origin;
        Vector direction;
        Point position(float distance);
        Ray transform(Matrix m);
};

struct Intersection {
    Intersection(float t, Shape *object): t{t}, object{object} {}
    float t;
    Shape *object;
};

struct Compare {
    bool operator()(Intersection const& i1, Intersection const& i2) {
        return i1.t > i2.t;
    }
};

class Intersections {
    public:
        Intersections() {}
        Intersection *hit();
        void put(Intersection inter);
        void clear();
    private:
        std::priority_queue<Intersection, std::vector<Intersection>, Compare> queue;
};

#endif