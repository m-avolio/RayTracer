#ifndef TUPLE_H
#define TUPLE_H

#include <cmath>
#define EPSILON 0.00001

struct Tuple {
    float x, y, z, w;
    Tuple() {};
    Tuple(float x, float y, float z, float w): x{x}, y{y}, z{z}, w{w} {} 
    Tuple operator+(const Tuple &b);
    Tuple operator-(const Tuple &b);
    Tuple operator-();
    Tuple operator*(const float &b);
    Tuple operator/(const float &b);
};

struct Point: public Tuple {
    Point(float x, float y, float z);
};

struct Vector: public Tuple {
    Vector(float x, float y, float z);
};

bool equal(const float &a, const float &b);

bool equal(const Tuple &a, const Tuple &b);

float magnitude(const Vector &v);

void normalize(Vector &v);

float dot(const Vector &a, const Vector &b);

#endif