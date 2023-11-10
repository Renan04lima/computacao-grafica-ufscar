#include "ObjLoader.h"

std::vector<Vertex> ObjLoader::GetVertices() const {
    return vertices;
}

std::vector<TextureCoord> ObjLoader::GetTextureCoords() const {
    return textureCoords;
}

std::vector<Normal> ObjLoader::GetNormals() const {
    return normals;
}

std::vector<Face> ObjLoader::GetFaces() const {
    return faces;
}

void ObjLoader::LoadObj(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        iss >> token;

        if (token == "v") {
            Vertex vertex;
            iss >> vertex.x >> vertex.y >> vertex.z;
            vertices.push_back(vertex);
        } else if (token == "vt") {
            TextureCoord texCoord;
            iss >> texCoord.u >> texCoord.v;
            textureCoords.push_back(texCoord);
        } else if (token == "vn") {
            Normal normal;
            iss >> normal.nx >> normal.ny >> normal.nz;
            normals.push_back(normal);
        } else if (token == "f") {
            Face face;
            iss >> face.v1 >> face.vt1 >> face.vn1
                >> face.v2 >> face.vt2 >> face.vn2
                >> face.v3 >> face.vt3 >> face.vn3;
            faces.push_back(face);
        }
    }

    file.close();
}
