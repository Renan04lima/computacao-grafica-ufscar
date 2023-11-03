#ifndef VEC2_H
#define VEC2_H

#include "vec3.h"

class vec2 : public vec3 {
  public:
    vec2() : vec3() {}
    vec2(double x, double y) : vec3(x, y, 0) {}
};

#endif
