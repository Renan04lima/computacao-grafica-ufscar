/**
 * @file main.cpp
 * @author Renan Oliveira de Barros Lima
 * @brief Programa principal, onde é feita a visualização da esfera, triangulo e objeto como todo.
 */

#include "../Atividade01/includes/ImageIO.h"
#include "../Atividade01/includes/ImageIO.cpp"
#include "../Atividade02/includes/color.h"
#include "../Atividade02/includes/vec3.h"
#include "../Atividade02/includes/vec3.cpp"
#include "includes/ray.h"

#include <iostream>
#include <vector>
bool hit_sphere(const point3 &center, double radius, const ray &r) {
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius * radius;
    auto discriminant = b * b - 4 * a * c;
    return (discriminant >= 0);
}

bool hit_triangle(const point3& vertex0, const point3& vertex1, const point3& vertex2, const ray& r) {
    vec3 e1 = vertex1 - vertex0;
    vec3 e2 = vertex2 - vertex0;
    vec3 h = cross(r.direction(), e2);
    double a = dot(e1, h);

    if (a > -1e-6 && a < 1e-6)
        return false;

    double f = 1.0 / a;
    vec3 s = r.origin() - vertex0;
    double u = f * dot(s, h);

    if (u < 0.0 || u > 1.0)
        return false;

    vec3 q = cross(s, e1);
    double v = f * dot(r.direction(), q);

    if (v < 0.0 || u + v > 1.0)
        return false;

    double t = f * dot(e2, q);

    return (t > 0.0001);
}
    

color ray_color(const ray &r, std::string type) {
    if (type == "sphere") {
        if (hit_sphere(point3(0, 0, -1), 0.5, r)) {
            return color(1, 0, 0);
        }
    } else if (type == "triangle") {
        point3 v0(-0.5, -0.5, -1.0);
        point3 v1(0.5, -0.5, -1.0);
        point3 v2(0, 0.5, -1.0);

        if (hit_triangle(v0, v1, v2, r)) {
            return color(1, 0, 0);
        }
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main() {
    // visualização da esfera

    // const int image_width = 200;
    // const int image_height = 100;
    point3 origin(0.0, 0.0, 0.0);
    point3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);

    // Image

    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Calculate the image height, and ensure that it's at least 1.
    int image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera

    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);
    auto camera_center = point3(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel.
    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    std::vector<unsigned char> image_data = std::vector<unsigned char>(image_width * image_height * 4);

    // Visualização da esfera
    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r, "sphere");

            // Mapeie a cor para valores de 0 a 255 e adicione ao vetor image_data
            image_data[(i + j * image_width) * 4] = static_cast<unsigned char>(255.999 * pixel_color.x());
            image_data[(i + j * image_width) * 4 + 1] = static_cast<unsigned char>(255.999 * pixel_color.y());
            image_data[(i + j * image_width) * 4 + 2] = static_cast<unsigned char>(255.999 * pixel_color.z());
            image_data[(i + j * image_width) * 4 + 3] = 255;  // Alpha (totalmente opaco)
        }
    }
    ImageIO sphereIO(image_width, image_height, image_data);

    sphereIO.save_png("outputs/sphere.png");

    // Visualização do triangulo
    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r, "triangle");

            // Mapeie a cor para valores de 0 a 255 e adicione ao vetor image_data
            image_data[(i + j * image_width) * 4] = static_cast<unsigned char>(255.999 * pixel_color.x());
            image_data[(i + j * image_width) * 4 + 1] = static_cast<unsigned char>(255.999 * pixel_color.y());
            image_data[(i + j * image_width) * 4 + 2] = static_cast<unsigned char>(255.999 * pixel_color.z());
            image_data[(i + j * image_width) * 4 + 3] = 255;  // Alpha (totalmente opaco)
        }
    }

    ImageIO triangleIO(image_width, image_height, image_data);

    triangleIO.save_png("outputs/triangle.png");

    // Visualização do objeto

    return 0;
}