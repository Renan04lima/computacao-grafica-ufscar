#ifndef MAT3_H
#define MAT3_H

#include <cmath>
#include <iostream>
#include "vec3.h"

class mat3 {
  public:
    vec3 rows[3];

    mat3() {}
    mat3(const vec3& row0, const vec3& row1, const vec3& row2) {
        rows[0] = row0;
        rows[1] = row1;
        rows[2] = row2;
    }

    vec3& operator[](int i) {
        return rows[i];
    }

    const vec3& operator[](int i) const {
        return rows[i];
    }
};

inline std::ostream& operator<<(std::ostream& out, const mat3& m) {
    return out << m[0] << '\n' << m[1] << '\n' << m[2];
}

#endif
