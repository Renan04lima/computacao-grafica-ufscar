#include "gtest/gtest.h"
#include "../includes/ObjLoader.h"

TEST(ObjLoaderTest, LoadObj) {
    ObjLoader objLoader;
    objLoader.LoadObj("/Users/renanoliveira/Desktop/ufscar/Faculdade/Computacao Grafica/2023/Atividade03/tests/mock/mock.obj");

    // Testar o número de vértices, coordenadas de textura, normais e faces
    ASSERT_EQ(objLoader.GetVertices().size(), 3);
    ASSERT_EQ(objLoader.GetTextureCoords().size(), 3);
    ASSERT_EQ(objLoader.GetNormals().size(), 3);
    ASSERT_EQ(objLoader.GetFaces().size(), 1);

    // Testar os valores de alguns vértices, coordenadas de textura, normais e faces
    Vertex vertex = objLoader.GetVertices()[0];
    ASSERT_FLOAT_EQ(vertex.x, 1.0);
    ASSERT_FLOAT_EQ(vertex.y, 0.0);
    ASSERT_FLOAT_EQ(vertex.z, 0.0);

    TextureCoord texCoord = objLoader.GetTextureCoords()[0];
    ASSERT_FLOAT_EQ(texCoord.u, 0.0);
    ASSERT_FLOAT_EQ(texCoord.v, 0.0);

    Normal normal = objLoader.GetNormals()[0];
    ASSERT_FLOAT_EQ(normal.nx, 1.0);
    ASSERT_FLOAT_EQ(normal.ny, 1.0);
    ASSERT_FLOAT_EQ(normal.nz, 1.0);
}
