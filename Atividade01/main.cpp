#include <iostream>
#include "includes/ImageIO.h"

int main() {
    ImageIO imageIO(256, 256);

    imageIO.makeGradient();

    // create a circle with color red (255, 0, 0)
    imageIO.makeCircle(128, 128, 100, 255, 0, 0);

    return 0;
}
