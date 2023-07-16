#pragma once

#include <random>

std::random_device RANDOM_DEVICE;
std::mt19937 gen(RANDOM_DEVICE());

int randint(int a, int b){
    std::uniform_int_distribution<> dist(a,b);
    return dist(gen);
}

float uniform(float a, float b){
    std::uniform_int_distribution<> dist(a,b);
    return dist(gen);    
}