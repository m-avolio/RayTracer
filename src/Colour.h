#ifndef COLOUR_H
#define COLOUR_H

#define RED Colour(1, 0, 0)
#define BLUE Colour(0, 1, 0)
#define GREEN Colour(0, 0, 1)

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