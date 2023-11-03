#include <iostream>
#include "includes/vec2.h"
#include "includes/vec3.h"
#include "includes/vec4.h"
#include "includes/mat2.h"
#include "includes/mat3.h"
#include "includes/mat4.h"

int main() {
    // Example usage of vec2
    vec2 v2(1, 2);
    std::cout << "v2: " << v2 << std::endl;

    // Example usage of vec3
    vec3 v3_1(1.0, 2.0, 3.0);
    vec3 v3_2(4.0, 5.0, 6.0);

    std::cout << "v3_1: " << v3_1 << std::endl;
    std::cout << "v3_2: " << v3_2 << std::endl;

    vec3 v3 = v3_1 + v3_2;
    std::cout << "v3_1 + v3_2: " << v3 << std::endl;

    vec3 v4 = v3_1 * 2.0;
    std::cout << "v3_1 * 2.0: " << v4 << std::endl;

    double dot_product = dot(v3_1, v3_2);
    std::cout << "Dot product of v3_1 and v3_2: " << dot_product << std::endl;

    vec3 cross_product = cross(v3_1, v3_2);
    std::cout << "Cross product of v3_1 and v3_2: " << cross_product << std::endl;

    // Criar um objeto vec4 usando o construtor padrão (inicialização padrão)
    vec4 v4_1;
    std::cout << "v4_1: (" << v4_1.x() << ", " << v4_1.y() << ", " << v4_1.z() << ", " << v4_1.w << ")" << std::endl;

    // Criar um objeto vec4 usando o construtor personalizado
    vec4 v4_2(1.0, 2.0, 3.0, 4.0);
    std::cout << "v4_2: (" << v4_2.x() << ", " << v4_2.y() << ", " << v4_2.z() << ", " << v4_2.w << ")" << std::endl;

    // Realizar operações com vetores 4D
    vec4 result = v4_1 + v4_2;
    std::cout << "v4_1 + v4_2: (" << result.x() << ", " << result.y() << ", " << result.z() << ", " << result.w << ")" << std::endl;

    // Atribuição
    v4_1 = v4_2;
    std::cout << "v4_1 after assignment: (" << v4_1.x() << ", " << v4_1.y() << ", " << v4_1.z() << ", " << v4_1.w << ")" << std::endl;


    // Example usage of mat2
    vec2 row0(1, 2);
    vec2 row1(3, 4);
    mat2 m2(row0, row1);
    std::cout << "mat2:\n" << m2 << std::endl;

    // Example usage of mat3
    vec3 row0_3(1, 2, 3);
    vec3 row1_3(4, 5, 6);
    vec3 row2_3(7, 8, 9);
    mat3 m3(row0_3, row1_3, row2_3);
    std::cout << "mat3:\n" << m3 << std::endl;

    // Example usage of mat4
    vec4 row0_4(1, 2, 3, 4);
    vec4 row1_4(5, 6, 7, 8);
    vec4 row2_4(9, 10, 11, 12);
    vec4 row3_4(13, 14, 15, 16);
    mat4 m4(row0_4, row1_4, row2_4, row3_4);
    std::cout << "mat4:\n" << m4 << std::endl;



    return 0;
}
