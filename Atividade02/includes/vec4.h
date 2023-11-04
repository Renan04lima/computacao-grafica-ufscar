/**
 * @file vec4.h
 * @brief Defines the vec4 class and related functions.
 * @author Renan Oliveira de Barros Lima
 */

#ifndef VEC4_H
#define VEC4_H

#include "vec3.h"

/**
 * @class vec4
 * @brief A class that represents a 4D vector, derived from the vec3 class.
 * 
 * The fourth dimension, w, is used to distinguish between points and directions in 3D space. 
 * When w is 1, the vector represents a point in 3D space. When w is 0, the vector represents a direction.
 */
class vec4 : public vec3 {
public:
    double w;

    /**
     * @brief Default constructor. Initializes the vector to zero and w to 1.
     */
    vec4() : vec3(), w(1) {}

    /**
     * @brief Constructor that initializes the vector with four components.
     * @param x The x component of the vector.
     * @param y The y component of the vector.
     * @param z The z component of the vector.
     * @param w The w component of the vector.
     */
    vec4(double x, double y, double z, double w) : vec3(x, y, z), w(w) {}

    /**
     * @brief Constructor that initializes the vector with a vec3 and w to 1.
     * @param v3 The vec3 to initialize the vector with.
     */
    vec4(const vec3 &v3) : vec3(v3), w(1) {}

    /**
     * @brief Overloads the == operator to compare two vec4 objects for equality.
     * @param other The other vec4 to compare with.
     * @return True if the two vec4 objects are equal, false otherwise.
     */
    bool operator==(const vec4 &other) const {
        return x() == other.x() && y() == other.y() && z() == other.z() && w == other.w;
    }
};

#endif