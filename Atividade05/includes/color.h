/**
 * @file color.h
 * @brief Arquivo de implementação da classe Color
 */

#ifndef COLOR_H
#define COLOR_H

#include "../../Atividade02/includes/vec3.h"
#include "../../Atividade02/includes/vec3.cpp"
#include <iostream>

using color = vec3;

/**
 * @brief Função para transformar um componente linear para o espaço gamma.
 * 
 * @param linear_component Componente linear a ser transformado.
 * @return double Componente transformado no espaço gamma.
 */
inline double linear_to_gamma(double linear_component)
{
    return sqrt(linear_component);
}

/**
 * @brief Escreve a cor de um pixel em um formato de imagem (PPM).
 * 
 * @param out Saída para o arquivo PPM.
 * @param pixel_color Vetor de cor representando a cor do pixel.
 * @param samples_per_pixel Número de amostras por pixel na imagem.
 */
void write_color(std::ostream &out, color pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    auto scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    // Transformação para o espaço gamma.
    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    // Limita os valores ao intervalo [0, 255].
    static const interval intensity(0.000, 0.999);
    out << static_cast<int>(256 * intensity.clamp(r)) << ' '
        << static_cast<int>(256 * intensity.clamp(g)) << ' '
        << static_cast<int>(256 * intensity.clamp(b)) << '\n';
}

#endif
