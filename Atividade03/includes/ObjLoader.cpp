#include "ObjLoader.h"

Vertex ObjLoader::GetVertices(const int idx) const {
    if (idx >= 0 && idx < vertices.size()) {
        return vertices[idx];
    }

    return Vertex();
}

std::vector<TextureCoord> ObjLoader::GetTextureCoords() const {
    return textureCoords;
}

Normal ObjLoader::GetNormals(const int idx) const {
    if (idx >= 0 && idx < normals.size()) {
        return normals[idx];
    }

    return Normal();
}

Face ObjLoader::GetFaces(const int i, const int j) const {
 if (i >= 0 && j >= 0 && i < faces.size()) {
        return faces[i][j];
    }

    return Face();
};

       

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
            std::vector<Face> faces_in_line;
            for (int i = 0; i < 3; ++i) {
                Face face;
                int v1, v2, v3;
                iss >> v1 >> v2 >> v3;

                // Ajuste para considerar apenas os índices de vértices
                face.v1 = v1;
                face.v2 = v2;
                face.v3 = v3;

                faces_in_line.push_back(face);
            }
            faces.push_back(faces_in_line);
        }
    }

    file.close();
}



std::vector<triangle> ObjLoader::get_triangle_faces(shared_ptr<material> mat) {
        /* Collect all triangles from obj */
        std::vector<triangle> triangle_list;
        int qtd_faces = faces.size();

        for (size_t i = 0; i < qtd_faces; i++) {
            int indiceV0 = this->GetFaces(i, 0).v1 - 1;
            int indiceV1 = this->GetFaces(i, 1).v1 - 1;
            int indiceV2 = this->GetFaces(i, 2).v1 - 1;

            point3 A(this->GetVertices(indiceV0).x, this->GetVertices(indiceV0).y, this->GetVertices(indiceV0).z);
            point3 B(this->GetVertices(indiceV1).x, this->GetVertices(indiceV1).y, this->GetVertices(indiceV1).z);
            point3 C(this->GetVertices(indiceV2).x, this->GetVertices(indiceV2).y, this->GetVertices(indiceV2).z);

            // If the obj file doesn't specify vertex normals...
            if(normals.empty()) {
                vec3 u = B - A;
                vec3 v = C - A;
                vec3 triangle_normal = cross(u, v);

                vertex vA(A, triangle_normal), vB(B, triangle_normal), vC(C, triangle_normal);
                triangle t = triangle(vA, vB, vC, mat);
                triangle_list.push_back(t);

            } else {
                int ind_vnA = this->GetFaces(i, 0).v3 - 1;
                int ind_vnB = this->GetFaces(i, 1).v3 - 1;
                int ind_vnC = this->GetFaces(i, 2).v3 - 1;
                point3 normal_A(this->GetNormals(ind_vnA).nx, this->GetNormals(ind_vnA).ny, this->GetNormals(ind_vnA).nz);
                point3 normal_B(this->GetNormals(ind_vnB).nx, this->GetNormals(ind_vnB).ny, this->GetNormals(ind_vnB).nz);
                point3 normal_C(this->GetNormals(ind_vnC).nx, this->GetNormals(ind_vnC).ny, this->GetNormals(ind_vnC).nz);

                vertex vA(A, normal_A), vB(B, normal_B), vC(C, normal_C);
                triangle t = triangle(vA, vB, vC, mat);
                triangle_list.push_back(t);
            }
        }

        return triangle_list;
    }