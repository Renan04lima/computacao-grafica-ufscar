#include <iostream>
#include "includes/ImageIO.h"

int main() {
    ImageIO imageIO(256, 256);

    imageIO.makeGradient();

    // create a circle with color red (r=255, g=0, b=0) with radius 100 and center (128, 128)
    imageIO.makeCircle(128, 128, 100, 255, 0, 0);

     // create a square red (r=255, g=0, b=0) with coordinates (100, 100) and size 50x50
    imageIO.makeSquare(100, 100, 50, 255, 0, 0);

    return 0;
}
