/**
 * @file vec2.h
 * @brief Defines the vec2 class and related functions.
 * @author Renan Oliveira de Barros Lima
 */

#ifndef VEC2_H
#define VEC2_H

#include "vec3.h"

/**
 * @class vec2
 * @brief A class that represents a 2D vector, derived from the vec3 class.
 */
class vec2 : public vec3 {
public:
    /**
     * @brief Default constructor. Initializes the vector to zero.
     */
    vec2() : vec3() {}

    /**
     * @brief Constructor that initializes the vector with two components.
     * @param x The x component of the vector.
     * @param y The y component of the vector.
     */
    vec2(double x, double y) : vec3(x, y, 0) {}

    /**
     * @brief Overloads the unary minus operator to return the negation of the vector.
     * @return A new vec2 object that is the negation of the current object.
     */
    vec2 operator-() const {
        return vec2(-x(), -y());
    }
};

#endif