#include <math.h>
#include <stdio.h>

void convert_to_YCrCb(unsigned char *rgb_pixels, unsigned char *ycc_pixels, int width, int height) {
    if (width <= 0 || height <= 0) {
        //dimensions zero
        return;
    }

    int pixels = width * height;
    for (int i = 0; i < pixels; i++) {
        unsigned char r = rgb_pixels[3 * i];
        unsigned char g = rgb_pixels[3 * i + 1];
        unsigned char b = rgb_pixels[3 * i + 2];

        //calculate y, cb, and cr
        unsigned char y = (unsigned char)round(0.299 * r + 0.587 * g + 0.114 * b);
        unsigned char cb = (unsigned char)round(128 - 0.168736 * r - 0.331264 * g + 0.5 * b);
        unsigned char cr = (unsigned char)round(128 + 0.5 * r - 0.418688 * g - 0.081312 * b);

        ycc_pixels[3 * i] = y;
        ycc_pixels[3 * i + 1] = cb;
        ycc_pixels[3 * i + 2] = cr;
    }
}