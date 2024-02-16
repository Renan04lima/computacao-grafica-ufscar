#include "vec3.h"

/**
 * @brief Default constructor. Initializes the vector to zero.
 * @author Renan Oliveira de Barros Lima
 */
vec3::vec3() {
    e[0] = 0;
    e[1] = 0;
    e[2] = 0;
}

/**
 * @brief Constructor that initializes the vector with three components.
 * @param e0 The x component of the vector.
 * @param e1 The y component of the vector.
 * @param e2 The z component of the vector.
 */
vec3::vec3(double e0, double e1, double e2) {
    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
}
/**
 * @brief Verifica se o vetor é próximo de zero em todos os componentes
 */
bool vec3::near_zero() const {
    const auto s = 1e-8;
    return (fabs( e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
}

/**
 * @brief Getter for the x component of the vector.
 * @return The x component of the vector.
 */
double vec3::x() const { return e[0]; }

/**
 * @brief Getter for the y component of the vector.
 * @return The y component of the vector.
 */
double vec3::y() const { return e[1]; }

/**
 * @brief Getter for the z component of the vector.
 * @return The z component of the vector.
 */
double vec3::z() const { return e[2]; }

/**
 * @brief Overloads the unary minus operator to return the negation of the vector.
 * @return A new vec3 object that is the negation of the current object.
 */
vec3 vec3::operator-() const { return vec3(-e[0], -e[1], -e[2]); }

/**
 * @brief Overloads the [] operator to access components of the vector.
 * @param i The index of the component to access.
 * @return The i-th component of the vector.
 */
double vec3::operator[](int i) const { return e[i]; }

/**
 * @brief Overloads the [] operator to access components of the vector.
 * @param i The index of the component to access.
 * @return A reference to the i-th component of the vector.
 */
double& vec3::operator[](int i) { return e[i]; }

/**
 * @brief Overloads the += operator to add another vector to this vector.
 * @param v The other vector.
 * @return A reference to the current object.
 */
vec3& vec3::operator+=(const vec3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

/**
 * @brief Overloads the *= operator to multiply this vector by a scalar.
 * @param t The scalar.
 * @return A reference to the current object.
 */
vec3& vec3::operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

/**
 * @brief Overloads the /= operator to divide this vector by a scalar.
 * @param t The scalar.
 * @return A reference to the current object.
 */
vec3& vec3::operator/=(double t) {
    return *this *= 1/t;
}

/**
 * @brief Calculates the length of the vector.
 * @return The length of the vector.
 */
double vec3::length() const {
    return sqrt(length_squared());
}

/**
 * @brief Calculates the squared length of the vector.
 * @return The squared length of the vector.
 */
double vec3::length_squared() const {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}

/**
 * @brief Overloads the << operator to print the vector.
 * @param out The output stream to print to.
 * @param v The vector to print.
 * @return The output stream.
 */
std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

/**
 * @brief Overloads the + operator to add two vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The sum of the two vectors.
 */
vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

/**
 * @brief Overloads the - operator to subtract two vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The difference of the two vectors.
 */
vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

/**
 * @brief Overloads the * operator to multiply two vectors component-wise.
 * @param u The first vector.
 * @param v The second vector.
 * @return The component-wise product of the two vectors.
 */
vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

/**
 * @brief Overloads the * operator to multiply a vector by a scalar.
 * @param t The scalar.
 * @param v The vector.
 * @return The product of the scalar and the vector.
 */
vec3 operator*(double t, const vec3 &v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

/**
 * @brief Overloads the * operator to multiply a vector by a scalar.
 * @param v The vector.
 * @param t The scalar.
 * @return The product of the scalar and the vector.
 */
vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

/**
 * @brief Overloads the / operator to divide a vector by a scalar.
 * @param v The vector.
 * @param t The scalar.
 * @return The quotient of the vector and the scalar.
 */
vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

/**
 * @brief Calculates the dot product of two vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The dot product of the two vectors.
 */
double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

/**
 * @brief Calculates the cross product of two vectors.
 * @param u The first vector.
 * @param v The second vector.
 * @return The cross product of the two vectors.
 */
vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

/**
 * @brief Calculates the unit vector of a vector.
 * @param v The vector.
 * @return The unit vector of the vector.
 */
vec3 unit_vector(vec3 v) {
    return v / v.length();
}