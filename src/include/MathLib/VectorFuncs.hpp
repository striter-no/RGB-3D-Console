#pragma once

#include "Vector3.hpp"
#include "AddMath.hpp"

float dot(vec3 a, vec3 b){ return a.x * b.x + a.y * b.y + a.z * b.z; }
float len(vec3 v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }
//float dist(vec3 a, vec3 b){ return sqrtf(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2)); }

vec3 abs(vec3 v){ return {abs(v.x), abs(v.y), abs(v.z)};}
vec3 norm(vec3 a){ return len(a) != 0 ? a / len(a): vec3(0, 0, 0); }
vec3 clamp(float a, float b, vec3 v){ return {clamp(a, b, v.x), clamp(a, b, v.y), clamp(a, b, v.z)}; }
vec3 cross(vec3 a, vec3 b){ return { a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x }; }

vec3 sign(vec3 const& v) { return vec3(sign(v.x), sign(v.y), sign(v.z)); }
vec3 step(vec3 const& edge, vec3 v) { return vec3(step(edge.x, v.x), step(edge.y, v.y), step(edge.z, v.z)); }
vec3 reflect(vec3 rd, vec3 n) { return rd - n * (2 * dot(n, rd)); }
vec3 refract(vec3 vec, vec3 normal, float eta){
    float N_dot_I = dot(normal, vec);
    float k = 1.f - eta * eta * (1.f - N_dot_I * N_dot_I);

    if (k < 0.f)
        return vec3(0.f, 0.f, 0.f);
    else
        return eta * vec - (eta * N_dot_I + sqrtf(k)) * normal;
}

vec3 rotateX(vec3 a, float angle){
    vec3 b = a;
    b.z = a.z * cos(angle) - a.y * sin(angle);
    b.y = a.z * sin(angle) + a.y * cos(angle);
    return b;
}

vec3 rotateY(vec3 a, float angle){
    vec3 b = a;
    b.x = a.x * cos(angle) - a.z * sin(angle);
    b.z = a.x * sin(angle) + a.z * cos(angle);
    return b;
}

vec3 rotateZ(vec3 a, float angle){
    vec3 b = a;
    b.x = a.x * cos(angle) - a.y * sin(angle);
    b.y = a.x * sin(angle) + a.y * cos(angle);
    return b;
}