/**
 * @file hittable.h
 * @brief Arquivo de implementação das classes Hit_record e Hittable
 */

#ifndef HITTABLE_H
#define HITTABLE_H

#include "./utils.h"

class material;

/**
 * @brief Classe que armazena informações sobre uma interseção de raio com um objeto.
 * 
 * A classe Hit_record contém dados como o ponto de interseção, a normal da superfície, 
 * o material associado e o parâmetro t do raio.
 */
class hit_record {
  public:
    point3 p;                       /**< Ponto de interseção */
    vec3 normal;                    /**< Vetor normal à superfície */
    shared_ptr<material> mat;        /**< Material associado ao objeto */
    double t;                        /**< Parâmetro t do raio na interseção */
    bool front_face;                 /**< Indica se a interseção ocorreu na face frontal do objeto */

    /**
     * @brief Define a normal da face com base no raio e na normal externa.
     * 
     * @param r Raio incidente.
     * @param outward_normal Normal externa ao objeto.
     */
    void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }

    /**
     * @brief Define a normal da face com base no raio, na normal externa e na cor da normal.
     * 
     * @param r Raio incidente.
     * @param outward_normal Normal externa ao objeto.
     * @param color_normal Cor associada à normal.
     */
    void set_face_normal(const ray& r, const vec3& outward_normal, const vec3& color_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? color_normal : -color_normal;
    }
};

/**
 * @brief Classe base abstrata que representa um objeto interceptável por raios.
 * 
 * A classe Hittable define uma interface para objetos que podem ser atingidos por raios.
 */
class hittable {
  public:
    virtual ~hittable() = default;

    /**
     * @brief Método virtual puro para determinar a interseção entre um raio e o objeto.
     * 
     * @param r Raio a ser verificado quanto à interseção.
     * @param ray_t Dados auxiliares de intervalo do raio.
     * @param rec Registro para armazenar informações sobre a interseção.
     * @return true Se houve uma interseção.
     * @return false Se não houve interseção.
     */
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif
