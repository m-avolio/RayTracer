#ifndef MATERIAL_H
#define MATERIAL_H
#include "Colour.h"

struct Material {
    Material(Colour colour, float ambient, float diffuse, float specular, float shininess): 
             colour{colour}, ambient{ambient}, diffuse{diffuse}, specular{specular}, shininess{shininess} {}
    Material(): colour{Colour{1,1,1}}, ambient{0.1}, diffuse{0.9}, specular{0.9}, shininess{200} {}
    Colour colour;
    float ambient; // typical values between 0 and 1
    float diffuse; // typical values between 0 and 1
    float specular; // typical values between 0 and 1
    float shininess; // typing values between 10 (very large) and 200 (very small)
};   

#endif