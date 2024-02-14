# Atividade 04

**Descrição:**

Tutorial 1: https://raytracing.github.io/books/RayTracingInOneWeekend.html
Tutorial 2: https://raytracing.github.io/books/RayTracingTheNextWeek.html

1) Siga o "tutorial 1" até a seção 5
2) Implemente a visualização da esfera, integrando com as implementações anteriores (Atividade 1 e Atividade 2)
3) Veja a seção 6.2 do "tutorial 2"
4) Implemente a visualização de um triângulo
5) Com a implementação da Atividade 3, visualize um objeto todo, lido de um arquivo
6) Documente adequadamente

Realiza a visualização da esfera, utilizando as Classes de manipulação de vetores das Atividades 1 e 2.

**Recursos:**


**Exemplo de Uso:**

```bash
$ g++ -o output main.cpp includes/*.cpp  -Wall
$ ./output
```

**Testes Unitários:**

Os testes unitários são realizados usando o Google Test (gtest). Certifique-se de que o ambiente esteja configurado corretamente antes de executar os testes.

```bash
$ g++ -std=c++14 run_tests.cpp tests/*.cpp includes/*.cpp -lgtest -lgtest_main -pthread -o run_tests
$ ./run_tests
```