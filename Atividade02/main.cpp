#include <iostream>
#include "gtest/gtest.h"

// Inclua seu cabeçalho vec3.h e o arquivo de teste
#include "includes/vec3.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
