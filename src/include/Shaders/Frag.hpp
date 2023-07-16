#include "Shader.hpp"

vec3 RayOrigin = vec3(-3, 1, 1), 
     RayDirection, 
     LightDirection = vec3(-1, 1, -1),
     LightColor = vec3(1, 1, 1);

vec2 res_;
vec3 n;

int tick = 0;

class Frag : public con::Shader{
    public:

    bool LightOn = true;

    vec3 frag(vec2 uv, vec2 res){
        uv /= res;
        uv -= 0.5;
        uv.x *= res.x / res.y;
        //uv.y *= 2.3;
        res_ = res;

        RayOrigin = vec3(-13, 0, -1);
        RayDirection = norm({2, uv});

        RayOrigin = rotateY(RayOrigin, 0.25);
        RayDirection = rotateY(RayDirection, 0.25);

        RayOrigin = rotateZ(RayOrigin, tick * 0.01);
        RayDirection = rotateZ(RayDirection, tick * 0.01);

        n = 0;

        vec3 pixel = vec3(0, 0, 0), 
            color = vec3(0.2, 0.7, 1);
        
        vec2 it;
        vec3 pos;

        float diff = 1;
        for(int i = 0; i < 1; i++){
            float minIt = 9999;

            pos = vec3(1, 0, 0);
            it = sphereIntersect(RayOrigin - pos, RayDirection, 1);
            if(it.x > 0 && it.x < minIt){
                vec3 itPos = RayOrigin - pos + RayDirection * it.x;
                n = norm(itPos);

                minIt = it.x;

                color = vec3(1, 1, 0);
            }

            pos = vec3(-3, 0, 0);
            it = sphereIntersect(RayOrigin - pos, RayDirection, 1);
            if(it.x > 0 && it.x < minIt){
                vec3 itPos = RayOrigin - pos + RayDirection * it.x;
                n = norm(itPos);
                minIt = it.x;

                color = vec3(1, 0, 1);
            }

            //pos = vec3(1, 0, 0);
            vec3 bn = 0;
            it = boxIntersect(RayOrigin, RayDirection, 1, bn);
            if(it.x > 0 && it.x < minIt){
                n = bn;
                //cout<<n.x<<" "<<n.y<<" "<<n.z<<endl;
                minIt = it.x;
                color = vec3(0, 1, 0);
            }

            
            it = vec2(planeIntersect(RayOrigin, RayDirection, vec3(0, 0, -1), 1));
            if(it.x > 0 && it.x < minIt){
                n = vec3(0, 0, -1);
                minIt = it.x;
            
                color = vec3(0.1, 0.1, 0.1);
            }
            
            if(minIt < 9999){
                diff *= (dot(n, LightDirection) * 0.5 + 0.5);
                //RayOrigin += RayDirection * (minIt - 0.001);
                //RayDirection = n;
            }
        }

        pixel = LightColor * color * (LightOn ? diff : 1);

        return {pixel};
    }
    
    /*void OnUpdate(string &frame, HANDLE activeBuffer, int activeBufferInd){
        frame+="\nTick: "+to_string(tick) + 
               "\nResolution: " + to_string((int)res_.x) + " " + to_string((int)res_.y) + 
               "\nRay origin: " + to_string(RayOrigin.x) + " " + to_string(RayOrigin.y) + " " + to_string(RayOrigin.z) + 
               "\nNormal: "  + to_string(n.x) + " " + to_string(n.y) + " " + to_string(n.z) + 
               "\nLight: " + to_string(LightOn);
        tick++;
    }*/
    void OnUpdate(){
        tick++;
    }
};