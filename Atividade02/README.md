# Atividade 02

Este projeto é uma biblioteca abrangente para operações vetoriais e matriciais, projetada principalmente para aplicações gráficas 2D e 3D. Inclui a implementação das classes vec2, vec3, vec4, mat2, mat3 e mat4, cada uma representando vetores e matrizes de suas respectivas dimensões.

A biblioteca fornece operações aritméticas básicas para essas estruturas matemáticas, como adição, subtração e multiplicação. Também inclui operações mais complexas, como produto escalar e produto vetorial para vetores e transformações de matriz.

O código é escrito em C++, aderindo aos padrões e práticas de codificação modernos. Ele foi projetado para ser fácil de integrar em outros projetos, fornecendo uma base sólida para qualquer projeto gráfico ou de desenvolvimento de jogos que exija operações vetoriais e matriciais.

## Instalação no Macbook

- instalar e configurar [Google Test](https://alexanderbussan.medium.com/getting-started-with-google-test-on-os-x-a07eee7ae6dc)
```

- Rodar testes
```powershell
$  g++ -std=c++14 main.cpp tests/*.cpp includes/*.cpp -lgtest -lgtest_main -pthread -o output  
$ ./output
```