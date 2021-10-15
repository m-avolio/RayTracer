#include "Shape.h"

Vector reflect(Vector in, Vector normal) {
    return in - normal * 2 * dot(in, normal);
}
