#include "Ray.h"

Ray::Ray(Point origin, Vector direction): origin{origin}, direction{direction} {}

Point Ray::position(float distance) {
    return this->origin + this->direction*distance;
}

Intersection *Intersections::hit() {
    while(!queue.empty()) {
        Intersection i = queue.top();
        queue.pop();
        if (i.t >= 0) {
            Intersection *output = new Intersection(i.t, i.object);
            return output;
        }
    }
    return NULL;
}

void Intersections::put(Intersection inter) {
    queue.push(inter);
}

void Intersections::clear() {
    std::priority_queue<Intersection, std::vector<Intersection>, Compare> empty;
    std::swap(queue, empty );
}