#include "Screen.hpp"
#include <Shaders/Shader.hpp>
#include <chrono>
#include <thread>
#include <mutex>

template<class TShader>
void calcFrame(string &frame, TShader &mainShader, vec2 res, int y){
    //static mutex m;
    //m.lock();
    for(int x = 0; x < res.x; x++){
        frame+=pixel(mainShader.frag({x / res.x, y / res.y}, res) * 255);
    }
    frame+="\n";
    //m.unlock();
}

template<class TShader>
class Console{
    public:

    Screen screen;
    TShader mainShader;
    vec2 res;
    float time = 0;
    int frames = 0;
    int fps = 0;

    Console(TShader mainShader_, vec2 res_){
        system("cls");
        mainShader = mainShader_;
        res = res_;

        mainShader.OnStart();
    }

    void Update(){

        if(time >= 1000){
            fps = frames;
            frames = 0;
            time = 0;
        }

        auto begin = chrono::steady_clock::now();

        screen.ShowBuffer();
        string frame;
        
        //vector<thread> threads(res.y);
        for(int y = 0; y < res.y; y++){
            for(int x = 0; x < res.x; x++){
                frame+=pixel(mainShader.frag({(float)x, (float)y}, res) * 255);
            }
            frame+="\n";
        }

        frame += "FPS: "+to_string(fps);
        mainShader.OnUpdate(frame, screen.ActiveBuffer == 0 ? screen.buffer1 : screen.buffer2, screen.ActiveBuffer);

        screen.Write(frame);
        screen.SwapBuffers();
        
        auto end = chrono::steady_clock::now();
        auto elapsed_s = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        time += elapsed_s.count();
        frames++;
    }

    Console(){}
};

//calcFrame<TShader>(frame, mainShader, res, y);
//hreads.at(y) = thread(calcFrame<TShader>, ref(frame), ref(mainShader), res, y);
//threads.at(y).join();

//frame += pixel(getPixelOnImage(img, {x * aspect.x, y * aspect.y}, pwidth));