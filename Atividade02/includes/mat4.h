/**
 * @file mat4.h
 * @brief Defines the mat4 class and related functions.
 * @author Renan Oliveira de Barros Lima
 */

#ifndef MAT4_H
#define MAT4_H

#include <cmath>
#include <iostream>
#include "vec4.h"

/**
 * @class mat4
 * @brief A class that represents a 4x4 matrix.
 */
class mat4 {
  public:
    vec4 rows[4]; ///< The rows of the matrix.

    /**
     * @brief Default constructor. Initializes the matrix to zero.
     */
    mat4() {}

    /**
     * @brief Constructor that initializes the matrix with four rows.
     * @param row0 The first row of the matrix.
     * @param row1 The second row of the matrix.
     * @param row2 The third row of the matrix.
     * @param row3 The fourth row of the matrix.
     */
    mat4(const vec4& row0, const vec4& row1, const vec4& row2, const vec4& row3) {
        rows[0] = row0;
        rows[1] = row1;
        rows[2] = row2;
        rows[3] = row3;
    }

    /**
     * @brief Overloads the [] operator to access rows of the matrix.
     * @param i The index of the row to access.
     * @return A reference to the i-th row of the matrix.
     */
    vec4& operator[](int i) {
        return rows[i];
    }

    /**
     * @brief Overloads the [] operator to access rows of the matrix.
     * @param i The index of the row to access.
     * @return A constant reference to the i-th row of the matrix.
     */
    const vec4& operator[](int i) const {
        return rows[i];
    }
};

/**
 * @brief Overloads the << operator to print the matrix.
 * @param out The output stream to print to.
 * @param m The matrix to print.
 * @return The output stream.
 */
inline std::ostream& operator<<(std::ostream& out, const mat4& m) {
    return out << m[0] << '\n' << m[1] << '\n' << m[2] << '\n' << m[3];
}

#endif