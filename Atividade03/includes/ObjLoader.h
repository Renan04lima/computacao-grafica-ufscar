/**
 * @file ObjLoader.h
 * @brief Classe para carregar arquivos OBJ.
 * @author Renan Oliveira de Barros Lima
 */
#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "../../Atividade05/includes/triangle.h"
#include "../../Atividade05/includes/material.h"

struct Vertex {
    float x, y, z;
};

struct TextureCoord {
    float u, v;
};

struct Normal {
    float nx, ny, nz;
};

struct Face {
    int v1, v2, v3;
};

/**
 * @brief Classe para carregar arquivos OBJ.
 */
class ObjLoader {
public:
    std::vector<Vertex> vertices;
    std::vector<TextureCoord> textureCoords;
    std::vector<Normal> normals;
    std::vector<std::vector<Face> > faces;

    /**
     * @brief Obtém os vértices carregados.
     * @return Vetor de vértices.
     */
    Vertex GetVertices(const int idx) const;

    /**
     * @brief Obtém as coordenadas de textura carregadas.
     * @return Vetor de coordenadas de textura.
     */
    std::vector<TextureCoord> GetTextureCoords() const;

    /**
     * @brief Obtém as normais carregadas.
     * @return Vetor de normais.
     */
    Normal GetNormals(const int idx) const;

    /**
     * @brief Obtém as faces carregadas.
     * @return Vetor de faces.
     */
    Face GetFaces(const int i, const int j) const;

    /**
     * @brief Carrega um arquivo OBJ.
     * @param filename Nome do arquivo OBJ.
     */
    void LoadObj(const std::string& filename);

    std::vector<triangle> get_triangle_faces(shared_ptr<material> mat);
};

#endif 
