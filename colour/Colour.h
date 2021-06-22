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

#endif