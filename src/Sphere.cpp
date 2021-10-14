#include "Sphere.h"

std::vector<Intersection> Sphere::intersect(Ray ray, Intersections *i) {
    std::vector<Intersection> output;
    Vector sphereToRay = ray.origin - Point();
    float a = dot(ray.direction, ray.direction);
    float b = 2*dot(ray.direction, sphereToRay);
    float c = dot(sphereToRay, sphereToRay) - 1;
    float discriminant = b*b - 4*a*c;
    if (discriminant >= 0) {
        output.push_back(Intersection((-b - sqrt(discriminant))/(2*a), this));
        output.push_back(Intersection((-b + sqrt(discriminant))/(2*a), this));
        if (i != NULL) {
            i->put(output[0]);
            i->put(output[1]);
        }
    }
    return output;
}