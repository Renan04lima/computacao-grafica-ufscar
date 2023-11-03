#ifndef VEC4_H
#define VEC4_H

#include "vec3.h"

class vec4 : public vec3 {
  public:
    double w;

    vec4() : vec3(), w(1) {}
    vec4(double x, double y, double z, double w) : vec3(x, y, z), w(w) {}
    vec4(const vec3& v3) : vec3(v3), w(1) {}
};

#endif
