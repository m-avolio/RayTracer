#include "Sphere.h"

Intersections Sphere::intersect(Ray ray) {
    Intersections output;
    Ray transformed = ray.transform(this->transform.inverse());
    Vector sphereToRay = transformed.origin - Point();
    float a = dot(transformed.direction, transformed.direction);
    float b = 2*dot(transformed.direction, sphereToRay);
    float c = dot(sphereToRay, sphereToRay) - 1;
    float discriminant = b*b - 4*a*c;
    if (discriminant >= 0) {
        output.put(Intersection((-b - sqrt(discriminant))/(2*a), this));
        output.put(Intersection((-b + sqrt(discriminant))/(2*a), this));
    }
    return output;
}