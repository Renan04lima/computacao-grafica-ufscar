# Atividade 01

- fazer o output de uma imagem png

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
$ g++ -o ImagesIO ImagesIO.cpp -I../lodepng ../lodepng/lodepng.cpp -Wall -Wextra -pedantic -ansi -O3
$ ./ImagesIO
```
