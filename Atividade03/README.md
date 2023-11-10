# Atividade 03

**Descrição:**

A classe `ObjLoader` é uma implementação em C++ para carregar e processar arquivos no formato Wavefront OBJ. Essa classe permite a leitura de vértices, coordenadas de textura, normais e faces a partir de arquivos `.obj`, fornecendo uma estrutura de dados fácil de usar para manipulação de modelos 3D.

**Recursos:**

- Carrega arquivos OBJ contendo vértices, coordenadas de textura, normais e faces.
- Fácil acesso aos dados carregados através de métodos getters.
- Suporte para testes unitários usando o Google Test (gtest).

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