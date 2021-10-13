#include "Ray.h"

Ray::Ray(Point origin, Vector direction): origin{origin}, direction{direction} {}

Point Ray::position(float distance) {
    return this->origin + this->direction*distance;
}