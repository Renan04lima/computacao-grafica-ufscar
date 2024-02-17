/**
 * @file main.cpp
 * @author Carlos Daniel, Martin Adam e Renan Oliveira.
 * @brief Programa principal, onde é gerado os frames da animação.
 */

#include <vector>
#include <iostream>
#include <string>
#include <cmath>

#include "../Atividade05/includes/utils.h"
#include "../Atividade02/includes/vec3.h"
#include "../Atividade03/includes/ObjLoader.h"
#include "../Atividade03/includes/ObjLoader.cpp"
#include "../Atividade05/includes/camera.h"
#include "../Atividade05/includes/color.h"
#include "../Atividade05/includes/hittable_list.h"
#include "../Atividade05/includes/material.h"
#include "../Atividade05/includes/sphere.h"
#include "../Atividade05/includes/triangle.h"

using std::make_shared;
using std::vector;

int main() {
    // Configuração da câmera
    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 500;
    cam.samples_per_pixel = 10;
    cam.max_depth = 20;

    cam.vfov = 30;
    cam.lookfrom = point3(0, 5, 20);
    cam.lookat = point3(0, 0, 0);
    cam.vup = vec3(0, 1, 0);

    cam.defocus_angle = 0.6;
    cam.focus_dist = 10.0;

    // Loop para gerar frames da animação
    for (int frame = 0; frame < 50; frame++) {
        // Lista de objetos na cena
        hittable_list world;

        // Adicionando plano como "chão"
        auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
        world.add(make_shared<sphere>(point3(0, -1000, 0), 1000, ground_material));

        // Carregando objeto 3D do arquivo .obj
        ObjLoader obj;
        obj.LoadObj("/Users/renanoliveira/Desktop/ufscar/2023-02/computacao-grafica/atividades-projeto/ProjetoFinal/cube.obj");
        auto cube_material = make_shared<metal>(color(0.9, 0.1, 0.3), 0.2);

        // Criando triângulos a partir das faces do objeto 3D
        vector<triangle> triangles_list = obj.get_triangle_faces(cube_material);
        for (int i = 0; i < triangles_list.size(); i++) {
            vertex v0 = triangles_list[i].A;
            v0.coord = v0.coord.operator+=(point3(0, 1, 0));

            vertex v1 = triangles_list[i].B;
            v1.coord = v1.coord.operator+=(point3(0, 1, 0));

            vertex v2 = triangles_list[i].C;
            v2.coord = v2.coord.operator+=(point3(0, 1, 0));
            world.add(make_shared<triangle>(v0, v1, v2, triangles_list[i].mat));
        }

        // Adicionando esfera com material lambertiano
        auto material2 = make_shared<lambertian>(color(1, 0.7, 0.5));
        world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

        // Adicionando esfera com material dielétrico
        auto material1 = make_shared<dielectric>(2);
        world.add(make_shared<sphere>(point3(2, 1, 0), 1.0, material1));

        // Renderizando a cena e salvando a imagem
        cam.render(world, ("frames/cam" + std::to_string(frame) + ".png").c_str());
        
        // Atualizando posições da esfera à esquerda e à direita
        float coordX_leftSphere = -4;
        float coordX_rightSphere = 2;
        float passo = 0.2;

        if (((frame/10) % 2 == 0) && coordX_leftSphere < -2) {
            coordX_leftSphere += passo;
        } else {
            coordX_leftSphere -= passo;
        }

        if ((frame/10) % 2 == 1) {
            coordX_rightSphere -= passo;
        } else {
            coordX_rightSphere += passo;
        }

        // Atualizando a posição da câmera e do vetor de visualização
        if (frame <= 24) {
            cam.lookfrom = cam.lookfrom.operator+=(point3(1, 0.5, -1));
            cam.vup = cam.vup.operator+=(point3(0, 0.5, 0));
        } else {
            cam.lookfrom = cam.lookfrom.operator+=(point3(-1, -0.5, 1));
            cam.vup = cam.vup.operator+=(point3(0, -0.5, 0));
        }
    }

    return 0;
}
