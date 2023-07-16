#pragma once

#include <vector>
#include <cmath>

float clamp(float a, float b, float v){
    return std::min(std::max(v, a), b);
}

float sign(float a) { return (0 < a) - (a < 0); }
float step(float edge, float x) { return x > edge; }