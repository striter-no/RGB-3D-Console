#pragma once

class vec2{
    public:

    float x, y;
    vec2(float a){x = a; y = a;}
    vec2(float x_, float y_){x = x_; y = y_;}
    vec2(){x = 0; y = 0;};
};

vec2 operator+(vec2 a, vec2 b){ return { a.x + b.x, a.y + b.y}; }
vec2 operator-(vec2 a, vec2 b){ return { a.x - b.x, a.y - b.y}; }
vec2 operator/(vec2 a, vec2 b){ return { a.x / b.x, a.y / b.y}; }
vec2 operator*(vec2 a, vec2 b){ return { a.x * b.x, a.y * b.y}; }

void operator+=(vec2 &a, vec2 b){a.x += b.x; a.y += b.y; }
void operator-=(vec2 &a, vec2 b){a.x -= b.x; a.y -= b.y; }
void operator/=(vec2 &a, vec2 b){a.x /= b.x; a.y /= b.y; }
void operator*=(vec2 &a, vec2 b){a.x *= b.x; a.y *= b.y; }

vec2 operator+(vec2 a, float b){ return { a.x + b, a.y + b}; }
vec2 operator-(vec2 a, float b){ return { a.x - b, a.y - b}; }
vec2 operator/(vec2 a, float b){ return { a.x / b, a.y / b}; }
vec2 operator*(vec2 a, float b){ return { a.x * b, a.y * b}; }

vec2 operator+(float b, vec2 a){ return { b + a.x, b + a.y}; }
vec2 operator-(float b, vec2 a){ return { b - a.x, b - a.y}; }
vec2 operator/(float b, vec2 a){ return { b / a.x, b / a.y}; }
vec2 operator*(float b, vec2 a){ return { b * a.x, b * a.y}; }

void operator+=(vec2 &a, float b){a.x += b; a.y += b; }
void operator-=(vec2 &a, float b){a.x -= b; a.y -= b; }
void operator/=(vec2 &a, float b){a.x /= b; a.y /= b; }
void operator*=(vec2 &a, float b){a.x *= b; a.y *= b; }

bool operator==(vec2 a, vec2 b){ return a.x == b.x && a.y == b.y; }
vec2 operator-(vec2 a){ return {-a.x, -a.y}; }