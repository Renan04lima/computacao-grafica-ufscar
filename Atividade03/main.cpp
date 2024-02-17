/**
 * @file main.cpp
 * @author Renan Oliveira de Barros Lima
 * @brief Um exemplo de uso da classe ObjLoader para carregar arquivos OBJ.
 */

#include <iostream>
#include <vector>
#include "includes/ObjLoader.h"
#include "includes/ObjLoader.cpp"

int main() {
    ObjLoader obj;
    obj.LoadObj("/Users/renanoliveira/Desktop/ufscar/2023-02/computacao-grafica/atividades-projeto/Atividade03/indoor_plant.obj");

  // Imprimir vértices
    for (size_t i = 0; i < obj.vertices.size(); ++i) {
        Vertex v = obj.GetVertices(i);
        std::cout << "Vertex " << i << ": " << v.x << " " << v.y << " " << v.z << std::endl;
    }

    // Imprimir coordenadas de textura
    std::vector<TextureCoord> texCoords = obj.GetTextureCoords();
    for (size_t i = 0; i < texCoords.size(); ++i) {
        TextureCoord t = texCoords[i];
        std::cout << "Texture Coord " << i << ": " << t.u << " " << t.v << std::endl;
    }

    // Imprimir normais
    for (size_t i = 0; i < obj.normals.size(); ++i) {
        Normal n = obj.GetNormals(i);
        std::cout << "Normal " << i << ": " << n.nx << " " << n.ny << " " << n.nz << std::endl;
    }

    // Imprimir faces
    for (size_t i = 0; i < obj.faces.size(); ++i) {
        for (size_t j = 0; j < obj.faces[i].size(); ++j) {
            Face f = obj.GetFaces(i, j);
            std::cout << "Face " << i << ", Vertex " << j << ": " << f.v1 << " " << f.v2 << " " << f.v3 << std::endl;
        }
    }
    return 0;
}