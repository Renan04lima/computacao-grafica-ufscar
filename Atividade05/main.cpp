/**
 * @file main.cpp
 * @author Renan Oliveira de Barros Lima
 * @brief Programa principal, onde é feita a visualização da cena com dois tipos de câmeras.
 */

#include "./includes/utils.h"
#include "./includes/camera.h"
#include "./includes/color.h"
#include "./includes/hittable_list.h"
#include "./includes/material.h"
#include "./includes/sphere.h"
#include "./includes/triangle.h"
#include "../Atividade03/includes/ObjLoader.h"
#include "../Atividade03/includes/ObjLoader.cpp"

#include <vector>

int main() {
    hittable_list world;

    std::cout << "Criando o chão..." << std::endl;
    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));
    std::cout << "Criando o chão..." << std::endl;

    ObjLoader obj;
    obj.LoadObj("/Users/renanoliveira/Desktop/ufscar/2023-02/computacao-grafica/atividades-projeto/Atividade05/cube.obj");
    auto cube_material = make_shared<lambertian>(color(0.9, 0.1, 0.3));

    std::cout << "Processando as faces do cubo..." << std::endl;
    std::vector<triangle> triangles_list = obj.get_triangle_faces(cube_material);
    for (int i = 0; i < triangles_list.size(); i++) {
        // ajuste de coordenadas do cubo (arquivo obj) de forma a melhor posicioná-lo na cena:
        vertex v0 = triangles_list[i].A;
        v0.coord = v0.coord.operator+=(point3(0, 1, 0));

        vertex v1 = triangles_list[i].B;
        v1.coord = v1.coord.operator+=(point3(0, 1, 0));

        vertex v2 = triangles_list[i].C;
        v2.coord = v2.coord.operator+=(point3(0, 1, 0));

        world.add(make_shared<triangle>(v0, v1, v2, triangles_list[i].mat));
    }

    auto material1 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

    auto material2 = make_shared<lambertian>(color(1, 0.7, 0.5));
    world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

    camera cam1;

    cam1.aspect_ratio = 16.0 / 9.0;
    cam1.image_width = 500;
    cam1.samples_per_pixel = 10;
    cam1.max_depth = 20;

    cam1.vfov = 30;
    cam1.lookfrom = point3(0, 5, 20);
    cam1.lookat = point3(0, 0, 0);
    cam1.vup = vec3(0, 1, 0);

    cam1.defocus_angle = 0.6;
    cam1.focus_dist = 10.0;

    std::cout << "Rendering cam1..." << std::endl;
    cam1.render(world, "outputs/cam1.png");

    camera cam2;

    cam2.aspect_ratio      = 16.0 / 9.0;
    cam2.image_width       = 500;
    cam2.samples_per_pixel = 10;
    cam2.max_depth         = 20;

    cam2.vfov     = 30;
    cam2.lookfrom = point3(0,4,14);
    cam2.lookat   = point3(0,0,0);
    cam2.vup      = vec3(0,1,0);

    cam2.defocus_angle = 0.6;
    cam2.focus_dist    = 10.0;

    std::cout << "Rendering cam2..." << std::endl;
    cam2.render(world, "outputs/cam2.png");
}