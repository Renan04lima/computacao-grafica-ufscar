/**
 * @file camera.h
 * @brief Arquivo de implementação da classe Camera
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "./utils.h"
#include "./color.h"
#include "./hittable.h"
#include "./material.h"
#include "../../Atividade01/includes/ImageIO.h"
#include "../../Atividade01/includes/ImageIO.cpp"

#include <iostream>
#include <string>
#include <fstream>
#include <random>

/**
 * @brief Gera um ponto aleatório dentro de um disco unitário.
 * 
 * @return point3 Ponto aleatório no disco unitário.
 */
point3 random_in_unit_disk() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;  // Mersenne Twister

    double theta = 2.0 * M_PI * distribution(generator);
    double r = sqrt(distribution(generator));

    double x = r * cos(theta);
    double y = r * sin(theta);

    return point3(x, y, 0.0);  // Assumindo que o disco está no plano XY
}

/**
 * @brief Classe que representa uma câmera na cena 3D.
 */
class camera {
  public:
    double aspect_ratio      = 1.0;  /**< Razão entre a largura e a altura da imagem. */
    int    image_width       = 100;  /**< Largura da imagem renderizada em pixels. */
    int    samples_per_pixel = 10;   /**< Número de amostras aleatórias para cada pixel. */
    int    max_depth         = 10;   /**< Número máximo de reflexões dos raios na cena. */

    double vfov     = 90;              /**< Ângulo de visão vertical (campo de visão). */
    point3 lookfrom = point3(0,0,-1);  /**< Ponto de onde a câmera está olhando. */
    point3 lookat   = point3(0,0,0);   /**< Ponto para onde a câmera está apontando. */
    vec3   vup      = vec3(0,1,0);     /**< Direção "para cima" em relação à câmera. */

    double defocus_angle = 0;  /**< Ângulo de variação dos raios através de cada pixel. */
    double focus_dist = 10;    /**< Distância do ponto de vista da câmera ao plano de foco perfeito. */

    /**
     * @brief Renderiza uma cena e salva a imagem resultante em um arquivo PNG.
     * 
     * @param world Lista de objetos presentes na cena.
     * @param filename Nome do arquivo PNG gerado.
     */
    void render(const hittable& world, const char *filename) {
        initialize();

        std::vector<unsigned char> image_data = std::vector<unsigned char>(image_width * image_height * 4);
        for (int j = 0; j < image_height; ++j) {
            for (int i = 0; i < image_width; ++i) {
                color pixel_color(0,0,0);
                for (int sample = 0; sample < samples_per_pixel; ++sample) {
                    ray r = get_ray(i, j);
                    pixel_color += ray_color(r, max_depth, world);
                    // Mapeie a cor para valores de 0 a 255 e adicione ao vetor image_data
                    image_data[(i + j * image_width) * 4] = static_cast<unsigned char>(255.999 * pixel_color.x());
                    image_data[(i + j * image_width) * 4 + 1] = static_cast<unsigned char>(255.999 * pixel_color.y());
                    image_data[(i + j * image_width) * 4 + 2] = static_cast<unsigned char>(255.999 * pixel_color.z());
                    image_data[(i + j * image_width) * 4 + 3] = 255;  // Alpha (totalmente opaco)
                }
            }
        }

        ImageIO camIO(image_width, image_height, image_data);

        camIO.save_png(filename);
    }

  private:
    int    image_height;    /**< Altura da imagem renderizada. */
    point3 center;          /**< Centro da câmera. */
    point3 pixel00_loc;     /**< Localização do pixel 0,0. */
    vec3   pixel_delta_u;   /**< Deslocamento para o pixel à direita. */
    vec3   pixel_delta_v;   /**< Deslocamento para o pixel abaixo. */
    vec3   u, v, w;         /**< Vetores de base do sistema de coordenadas da câmera. */
    vec3   defocus_disk_u;  /**< Raio horizontal do disco de desfoque. */
    vec3   defocus_disk_v;  /**< Raio vertical do disco de desfoque. */

    /**
     * @brief Inicializa a cena da câmera.
     */
    void initialize() {
        image_height = static_cast<int>(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;

        center = lookfrom;

        // Determine viewport dimensions.
        auto theta = degrees_to_radians(vfov);
        auto h = tan(theta/2);
        auto viewport_height = 2 * h * focus_dist;
        auto viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);

        // Calculate the u,v,w unit basis vectors for the camera coordinate frame.
        w = unit_vector(lookfrom - lookat);
        u = unit_vector(cross(vup, w));
        v = cross(w, u);

        // Calculate the vectors across the horizontal and down the vertical viewport edges.
        vec3 viewport_u = viewport_width * u;    // Vector across viewport horizontal edge
        vec3 viewport_v = viewport_height * -v;  // Vector down viewport vertical edge

        // Calculate the horizontal and vertical delta vectors to the next pixel.
        pixel_delta_u = viewport_u / image_width;
        pixel_delta_v = viewport_v / image_height;

        // Calculate the location of the upper left pixel.
        auto viewport_upper_left = center - (focus_dist * w) - viewport_u/2 - viewport_v/2;
        pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

        // Calculate the camera defocus disk basis vectors.
        auto defocus_radius = focus_dist * tan(degrees_to_radians(defocus_angle / 2));
        defocus_disk_u = u * defocus_radius;
        defocus_disk_v = v * defocus_radius;
    }

    /**
     * @brief Obtém um raio na posição (i, j) da imagem.
     * 
     * @param i Índice horizontal do pixel.
     * @param j Índice vertical do pixel.
     * @return ray Raio associado à posição do pixel.
     */
    ray get_ray(int i, int j) const {
        auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
        auto pixel_sample = pixel_center + pixel_sample_square();

        auto ray_origin = (defocus_angle <= 0) ? center : defocus_disk_sample();
        auto ray_direction = pixel_sample - ray_origin;

        return ray(ray_origin, ray_direction);
    }

    /**
     * @brief Retorna uma amostra aleatória no quadrado ao redor de um pixel.
     * 
     * @return vec3 Amostra no quadrado ao redor de um pixel.
     */
    vec3 pixel_sample_square() const {
        auto px = -0.5 + random_double();
        auto py = -0.5 + random_double();
        return (px * pixel_delta_u) + (py * pixel_delta_v);
    }

    /**
     * @brief Retorna uma amostra aleatória do disco de desfoque da câmera.
     * 
     * @return point3 Amostra aleatória do disco de desfoque.
     */
    point3 defocus_disk_sample() const  {
        auto p = random_in_unit_disk();
        return center + (p[0] * defocus_disk_u) + (p[1] * defocus_disk_v);
    }

    /**
     * @brief Calcula a cor do raio, considerando interseções com objetos da cena.
     * 
     * @param r Raio lançado na cena.
     * @param depth Profundidade atual de reflexão.
     * @param world Lista de objetos presentes na cena.
     * @return color Cor resultante do raio na cena.
     */
    color ray_color(const ray& r, int depth, const hittable& world) const {
        if (depth <= 0)
            return color(0,0,0);

        hit_record rec;

        if (world.hit(r, interval(0.001, infinity), rec)) {            
            ray scattered;
            color attenuation;
            if (rec.mat->scatter(r, rec, attenuation, scattered))
                return attenuation * ray_color(scattered, depth-1, world);
            
            return color(0,0,0);
        }

        vec3 unit_direction = unit_vector(r.direction());
        auto a = 0.5*(unit_direction.y() + 1.0);
        return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
    }
};

#endif
