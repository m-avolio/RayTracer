#include "Canvas.h"

Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;

    std::vector<std::vector<Colour>> temp(width, std::vector<Colour>(height, Colour()));
    pixels = temp;
}

void Canvas::write_pixel(int x, int y, Colour c) {
    pixels[x][y] = c;
}

Colour Canvas::read_pixel(int x, int y) {
    return pixels[x][y];
}

void Canvas::to_ppm(std::string name) {
    std::ofstream outfile (name + ".ppm");
    outfile << "P3" << std::endl;
    outfile << width << " " << height << std::endl;
    outfile << "255" << std::endl;
    for (int i{0}; i < height; ++i) {
        for (int j{0}; j < width; ++j) {
            Colour pixel = pixels[j][i];
            int red = (pixel.red > 1) ? 255 : 
                      (pixel.red < 0) ? 0 : round(255*pixel.red);
            int green = (pixel.green > 1) ? 255 : 
                        (pixel.green < 0) ? 0 : round(255*pixel.green);
            int blue = (pixel.blue > 1) ? 255 : 
                       (pixel.blue < 0) ? 0 : round(255*pixel.blue);
            outfile << red << " " <<  green << " " << blue << " ";
            if (j % 5 == 0) {
                outfile << std::endl;
            }
        }
        outfile << std::endl;
    }
}