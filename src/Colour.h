#ifndef COLOUR_H
#define COLOUR_H

struct Colour {
    float red, green, blue;
    Colour(float red, float green, float blue): red{red}, green{green}, blue{blue} {}
    Colour(): red{0}, green{0}, blue{0} {}
    Colour operator+(const Colour &b);
    Colour operator-(const Colour &b);
    Colour operator*(const float &b);
    Colour operator*(const Colour &b);
};

const Colour RED(1, 0, 0);
const Colour GREEN(0, 1, 0);
const Colour BLUE(0, 0, 1);
const Colour BLACK(0, 0, 0);

#endif