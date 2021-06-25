#include "Colour.h"

Colour Colour::operator+(const Colour &b) {
    Colour colour;
    colour.red = this->red + b.red;
    colour.green = this->green + b.green;
    colour.blue = this->blue + b.blue;
    return colour;
}

Colour Colour::operator-(const Colour &b) {
    Colour colour;
    colour.red = this->red - b.red;
    colour.blue = this->blue - b.blue;
    colour.green = this->green - b.green;
    return colour;
}

Colour Colour::operator*(const float &b) {
    Colour colour;
    colour.red = this->red * b;
    colour.blue = this->blue * b;
    colour.green = this->green * b;
    return colour;
}

Colour Colour::operator*(const Colour &b) {
    Colour colour;
    colour.red = this->red * b.red;
    colour.blue = this->blue * b.blue;
    colour.green = this->green * b.green;
    return colour;
}
