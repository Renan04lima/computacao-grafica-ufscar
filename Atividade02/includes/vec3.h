#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

/**
 * @class vec3
 * @brief A class that represents a 3D vector.
 * @author Renan Oliveira de Barros Lima
 */
class vec3 {
  public:
    double e[3];

    /**
     * @brief Default constructor. Initializes the vector to zero.
     */
    vec3();

    /**
     * @brief Constructor that initializes the vector with three components.
     * @param e0 The x component of the vector.
     * @param e1 The y component of the vector.
     * @param e2 The z component of the vector.
     */
    vec3(double e0, double e1, double e2);

    /**
     * @brief Getter for the x component of the vector.
     * @return The x component of the vector.
     */
    double x() const;

    /**
     * @brief Getter for the y component of the vector.
     * @return The y component of the vector.
     */
    double y() const;

    /**
     * @brief Getter for the z component of the vector.
     * @return The z component of the vector.
     */
    double z() const;

    /**
     * @brief Overloads the unary minus operator to return the negation of the vector.
     * @return A new vec3 object that is the negation of the current object.
     */
    vec3 operator-() const;

    /**
     * @brief Overloads the [] operator to access components of the vector.
     * @param i The index of the component to access.
     * @return The i-th component of the vector.
     */
    double operator[](int i) const;

    /**
     * @brief Overloads the [] operator to access components of the vector.
     * @param i The index of the component to access.
     * @return A reference to the i-th component of the vector.
     */
    double& operator[](int i);

    /**
     * @brief Overloads the += operator to add another vector to this vector.
     * @param v The other vector.
     * @return A reference to the current object.
     */
    vec3& operator+=(const vec3 &v);

    /**
     * @brief Overloads the *= operator to multiply this vector by a scalar.
     * @param t The scalar.
     * @return A reference to the current object.
     */
    vec3& operator*=(double t);

    /**
     * @brief Overloads the /= operator to divide this vector by a scalar.
     * @param t The scalar.
     * @return A reference to the current object.
     */
    vec3& operator/=(double t);

    /**
     * @brief Calculates the length of the vector.
     * @return The length of the vector.
     */
    double length() const;

    /**
     * @brief Calculates the squared length of the vector.
     * @return The squared length of the vector.
     */
    double length_squared() const;
};

// point3 is just an alias for vec3, but useful for geometric clarity in the code.
using point3 = vec3;

// Vector Utility Functions

/**
 * @brief Overloads the << operator to print the vector.
 * @param out The output stream to print to.
 * @param v The vector to print.
 * @return The output stream.
 */
std::ostream& operator<<(std::ostream &out, const vec3 &v);

/**
 * @brief Overloads the + operator to add two vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The sum of the two vectors.
 */
vec3 operator+(const vec3 &u, const vec3 &v);

/**
 * @brief Overloads the - operator to subtract two vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The difference of the two vectors.
 */
vec3 operator-(const vec3 &u, const vec3 &v);

/**
 * @brief Overloads the * operator to multiply two vectors component-wise.
 * @param u The first vector.
 * @param v The second vector.
 * @return The component-wise product of the two vectors.
 */
vec3 operator*(const vec3 &u, const vec3 &v);

/**
 * @brief Overloads the * operator to multiply a vector by a scalar.
 * @param t The scalar.
 * @param v The vector.
 * @return The product of the scalar and the vector.
 */
vec3 operator*(double t, const vec3 &v);

/**
 * @brief Overloads the * operator to multiply a vector by a scalar.
 * @param v The vector.
 * @param t The scalar.
 * @return The product of the scalar and the vector.
 */
vec3 operator*(const vec3 &v, double t);

/**
 * @brief Overloads the / operator to divide a vector by a scalar.
 * @param v The vector.
 * @param t The scalar.
 * @return The quotient of the vector and the scalar.
 */
vec3 operator/(vec3 v, double t);

/**
 * @brief Calculates the dot product of two vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The dot product of the two vectors.
 */
double dot(const vec3 &u, const vec3 &v);

/**
 * @brief Calculates the cross product of two vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The cross product of the two vectors.
 */
vec3 cross(const vec3 &u, const vec3 &v);

/**
 * @brief Calculates the unit vector of a vector.
 * @param v The vector.
 * @return The unit vector of the vector.
 */
vec3 unit_vector(vec3 v);

#endif