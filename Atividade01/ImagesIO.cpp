#include "ImageIO.h"
#include "lodepng.h"
#include <iostream>

// Constructor definition
ImageIO::ImageIO(int image_width, int image_height) {
    this->image_width = image_width;
    this->image_height = image_height;
    // Create a vector to store the image pixels (RGBA)
    this->image_data = std::vector<unsigned char>(image_width * image_height * 4);
}

// Member function to save PNG
void ImageIO::save_png(const char *filename) {
    // Save the image in PNG format using lodepng
    if (lodepng::encode(filename, this->image_data, this->image_width, this->image_height) == 0) {
        std::cout << "PNG image created successfully: " << filename << std::endl;
    } else {
        std::cerr << "Error creating PNG image." << std::endl;
    }
}

// Member function to create gradient
void ImageIO::makeGradient() {
    // Fill the image with the gradient
    for (int j = 0; j < this->image_height; ++j) {
        for (int i = 0; i < this->image_width; ++i) {
            unsigned char r = static_cast<unsigned char>(255.999 * double(i) / (this->image_width - 1));
            unsigned char g = static_cast<unsigned char>(255.999 * double(j) / (this->image_height - 1));
            unsigned char b = static_cast<unsigned char>(0);
            unsigned char a = static_cast<unsigned char>(255); // Alpha (transparency) = 255 (opaque)

            // Calculate the pixel index in the RGBA image
            size_t index = (i + j * this->image_width) * 4;

            // Fill the color values in the image data vector
            this->image_data[index] = r;
            this->image_data[index + 1] = g;
            this->image_data[index + 2] = b;
            this->image_data[index + 3] = a;
        }
    }

    save_png("gradient.png");
}
