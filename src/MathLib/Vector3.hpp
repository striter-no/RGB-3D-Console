#pragma once

#include "Vector2.hpp"

class vec3{
    public:

    float x, y, z;
    vec3(float a){x = a; y = a; z = a;}
    vec3(vec2 v, float a){x = v.x; y = v.y; z = a;}
    vec3(float a, vec2 v){x = a; y = v.x; z = v.y;}
    vec3(float x_, float y_, float z_){x = x_; y = y_; z = z_;}
    vec3(){x = 0; y = 0; z = 0;};
};

vec3 operator+(vec3 a, vec3 b){ return { a.x + b.x, a.y + b.y, a.z + b.z}; }
vec3 operator-(vec3 a, vec3 b){ return { a.x - b.x, a.y - b.y, a.z - b.z}; }
vec3 operator/(vec3 a, vec3 b){ return { a.x / b.x, a.y / b.y, a.z / b.z}; }
vec3 operator*(vec3 a, vec3 b){ return { a.x * b.x, a.y * b.y, a.z * b.z}; }

void operator+=(vec3 a, vec3 b){a.x += b.x; a.y += b.y; a.z += b.z; }
void operator-=(vec3 a, vec3 b){a.x -= b.x; a.y -= b.y; a.z -= b.z; }
void operator/=(vec3 a, vec3 b){a.x /= b.x; a.y /= b.y; a.z /= b.z; }
void operator*=(vec3 a, vec3 b){a.x *= b.x; a.y *= b.y; a.z *= b.z; }

vec3 operator+(vec3 a, float b){ return { a.x + b, a.y + b, a.z + b}; }
vec3 operator-(vec3 a, float b){ return { a.x - b, a.y - b, a.z - b}; }
vec3 operator/(vec3 a, float b){ return { a.x / b, a.y / b, a.z / b}; }
vec3 operator*(vec3 a, float b){ return { a.x * b, a.y * b, a.z * b}; }

vec3 operator+(float b, vec3 a){ return { b + a.x, b + a.y, b + a.z}; }
vec3 operator-(float b, vec3 a){ return { b - a.x, b - a.y, b - a.z}; }
vec3 operator/(float b, vec3 a){ return { b / a.x, b / a.y, b / a.z}; }
vec3 operator*(float b, vec3 a){ return { b * a.x, b * a.y, b * a.z}; }

void operator+=(vec3 a, float b){a.x += b; a.y += b; a.z += b; }
void operator-=(vec3 a, float b){a.x -= b; a.y -= b; a.z -= b; }
void operator/=(vec3 a, float b){a.x /= b; a.y /= b; a.z /= b; }
void operator*=(vec3 a, float b){a.x *= b; a.y *= b; a.z *= b; }

bool operator==(vec3 a, vec3 b){ return a.x == b.x && a.y == b.y && a.z == b.z; }
vec3 operator-(vec3 a){ return {-a.x, -a.y, -a.z}; }