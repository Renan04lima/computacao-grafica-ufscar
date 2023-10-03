#include "ImageIO.h"
#include <iostream>

int main() {
    ImageIO imageIO(256, 256);

    imageIO.makeGradient();

    return 0;
}
