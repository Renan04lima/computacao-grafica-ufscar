/**
 * @file main.cpp
 * @author Renan Oliveira de Barros Lima
 * @brief Programa principal, onde é feita a visualização da esfera, triangulo e objeto como todo.
 */

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

color ray_color(const ray &r) {
    if (hit_sphere(point3(0, 0, -1), 0.5, r))
        return color(1, 0, 0);

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

    // Render

    std::cout << "P3\n"
              << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    // std::cout << "P3\n"
    //           << image_width << ' ' << image_height << "\n255\n";

    // for (int j = image_height - 1; j >= 0; --j) {
    //     std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    //     for (int i = 0; i < image_width; ++i) {
    //         auto u = double(i) / (image_width - 1);
    //         auto v = double(j) / (image_height - 1);
    //         ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
    //         color pixel_color = ray_color(r);
    //         write_color(std::cout, pixel_color);
    //     }
    // }

    // std::cerr << "\nDone.\n";

    // classe de visualização do triangulo

    // classe de visualização do objeto

    return 0;
}