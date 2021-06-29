#include "Canvas.h"

int main() {
    Canvas c(5, 3);
    c.write_pixel(0, 0, Colour(1.5, 0.39, 0.1));
    c.write_pixel(2, 1, Colour(0.8, 0.5, 1));
    c.write_pixel(4, 2, Colour(-0.5, 0, 1));
    c.write_pixel(0, 1, RED);
    c.to_ppm("test");
    return 0;
}