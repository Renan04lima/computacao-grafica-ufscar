/**
 * @file ImageIO.h
 * @author Renan Oliveira de Barros Lima
 * @brief Uma classe que permite a criação de imagens em formato PNG com funcionalidades de gradiente, círculos e quadrados.
 */

#ifndef IMAGEIO_H
#define IMAGEIO_H

#include <vector>

class ImageIO {
private:
    int image_width;
    int image_height;
    std::vector<unsigned char> image_data;

    /**
     * @brief Preenche o plano de fundo da imagem com uma cor RGBA.
     * @param r Componente vermelha (0-255).
     * @param g Componente verde (0-255).
     * @param b Componente azul (0-255).
     * @param a Componente alfa (0-255) para transparência.
     */
    void fill_background(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

public:
    /**
     * @brief Construtor padrão da classe ImageIO.
     * @param image_width A largura da imagem em pixels.
     * @param image_height A altura da imagem em pixels.
     */
    ImageIO(int image_width, int image_height);

    /**
     * @brief Construtor da classe ImageIO.
     * @param image_width A largura da imagem em pixels.
     * @param image_height A altura da imagem em pixels.
     * @param image_data O vetor com os pixels da imagem.
     */
    ImageIO(int image_width, int image_height, const std::vector<unsigned char>& image_data);

    /**
     * @brief Salva a imagem em formato PNG.
     * @param filename O nome do arquivo PNG de saída.
     */
    void save_png(const char *filename);

    /**
     * @brief Gera um gradiente na imagem.
     */
    void makeGradient();

    /**
     * @brief Cria um círculo na imagem com a cor especificada.
     * @param centerX A coordenada x do centro do círculo.
     * @param centerY A coordenada y do centro do círculo.
     * @param radius O raio do círculo.
     * @param r Componente vermelha (0-255) da cor.
     * @param g Componente verde (0-255) da cor.
     * @param b Componente azul (0-255) da cor.
     */
    void makeCircle(int centerX, int centerY, int radius, unsigned char r, unsigned char g, unsigned char b);

    /**
     * @brief Cria um quadrado na imagem com a cor especificada.
     * @param x A coordenada x do canto superior esquerdo do quadrado.
     * @param y A coordenada y do canto superior esquerdo do quadrado.
     * @param size O tamanho do quadrado (largura e altura).
     * @param r Componente vermelha (0-255) da cor.
     * @param g Componente verde (0-255) da cor.
     * @param b Componente azul (0-255) da cor.
     */
    void makeSquare(int x, int y, int size, unsigned char r, unsigned char g, unsigned char b);
};

#endif
