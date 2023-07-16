#include <MathLib/Vector3.hpp>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class Image{
    public:

    unsigned char *img;
    int width, height, cnt;
    vec2 aspect = vec2(1);

    Image(std::string fileName){
        img = stbi_load(fileName.c_str(), &width, &height, &cnt, 3);
    }

    void calcAspect(vec2 res){
        aspect = res / vec2(width, height);
    }

    vec3 getPixelOnImage(vec2 pos){
        pos *= aspect;
        float r = img[(int)pos.y * width * 3 + (int)pos.x * 3 + 0];
        float g = img[(int)pos.y * width * 3 + (int)pos.x * 3 + 1];
        float b = img[(int)pos.y * width * 3 + (int)pos.x * 3 + 2];
        return {r, g, b};
    }

    Image(){}
};