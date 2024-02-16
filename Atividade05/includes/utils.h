/**
 * @file utils.h
 * @brief Arquivo de implementação da classe Utils
 */

#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <limits>
#include <memory>
#include <random>

// Usings
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

/**
 * @brief Converte graus para radianos.
 * 
 * @param degrees Graus a serem convertidos.
 * @return double Valor em radianos.
 */
inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

/**
 * @brief Gera um número aleatório do tipo double no intervalo [0, 1).
 * 
 * @return double Número aleatório gerado.
 */
inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

/**
 * @brief Gera um número aleatório do tipo double dentro de um intervalo específico.
 * 
 * @param min Valor mínimo do intervalo.
 * @param max Valor máximo do intervalo.
 * @return double Número aleatório gerado.
 */
inline double random_double(double min, double max) {
    static std::uniform_real_distribution<double> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);
}

// Common headers
#include "./interval.h"
#include "../../Atividade04/includes/ray.h"
#include "../../Atividade02/includes/vec3.h"

#endif
