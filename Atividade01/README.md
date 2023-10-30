# Atividade 01

Este projeto consiste em uma aplicação C++ que gera imagens em formato PNG. Ele oferece a funcionalidade de criar imagens de gradiente suave, desenhar círculos e quadrados coloridos em um plano de fundo personalizável. As imagens resultantes são úteis para várias aplicações gráficas e podem ser facilmente integradas em projetos maiores.

Ao executar o programa, as imagens geradas serão salvas na pasta *outputs*

## Instalação no Macbook

- instalar [Quartz](https://www.xquartz.org/)

- Lib para processamento de imagem
```powershell
$ brew install cimg
```
- Lib para salvar em PNG
```powershell
$ git clone https://github.com/lvandeve/lodepng.git
```

- Rodar programa
```powershell
$ g++ -o output main.cpp includes/ImageIO.cpp -I../lodepng ../lodepng/lodepng.cpp -Wall
$ ./output
```