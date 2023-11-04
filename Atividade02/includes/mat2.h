/**
 * @file mat2.h
 * @brief Defines the mat2 class and related functions.
 * @author Renan Oliveira de Barros Lima
 */

#ifndef MAT2_H
#define MAT2_H

#include "vec2.h"
#include <cmath>
#include <iostream>

/**
 * @class mat2
 * @brief A class that represents a 2x2 matrix.
 */
class mat2 {
public:
    vec2 rows[2]; ///< The rows of the matrix.

    /**
     * @brief Default constructor. Initializes the matrix to zero.
     */
    mat2() {}

    /**
     * @brief Constructor that initializes the matrix with two rows.
     * @param row0 The first row of the matrix.
     * @param row1 The second row of the matrix.
     */
    mat2(const vec2 &row0, const vec2 &row1) {
        rows[0] = row0;
        rows[1] = row1;
    }

    /**
     * @brief Overloads the [] operator to access rows of the matrix.
     * @param i The index of the row to access.
     * @return A reference to the i-th row of the matrix.
     */
    vec2 &operator[](int i) {
        return rows[i];
    }

    /**
     * @brief Overloads the [] operator to access rows of the matrix.
     * @param i The index of the row to access.
     * @return A constant reference to the i-th row of the matrix.
     */
    const vec2 &operator[](int i) const {
        return rows[i];
    }
};

/**
 * @brief Overloads the << operator to print the matrix.
 * @param out The output stream to print to.
 * @param m The matrix to print.
 * @return The output stream.
 */
inline std::ostream &operator<<(std::ostream &out, const mat2 &m) {
    out << m[0].x() << " " << m[0].y() << "\n";
    out << m[1].x() << " " << m[1].y() << "\n";
    return out;
}

#endif