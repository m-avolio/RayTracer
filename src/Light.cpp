#include "Light.h"

Colour lighting(Material material, Light light, Point point, Vector eye, Vector normal) {
    Colour ambient;
    Colour diffuse;
    Colour specular;

    Colour effective_colour = material.colour * light.intensity;
    Vector lightv = norm(light.position - point);
    ambient = effective_colour * material.ambient;
    float light_dot_normal = dot(lightv, normal);
    if (light_dot_normal >= 0) {
        diffuse = effective_colour * material.diffuse * light_dot_normal;
        Vector reflectv = reflect(-lightv, normal);
        float reflect_dot_eye = dot(reflectv, eye);
        if (reflect_dot_eye > 0) {
            float factor = pow(reflect_dot_eye, material.shininess);
            specular = light.intensity * material.specular * factor;
        }
    }
    return ambient + diffuse + specular;
} 
