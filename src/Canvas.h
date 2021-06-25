#ifndef CANVAS_H
#define CANVAS_H
#include "Colour.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

class Canvas {
    public:
        Canvas(int width, int height);
        void write_pixel(int x, int y, Colour c);
        Colour read_pixel(int x, int y);
        void to_ppm(std::string name);
    private:
        int width;
        int height;
        std::vector<std::vector<Colour>> pixels;
};

#endif