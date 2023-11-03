#ifndef MAT2_H
#define MAT2_H

#include <cmath>
#include <iostream>
#include "vec2.h"

class mat2 {
  public:
    vec2 rows[2];

    mat2() {}
    mat2(const vec2& row0, const vec2& row1) {
        rows[0] = row0;
        rows[1] = row1;
    }

    vec2& operator[](int i) {
        return rows[i];
    }

    const vec2& operator[](int i) const {
        return rows[i];
    }
};


inline std::ostream& operator<<(std::ostream& out, const mat2& m) {
    return out << m[0] << '\n' << m[1];
}

#endif
