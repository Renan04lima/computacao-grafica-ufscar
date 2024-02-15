#ifndef RAY_H
#define RAY_H

#include "../../Atividade02/includes/vec3.h"

/**
 * @brief Classe que representa um raio em um espaço tridimensional.
 *
 * A classe ray é utilizada para representar um raio que possui uma origem (point3) e
 * uma direção (vec3) no espaço tridimensional. Oferece métodos para acessar a origem,
 * a direção e calcular um ponto em determinada distância ao longo do raio.
 */
class ray {
public:
    /**
     * @brief Construtor padrão da classe ray.
     */
    ray() {}

    /**
     * @brief Construtor parametrizado que inicializa um raio com uma origem e uma direção.
     * @param origin A origem do raio (point3).
     * @param direction A direção do raio (vec3).
     */
    ray(const point3 &origin, const vec3 &direction) : orig(origin), dir(direction) {}

    /**
     * @brief Obtém a origem do raio.
     * @return A origem do raio (point3).
     */
    point3 origin() const { return orig; }

    /**
     * @brief Obtém a direção do raio.
     * @return A direção do raio (vec3).
     */
    vec3 direction() const { return dir; }

    /**
     * @brief Calcula um ponto ao longo do raio a uma determinada distância.
     * @param t A distância ao longo do raio.
     * @return O ponto no espaço tridimensional correspondente à distância t ao longo do raio.
     */
    point3 at(double t) const {
        return orig + t * dir;
    }

private:
    point3 orig; ///< Origem do raio.
    vec3 dir;    ///< Direção do raio.
};

#endif
