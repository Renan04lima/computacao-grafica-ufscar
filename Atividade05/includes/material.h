/**
 * @file material.h
 * @brief Arquivo de implementação da classe Material
 */

#ifndef MATERIAL_H
#define MATERIAL_H

#include "utils.h"
#include "hittable_list.h"
#include <cstdlib>

/**
 * @brief Classe base abstrata para materiais.
 * 
 * A classe `material` fornece uma interface para diferentes tipos de materiais utilizados em interações
 * de raios com objetos na cena.
 */
class material {
  public:
    virtual ~material() = default;

    /**
     * @brief Método virtual puro de espalhamento de raio.
     * 
     * @param r_in Raio incidente.
     * @param rec Registro de interseptação.
     * @param attenuation Atenuação da cor.
     * @param scattered Raio espalhado.
     * @return true Se houve espalhamento do raio.
     * @return false Se não houve espalhamento do raio.
     */
    virtual bool scatter(
        const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const = 0;
};

/**
 * @brief Gera um vetor unitário aleatório na esfera.
 * 
 * @return vec3 Vetor unitário aleatório na esfera.
 */
vec3 random_unit_vector() {
    auto a = random_double(0, 2 * pi);
    auto z = random_double(-1, 1);
    auto r = sqrt(1 - z * z);

    return vec3(r * cos(a), r * sin(a), z);
}

/**
 * @brief Classe que representa um material difuso (lambertiano).
 */
class lambertian : public material {
  public:
    /**
     * @brief Construtor da classe lambertian.
     * 
     * @param a Cor do material.
     */
    lambertian(const color& a) : albedo(a) {}

    /**
     * @brief Implementação da função de espalhamento para material difuso.
     * 
     * @param r_in Raio incidente.
     * @param rec Registro de interseptação.
     * @param attenuation Atenuação da cor.
     * @param scattered Raio espalhado.
     * @return true Sempre retorna verdadeiro.
     */
    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
    const override {
        auto scatter_direction = rec.normal + random_unit_vector();

        // Trata direção de espalhamento degenerada
        if (scatter_direction.near_zero())
            scatter_direction = rec.normal;

        scattered = ray(rec.p, scatter_direction);
        attenuation = albedo;
        return true;
    }

  private:
    color albedo; /**< Cor do material lambertiano. */
};

/**
 * @brief Calcula a reflexão de um vetor em relação a uma normal.
 * 
 * @param v Vetor a ser refletido.
 * @param normal Normal da superfície.
 * @return vec3 Vetor refletido.
 */
vec3 reflect(const vec3& v, const vec3& normal) {
    return v - 2 * dot(v, normal) * normal;
}

/**
 * @brief Gera um vetor aleatório na esfera unitária.
 * 
 * @return vec3 Vetor aleatório na esfera unitária.
 */
vec3 random_in_unit_sphere() {
    while (true) {
        auto p = vec3::random(-1, 1);
        if (p.length_squared() >= 1)
            continue;
        return p;
    }
}

/**
 * @brief Classe que representa um material metálico.
 */
class metal : public material {
  public:
    /**
     * @brief Construtor da classe metal.
     * 
     * @param a Cor do material metálico.
     * @param f Fuzziness (borramento) do material.
     */
    metal(const color& a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

    /**
     * @brief Implementação da função de espalhamento para material metálico.
     * 
     * @param r_in Raio incidente.
     * @param rec Registro de interseptação.
     * @param attenuation Atenuação da cor.
     * @param scattered Raio espalhado.
     * @return true Se o raio espalhado é válido.
     */
    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
    const override {
        vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
        scattered = ray(rec.p, reflected + fuzz*random_in_unit_sphere());
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }

  private:
    color albedo; /**< Cor do material metálico. */
    double fuzz;  /**< Fuzziness (borramento) do material. */
};

/**
 * @brief Calcula a refração de um vetor.
 * 
 * @param uv Vetor a ser refratado.
 * @param normal Normal da superfície.
 * @param etai_over_etat Índice de refração.
 * @return vec3 Vetor refratado.
 */
vec3 refract(const vec3& uv, const vec3& normal, double etai_over_etat) {
    auto cos_theta = fmin(dot(-uv, normal), 1.0);
    vec3 r_out_perp = etai_over_etat * (uv + cos_theta * normal);
    vec3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * normal;
    return r_out_perp + r_out_parallel;
}

/**
 * @brief Classe que representa um material de vidro.
 */
class dielectric : public material {
  public:
    /**
     * @brief Construtor da classe dielectric.
     * 
     * @param index_of_refraction Índice de refração do material.
     */
    dielectric(double index_of_refraction) : ir(index_of_refraction) {}

    /**
     * @brief Implementação da função de espalhamento para material dielétrico (de vidro).
     * 
     * @param r_in Raio incidente.
     * @param rec Registro de interseptação.
     * @param attenuation Atenuação da cor.
     * @param scattered Raio espalhado.
     * @return true Se o raio espalhado é válido.
     */
    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
    const override {
        attenuation = color(1.0, 1.0, 1.0);
        double refraction_ratio = rec.front_face ? (1.0/ir) : ir;

        vec3 unit_direction = unit_vector(r_in.direction());
        double cos_theta = fmin(dot(-unit_direction, rec.normal), 1.0);
        double sin_theta = sqrt(1.0 - cos_theta*cos_theta);

        bool cannot_refract = refraction_ratio * sin_theta > 1.0;
        vec3 direction;

        if (cannot_refract || reflectance(cos_theta, refraction_ratio) > random_double())
            direction = reflect(unit_direction, rec.normal);
        else
            direction = refract(unit_direction, rec.normal, refraction_ratio);

        scattered = ray(rec.p, direction);
        return true;
    }

  private:
    double ir; /**< Índice de refração do material dielétrico. */

    /**
     * @brief Calcula o coeficiente de reflectância.
     * 
     * @param cosine Cosseno do ângulo de incidência.
     * @param ref_idx Índice de refração.
     * @return double Coeficiente de reflectância.
     */
    static double reflectance(double cosine, double ref_idx) {
        auto r0 = (1-ref_idx) / (1+ref_idx);
        r0 = r0*r0;
        return r0 + (1-r0)*pow((1 - cosine),5);
    }
};

#endif
