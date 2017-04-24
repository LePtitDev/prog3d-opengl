#include "IMGLoader.hpp"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

unsigned char * IMG_Load(const char * fname, int& w, int& h, int& ch) {
    return stbi_load(fname, &w, &h, &ch, ch);
}