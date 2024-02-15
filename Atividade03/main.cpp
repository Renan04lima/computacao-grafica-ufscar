/**
 * @file main.cpp
 * @author Renan Oliveira de Barros Lima
 * @brief Um exemplo de uso da classe ObjLoader para carregar arquivos OBJ.
 */

#include <iostream>
#include <vector>
#include "includes/ObjLoader.h"

int main() {
    ObjLoader objLoader;
    objLoader.LoadObj("/Users/renanoliveira/Desktop/ufscar/2023-02/computacao-grafica/atividades-projeto/Atividade03/indoor_plant.obj");

    std::vector<Vertex> vertices = objLoader.GetVertices();
    std::vector<TextureCoord> textureCoords = objLoader.GetTextureCoords();
    std::vector<Normal> normals = objLoader.GetNormals();
    std::vector<Face> faces = objLoader.GetFaces();

    std::cout << "Número de vértices: " << vertices.size() << "\n";
    std::cout << "Número de coordenadas de textura: " << textureCoords.size() << "\n";
    std::cout << "Número de normais: " << normals.size() << "\n";
    std::cout << "Número de faces: " << faces.size() << "\n";

    return 0;
}