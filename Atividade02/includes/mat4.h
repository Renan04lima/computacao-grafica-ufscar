#ifndef MAT4_H
#define MAT4_H

#include <cmath>
#include <iostream>
#include "vec4.h"

class mat4 {
  public:
    vec4 rows[4];

    mat4() {}
    mat4(const vec4& row0, const vec4& row1, const vec4& row2, const vec4& row3) {
        rows[0] = row0;
        rows[1] = row1;
        rows[2] = row2;
        rows[3] = row3;
    }

    vec4& operator[](int i) {
        return rows[i];
    }

    const vec4& operator[](int i) const {
        return rows[i];
    }
};

inline std::ostream& operator<<(std::ostream& out, const mat4& m) {
    return out << m[0] << '\n' << m[1] << '\n' << m[2] << '\n' << m[3];
}

#endif
