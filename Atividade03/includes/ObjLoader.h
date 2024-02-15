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
    /**
     * @brief Obtém os vértices carregados.
     * @return Vetor de vértices.
     */
    std::vector<Vertex> GetVertices() const;

    /**
     * @brief Obtém as coordenadas de textura carregadas.
     * @return Vetor de coordenadas de textura.
     */
    std::vector<TextureCoord> GetTextureCoords() const;

    /**
     * @brief Obtém as normais carregadas.
     * @return Vetor de normais.
     */
    std::vector<Normal> GetNormals() const;

    /**
     * @brief Obtém as faces carregadas.
     * @return Vetor de faces.
     */
    std::vector<Face> GetFaces() const;

    /**
     * @brief Carrega um arquivo OBJ.
     * @param filename Nome do arquivo OBJ.
     */
    void LoadObj(const std::string& filename);

private:
    std::vector<Vertex> vertices;
    std::vector<TextureCoord> textureCoords;
    std::vector<Normal> normals;
    std::vector<Face> faces;
};

#endif 
