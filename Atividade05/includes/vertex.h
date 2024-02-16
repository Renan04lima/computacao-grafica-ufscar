/**
 * @file vertex.h
 * @brief Arquivo de implementação da classe Vertex
 */

#ifndef VERTEX_H
#define VERTEX_H

#include "../../Atividade02/includes/vec3.h"

class vertex {
    public:
        point3 coord;
        vec3 normal;

        vertex(const point3& _coord, const point3& _normal): 
            coord(_coord), normal(_normal) {}
};

#endif