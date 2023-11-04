/**
 * @file mat3.h
 * @brief A class that represents a 3x3 matrix.
 * @author Renan Oliveira de Barros Lima
 */

#ifndef MAT3_H
#define MAT3_H

#include "vec3.h"
#include <cmath>
#include <iostream>

class mat3 {
public:
    vec3 rows[3]; ///< The rows of the matrix.

    /**
     * @brief Default constructor. Initializes the matrix to zero.
     */
    mat3() {}

    /**
     * @brief Constructor that initializes the matrix with three rows.
     * @param row0 The first row of the matrix.
     * @param row1 The second row of the matrix.
     * @param row2 The third row of the matrix.
     */
    mat3(const vec3 &row0, const vec3 &row1, const vec3 &row2) {
        rows[0] = row0;
        rows[1] = row1;
        rows[2] = row2;
    }

    /**
     * @brief Overloads the [] operator to access rows of the matrix.
     * @param i The index of the row to access.
     * @return A reference to the i-th row of the matrix.
     */
    vec3 &operator[](int i) {
        return rows[i];
    }

    /**
     * @brief Overloads the [] operator to access rows of the matrix.
     * @param i The index of the row to access.
     * @return A constant reference to the i-th row of the matrix.
     */
    const vec3 &operator[](int i) const {
        return rows[i];
    }
};

/**
 * @brief Overloads the << operator to print the matrix.
 * @param out The output stream to print to.
 * @param m The matrix to print.
 * @return The output stream.
 */
inline std::ostream &operator<<(std::ostream &out, const mat3 &m) {
    out << m[0].x() << " " << m[0].y() << " " << m[0].z() << "\n";
    out << m[1].x() << " " << m[1].y() << " " << m[1].z() << "\n";
    out << m[2].x() << " " << m[2].y() << " " << m[2].z() << "\n";
    return out;
}

#endif
