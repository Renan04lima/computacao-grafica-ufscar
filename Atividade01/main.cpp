#include <iostream>
#include "includes/ImageIO.h"

int main() {
    ImageIO imageIO(256, 256);

    imageIO.makeGradient();

    return 0;
}
