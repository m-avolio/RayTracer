#include "Tuple.h"

Tuple Tuple::operator+(const Tuple &b) {
    Tuple tuple;
    tuple.x = this->x + b.x;
    tuple.y = this->y + b.y;
    tuple.z = this->z + b.z;
    tuple.w = this->w + b.w;
    return tuple;
}

Tuple Tuple::operator-(const Tuple &b) {
    Tuple tuple;
    tuple.x = this->x - b.x;
    tuple.y = this->y - b.y;
    tuple.z = this->z - b.z;
    tuple.w = this->w - b.w;
    return tuple;
}

Tuple Tuple::operator-() {
    Tuple tuple;
    tuple.x = -this->x;
    tuple.y = -this->y;
    tuple.z = -this->z;
    tuple.w = -this->w;
    return tuple;
}

Tuple Tuple::operator*(const float &b) {
    Tuple tuple;
    tuple.x = this->x * b;
    tuple.y = this->y * b;
    tuple.z = this->z * b;
    tuple.w = this->w * b;
    return tuple;
}

Tuple Tuple::operator/(const float &b) {
    Tuple tuple;
    tuple.x = this->x / b;
    tuple.y = this->y / b;
    tuple.z = this->z / b;
    tuple.w = this->w / b;
    return tuple;
}

Point::Point(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = 1;
}

Point::Point() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 1;
}

Point Point::operator+(const Vector &b) {
    Point point;
    point.x = this->x + b.x;
    point.y = this->y + b.y;
    point.z = this->z + b.z;
    point.w = this->w + b.w;
    return point;
}

Vector Point::operator-(const Point &b) {
    Vector vector;
    vector.x = this->x - b.x;
    vector.y = this->y - b.y;
    vector.z = this->z - b.z;
    vector.w = this->w - b.w;
    return vector;
}

Point Point::operator-(const Vector &b) {
    Point point;
    point.x = this->x - b.x;
    point.y = this->y - b.y;
    point.z = this->z - b.z;
    point.w = this->w - b.w;
    return point;
}

Point Point::operator-() {
    Point point;
    point.x = -this->x;
    point.y = -this->y;
    point.z = -this->z;
    point.w = -this->w;
    return point;
}

Vector::Vector(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = 0;
}

Vector::Vector() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 0;
}

Point Vector::operator+(const Point &b) {
    Point point;
    point.x = this->x + b.x;
    point.y = this->y + b.y;
    point.z = this->z + b.z;
    point.w = this->w + b.w;
    return point;
}

Vector Vector::operator+(const Vector &b) {
    Vector vector;
    vector.x = this->x + b.x;
    vector.y = this->y + b.y;
    vector.z = this->z + b.z;
    vector.w = this->w + b.w;
    return vector;
}

Vector Vector::operator-(const Vector &b) {
    Vector vector;
    vector.x = this->x - b.x;
    vector.y = this->y - b.y;
    vector.z = this->z - b.z;
    vector.w = this->w - b.w;
    return vector;
}

Vector Vector::operator*(const float &b) {
    Vector vector;
    vector.x = this->x * b;
    vector.y = this->y * b;
    vector.z = this->z * b;
    vector.w = this->w * b;
    return vector;
}

Vector Vector::operator/(const float &b) {
    Vector vector;
    vector.x = this->x / b;
    vector.y = this->y / b;
    vector.z = this->z / b;
    vector.w = this->w / b;
    return vector;
}

Vector Vector::operator-() {
    Vector vector;
    vector.x = -this->x;
    vector.y = -this->y;
    vector.z = -this->z;
    vector.w = -this->w;
    return vector;
}

// Helper Functions
Vector norm(const Vector &v) {
    Vector vector;
    float mag = magnitude(v);
    vector.x = v.x / mag;
    vector.y = v.y / mag;
    vector.z = v.z / mag;
    vector.w = v.w / mag;
    return vector;
}

float magnitude(const Vector &v) {
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
}

float dot(const Vector &a, const Vector &b) {
     return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w; 
}

Vector cross(const Vector &a, const Vector &b) {
    return Vector(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

bool equal(const float &a, const float &b) {
   if (abs(a-b) < EPSILON) {
       return true;
   } else {
       return false;
   } 
}

bool equal(const Tuple &a, const Tuple &b) {
    if (equal(a.x, b.x) && equal(a.y, b.y) && equal(a.z, b.z) && equal(a.w, b.w)) {
        return true;
    } else {
        return false;
    }
}

