/**
 * @file main.cpp
 * @author Renan Oliveira de Barros Lima
 * @brief Um exemplo de uso da classe ImageIO para gerar imagens com gradientes, círculos e quadrados.
 */

#include <iostream>
#include "includes/ImageIO.h"

int main() {
    ImageIO imageIO(256, 256);

    // Gere um gradiente
    imageIO.makeGradient();

    // Crie um círculo vermelho (r=255, g=0, b=0) com raio 100 e centro (128, 128)
    imageIO.makeCircle(128, 128, 100, 255, 0, 0);

    // Crie um quadrado vermelho (r=255, g=0, b=0) com coordenadas (100, 100) e tamanho 50x50
    imageIO.makeSquare(100, 100, 50, 255, 0, 0);

    return 0;
}
