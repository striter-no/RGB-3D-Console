#pragma once

#include <iostream>
#include <MathLib/VectorFuncs.hpp>
#include <MathLib/IntersectionFormulas.hpp>

using namespace std;

class Shader{
    public:

    int tick = 0;

    Shader(){}

    void OnStart(){
        ;
    }

    vec3 frag(vec2 uv, vec2 resolution){
        ;
    }

    void OnUpdate(string &frame){
        tick++;
    }
};