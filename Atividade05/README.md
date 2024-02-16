# Atividade 04

**Descrição:**

Este projeto consiste na implementação de um sistema de renderização de imagens usando ray tracing, seguindo o tutorial disponível em [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html). O objetivo principal é criar uma cena tridimensional e renderizá-la de dois pontos de vista diferentes, utilizando pelo menos três objetos com material difuso.

Para isso, o projeto utiliza conceitos de geometria computacional, álgebra linear e física da luz para simular o comportamento dos raios de luz ao interagirem com objetos na cena. O material difuso é implementado, utilizando a informação da normal do modelo para determinar a reflexão da luz em cada ponto da superfície.

Além disso, o projeto faz uso de arquivos contendo informações de normais dos modelos para criar uma representação mais realista das superfícies dos objetos. A cena é visualizada a partir de dois pontos de vista diferentes, proporcionando uma experiência de visualização abrangente e detalhada.

Ao implementar o material difuso e utilizar as informações de normal do modelo, o projeto busca criar uma cena visualmente atraente e realista, demonstrando os princípios fundamentais do ray tracing e oferecendo uma introdução prática à computação gráfica.


**Exemplo de Uso:**

- adicionar Lib para salvar em PNG
```powershell
$ git clone https://github.com/lvandeve/lodepng.git
```

- compilar e executar o código, as imagens serão salvas na pasta `/outputs`
```bash
$ g++ -std=c++11 -o output main.cpp  
$ ./output
```