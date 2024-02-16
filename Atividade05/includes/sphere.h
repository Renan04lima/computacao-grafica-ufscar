/**
 * @file sphere.h
 * @brief Arquivo de implementação da classe Sphere
 */

#ifndef SPHERE_H
#define SPHERE_H

#include "utils.h"
#include "hittable.h"

/**
 * @brief Representação de uma esfera no espaço tridimensional.
 * 
 * A classe `sphere` herda da classe `hittable` e implementa a interseção de raios com uma esfera.
 */
class sphere : public hittable {
  public:
    /**
     * @brief Construtor da classe Sphere.
     * 
     * @param _center Centro da esfera.
     * @param _radius Raio da esfera.
     * @param _material Material associado à esfera.
     */
    sphere(point3 _center, double _radius, shared_ptr<material> _material)
      : center(_center), radius(_radius), mat(_material) {}

    /**
     * @brief Verifica se um raio atinge a esfera e retorna informações sobre a interseção.
     * 
     * @param r Raio a ser verificado.
     * @param ray_t Dados auxiliares de intervalo do raio.
     * @param rec Estrutura para armazenamento de informações sobre a interseção.
     * @return true Se houve interseção entre o raio e a esfera.
     * @return false Se não houve interseção entre o raio e a esfera.
     */
    bool hit(const ray& r, interval ray_t, hit_record& rec) const noexcept override {
        vec3 oc = r.origin() - center;
        auto a = r.direction().length_squared();
        auto half_b = dot(oc, r.direction());
        auto c = oc.length_squared() - radius*radius;

        auto discriminant = half_b*half_b - a*c;
        if (discriminant < 0)
            return false;

        auto sqrtd = sqrt(discriminant);
        auto root = (-half_b - sqrtd) / a;
        if (!ray_t.surrounds(root)) {
            root = (-half_b + sqrtd) / a;
            if (!ray_t.surrounds(root))
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);
        rec.mat = mat;

        return true;
    }

  private:
    point3 center;                 /**< Centro da esfera. */
    double radius;                 /**< Raio da esfera. */
    shared_ptr<material> mat;      /**< Material associado à esfera. */
};

#endif
