#ifndef TUPLE_H
#define TUPLE_H

#include <cmath>
#define EPSILON 0.0001

class Tuple {
    public:
        float x, y, z, w;
        Tuple() {};
        Tuple(float x, float y, float z, float w): x{x}, y{y}, z{z}, w{w} {} 
        Tuple operator+(const Tuple &b);
        Tuple operator-(const Tuple &b);
        Tuple operator-();
        Tuple operator*(const float &b);
        Tuple operator/(const float &b);
};

class Point;
class Vector;

class Point: public Tuple {
    public:
        Point(float x, float y, float z);
        Point();
        Point operator+(const Vector &b);
        Vector operator-(const Point &b);
        Point operator-(const Vector &b);
        Point operator-();
};

class Vector: public Tuple {
    public:
        Vector(float x, float y, float z);
        Vector();
        Point operator+(const Point &b);
        Vector operator+(const Vector &b);
        Vector operator-(const Vector &b);
        Vector operator*(const float &b);
        Vector operator/(const float &b);
        Vector operator-();
};

bool equal(const float &a, const float &b);

bool equal(const Tuple &a, const Tuple &b);

float magnitude(const Vector &v);

Vector norm(const Vector &v);

Vector cross(const Vector &a, const Vector &b);

float dot(const Vector &a, const Vector &b);

#endif