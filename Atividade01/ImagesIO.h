#ifndef IMAGEIO_H
#define IMAGEIO_H

#include <vector>

class ImageIO {
private:
    int image_width;
    int image_height;
    std::vector<unsigned char> image_data;

    void save_png(const char *filename);

public:
    ImageIO(int image_width, int image_height);

    void makeGradient();
};

#endif
