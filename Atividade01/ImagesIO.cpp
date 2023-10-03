#include <iostream>
#include <vector>
#include "lodepng.h"

int main() {
    // Dimensões da imagem
    int image_width = 256;
    int image_height = 256;

    // Crie um vetor para armazenar os pixels da imagem (RGBA)
    std::vector<unsigned char> image_data(image_width * image_height * 4);

    // Preencha a imagem com o gradiente
    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            unsigned char r = static_cast<unsigned char>(255.999 * double(i) / (image_width - 1));
            unsigned char g = static_cast<unsigned char>(255.999 * double(j) / (image_height - 1));
            unsigned char b = static_cast<unsigned char>(0);
            unsigned char a = static_cast<unsigned char>(255); // Alpha (transparência) = 255 (opaco)

            // Calcule o índice do pixel na imagem RGBA
            size_t index = (i + j * image_width) * 4;

            // Preencha os valores de cor no vetor de imagem
            image_data[index] = r;
            image_data[index + 1] = g;
            image_data[index + 2] = b;
            image_data[index + 3] = a;
        }
    }

    // Salve a imagem em formato PNG usando lodepng
    if (lodepng::encode("gradient.png", image_data, image_width, image_height) == 0) {
        std::cout << "Imagem PNG criada com sucesso: gradient.png" << std::endl;
    } else {
        std::cerr << "Erro ao criar a imagem PNG." << std::endl;
    }

    return 0;
}
