#pragma once

#include "Vector3.hpp"

float Min( float fR, float fG, float fB )
{
    float fMin = fR;
    if (fG < fMin){
        fMin = fG;
    }
    if (fB < fMin){
        fMin = fB;
    }
    return fMin;
}

float Max( float fR, float fG, float fB)
{
    float fMax = fR;
    if (fG > fMax){
        fMax = fG;
    }
    if (fB > fMax){
        fMax = fB;
    }
    return fMax;
}

vec3 rgbToHSL(vec3 rgb)
{
	float H, S, L;

    float fR = rgb.x / 255.0;
    float fG = rgb.y / 255.0;
    float fB = rgb.z / 255.0;

    float fCMin = Min(fR, fG, fB);
    float fCMax = Max(fR, fG, fB);

    L = 50 * (fCMin + fCMax);

    if (fCMin == fCMax) {
        S = 0;
        H = 0;
        return {H, S, L};

    } else if (L < 50){
        S = 100 * (fCMax - fCMin) / (fCMax + fCMin);
    } else{
        S = 100 * (fCMax - fCMin) / (2.0 - fCMax - fCMin);
    }

    if (fCMax == fR){
        H = 60 * (fG - fB) / (fCMax - fCMin);
    } else if (fCMax == fG){
        H = 60 * (fB - fR) / (fCMax - fCMin) + 120;
    } else if (fCMax == fB){
        H = 60 * (fR - fG) / (fCMax - fCMin) + 240;
    }
    
    if (H < 0){
        H = H + 360;
    }

	return {H, S, L};
}