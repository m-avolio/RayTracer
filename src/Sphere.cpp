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

Vector Sphere::normal_at(Point world_point) {
    Point object_point = this->transform.inverse() * world_point;
    Vector object_normal = object_point - Point();
    Vector world_normal = this->transform.inverse().transpose() * object_normal;
    world_normal.w = 0;
    return norm(world_normal);
}
