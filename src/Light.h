#ifndef LIGHT_H
#define LIGHT_H
#include "Tuple.h"
#include "Colour.h"
#include "Material.h"
#include "Shape.h"
#include <cmath>

class Light {
    public:
        Light(Point position, Colour intensity): position{position}, intensity{intensity} {}
        Light() {}
        Point position;
        Colour intensity = Colour(1, 1, 1);
};

Colour lighting(Material material, Light light, Point point, Vector eye, Vector normal);
#endif