#pragma once

#include "VectorFuncs.hpp"

vec2 sphereIntersect(vec3 ro, vec3 rd, float ra){
    float b = dot(ro, rd);
    float c = dot(ro, ro) - ra * ra;
    float h = b * b - c;
    if(h < 0.f) return vec2(-1, -1);
    h = sqrt(h);
    return vec2(-b - h, -b + h);
}

vec2 boxIntersect(vec3 ro, vec3 rd, vec3 boxSize, vec3& outNormal) {
    vec3 m = vec3(1) / rd;
    vec3 n = m * ro;
    vec3 k = abs(m) * boxSize;
    vec3 t1 = -n - k;
    vec3 t2 = -n + k;
    float tN = max(max(t1.x, t1.y), t1.z);
    float tF = min(min(t2.x, t2.y), t2.z);
    if (tN > tF || tF < 0.0) return vec2(-1);
    vec3 yzx = vec3(t1.y, t1.z, t1.x);
    vec3 zxy = vec3(t1.z, t1.x, t1.y);
    outNormal = -sign(rd) * step(yzx, t1) * step(zxy, t1);
    return vec2(tN, tF);
}

float planeIntersect(vec3 ro, vec3 rd, vec3 p, float w){
    return -(dot(ro, p) + w) / dot(rd, p);
}