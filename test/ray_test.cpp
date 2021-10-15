#include "Ray.h"
#include "Sphere.h"
#include "Shape.h"
#include "Canvas.h"
#include "Colour.h"
#include "Light.h"
#include <iostream>
#include <cassert>

// void old_tests() {
//     // computing point from a distance
//     Ray ray(Point(2,3,4), Vector(1,0,0));
//     assert(equal(ray.position(2.5), Point(4.5,3,4)));
//     // intersections with sphere
//     // two points
//     ray.origin = Point(0, 0, -5);
//     ray.direction = Vector(0, 0, 1);
//     Sphere sphere;
//     std::vector<Intersection> x = sphere.intersect(ray);
//     assert(x[0].t == 4.0 && x[1].t == 6.0);
//     // intersects at tangent
//     ray.origin = Point(0, 1, -5);
//     x.clear();
//     x = sphere.intersect(ray);
//     assert(x[0].t == 5.0 && x[1].t == 5.0);
//     assert(x[0].object == &sphere);
//     // no intersection
//     ray.origin = Point(0, 2, -5);
//     x.clear();
//     x = sphere.intersect(ray);
//     assert(x.size() == 0);
//     // test hit
//     Intersections intersections;
//     intersections.put(Intersection(5, &sphere));
//     intersections.put(Intersection(-7, &sphere));
//     intersections.put(Intersection(1, &sphere));
//     intersections.put(Intersection(2, &sphere));
//     Intersection final = *intersections.hit();
//     assert(final.t == 1);
//     // Translation
//     ray = Ray(Point(1,2,3), Vector(0,1,0));
//     ray = ray.transform(translation(3,4,5));
//     assert(equal(ray.origin, Point(4,6,8)));
//     assert(equal(ray.direction, Vector(0,1,0)));
//     // Scaling a ray
//     ray = Ray(Point(1,2,3), Vector(0,1,0));
//     ray = ray.transform(scaling(2, 3, 4));
//     assert(equal(ray.origin, Point(2,6,12)));
//     assert(equal(ray.direction, Vector(0,3,0)));
//     // Scaling a sphere
//     ray = Ray(Point(0, 0, -5), Vector(0, 0, 1));
//     sphere = Sphere();
//     sphere.transform = scaling(2, 2, 2);
//     x.clear();
//     x = sphere.intersect(ray);
//     //assert(x[0].t == 3 && x[1].t == 7);
//     // translated sphere
//     sphere.transform = translation(5, 0, 0);
//     x.clear();
//     x = sphere.intersect(ray);
//     assert(x.size() == 0);
// }

void creating_circle() {
    //creating a circle
    Point ray_origin(0, 0, -5);
    int wall_z = 10;
    float wall_size = 7.0;
    int canvas_pixels = 200;
    float pixel_size = wall_size / canvas_pixels;
    float half = wall_size / 2;
    Canvas canvas(canvas_pixels, canvas_pixels);
    Colour red = RED;
    Sphere sphere;
    sphere.transform = shearing(1, 0, 0, 0, 1, 0) * scaling(0.5, 1, 1); 
    for (int y{0}; y < canvas_pixels; y++) {
        float world_y = half - pixel_size * y;
        for (int x{0}; x < canvas_pixels; x++) {
            float world_x = -half + pixel_size * x;
            Point position(world_x, world_y, wall_z);
            Ray ray(ray_origin, norm(position-ray_origin));
            Intersections inter = sphere.intersect(ray);
            if (inter.hit() != NULL) {
                canvas.write_pixel(x, y, red);
            }
        }
    }
    canvas.to_ppm("circle");
}


void render_sphere() {
    //creating a circle
    Point ray_origin(0, 0, -5);
    int wall_z = 10;
    float wall_size = 7.0;
    int canvas_pixels = 800;
    float pixel_size = wall_size / canvas_pixels;
    float half = wall_size / 2;
    Canvas canvas(canvas_pixels, canvas_pixels);
    Sphere sphere;
    sphere.material.colour = Colour(0.2, 0.733, 0.941);
    Light light(Point(-10, 10, -10), Colour(1, 1, 1));
    for (int y{0}; y < canvas_pixels; y++) {
        float world_y = half - pixel_size * y;
        for (int x{0}; x < canvas_pixels; x++) {
            float world_x = -half + pixel_size * x;
            Point position(world_x, world_y, wall_z);
            Ray ray(ray_origin, norm(position-ray_origin));
            Intersections intersections = sphere.intersect(ray);
            Intersection *hit = intersections.hit();
            if (hit != NULL) {
                Point point = ray.position(hit->t);
                Vector normal = hit->object->normal_at(point);
                Vector eye = -ray.direction;
                Colour colour = lighting(hit->object->material, light, point, eye, normal);
                canvas.write_pixel(x, y, colour);
            }
        }
    }
    canvas.to_ppm("sphere");
}

int main() {
    // computing normal on translated sphere
    Sphere s;
    s.transform = translation(0, 1, 0);
    assert(equal(s.normal_at(Point(0, 1.70711,-0.70711)), Vector(0, 0.70711, -0.70711)));
    // lighting test
    Vector eyev(0, 0, -1);
    Vector normalv(0, 0, -1);
    Light light(Point(0, 10, -10), Colour(1, 1, 1));
    Colour result = lighting(Material(), light, Point(0, 0, 0), eyev, normalv);
    assert(equal(result.red, 0.7364));
    render_sphere();
    std::cout << "ALL TESTS PASSED" << std::endl;
    return 0;
}