#include "lodepng.h"
#include <iostream>

#include "ImageIO.h"

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

void ImageIO::makeCircle(int centerX, int centerY, int radius, unsigned char r, unsigned char g, unsigned char b) {
    // Ensure that the radius is non-negative
    if (radius < 0) {
        std::cerr << "Invalid radius for the circle." << std::endl;
        return;
    }

     // Fill the image with a black background
    for (int j = 0; j < this->image_height; ++j) {
        for (int i = 0; i < this->image_width; ++i) {
            // Calculate the pixel index in the RGBA image
            size_t index = (i + j * this->image_width) * 4;

            // Fill the background with black
            this->image_data[index] = 0;   // R component
            this->image_data[index + 1] = 0; // G component
            this->image_data[index + 2] = 0; // B component
            this->image_data[index + 3] = 255; // Fully opaque
        }
    }

    for (int j = 0; j < this->image_height; ++j) {
        for (int i = 0; i < this->image_width; ++i) {
            int dx = i - centerX;
            int dy = j - centerY;

            // Check if the pixel (i, j) is inside the circle
            if (dx * dx + dy * dy <= radius * radius) {
                // Calculate the pixel index in the RGBA image
                size_t index = (i + j * this->image_width) * 4;

                // Fill the circle with the specified color
                this->image_data[index] = r; // R component
                this->image_data[index + 1] = g; // G component
                this->image_data[index + 2] = b; // B component
                this->image_data[index + 3] = 255; // Fully opaque
            }
        }
    }

    // Save the modified image
    save_png("circle.png");
}

void ImageIO::makeSquare(int x, int y, int size, unsigned char r, unsigned char g, unsigned char b) {
    // Ensure that the size is non-negative
    if (size < 0) {
        std::cerr << "Invalid size for the square." << std::endl;
        return;
    }

    // Calculate the coordinates of the square's top-left and bottom-right corners
    int x1 = x;
    int y1 = y;
    int x2 = x + size;
    int y2 = y + size;

    // Fill the image with a black background
    for (int j = 0; j < this->image_height; ++j) {
        for (int i = 0; i < this->image_width; ++i) {
            // Calculate the pixel index in the RGBA image
            size_t index = (i + j * this->image_width) * 4;

            // Fill the background with black
            this->image_data[index] = 0;   // R component
            this->image_data[index + 1] = 0; // G component
            this->image_data[index + 2] = 0; // B component
            this->image_data[index + 3] = 255; // Fully opaque
        }
    }

    // Draw the colored square on the black background
    for (int j = y1; j < y2; ++j) {
        for (int i = x1; i < x2; ++i) {
            // Check if the pixel (i, j) is inside the square
            if (i >= 0 && i < this->image_width && j >= 0 && j < this->image_height) {
                // Calculate the pixel index in the RGBA image
                size_t index = (i + j * this->image_width) * 4;

                // Fill the square with the specified color
                this->image_data[index] = r; // R component
                this->image_data[index + 1] = g; // G component
                this->image_data[index + 2] = b; // B component
                this->image_data[index + 3] = 255; // Fully opaque
            }
        }
    }

    // Save the modified image
    save_png("square.png");
}
