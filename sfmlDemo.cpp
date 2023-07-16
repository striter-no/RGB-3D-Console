#include <SFML/Graphics.hpp>
#include <Shaders/Frag.hpp>
#include <chrono>
using namespace sf;

void drawPixel(vec3 clr, vec2 pos, RenderWindow &wind){
    RectangleShape pix;
    pix.setFillColor({clr.x, clr.y, clr.z});
    pix.setPosition({pos.x, pos.y});
    pix.setSize({1, 1});
    wind.draw(pix);
}

int main(){
    RenderWindow window(VideoMode(700, 500), "Window");
    window.setFramerateLimit(60);

    float time = 0;
    int frames = 0;
    int tick = 0;
    int fps = 0;

    Frag mainShader;
    vec2 res = {700, 500};

    while(window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            switch (event.type){
                case Event::Closed:
                    window.close();
                    break;
            }
        }

        window.clear();

        if(time >= 1000){
            fps = frames;
            frames = 0;
            time = 0;
        }

        window.setTitle("FPS: " + to_string(fps) + " Tick: " + to_string(tick));

        auto begin = chrono::steady_clock::now();

        for(int y = 0; y < res.y; y++){
            for(int x = 0; x < res.x; x++){
                vec3 o = mainShader.frag({(float)x, (float)y}, res) * 255;
                //cout<<o.x<<" "<<o.y<<" "<<o.z<<endl;
                drawPixel(o, {x, y},window);
            }
        }

        mainShader.OnUpdate();
        
        auto end = chrono::steady_clock::now();
        auto elapsed_s = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        time += elapsed_s.count();
        frames++;
        tick++;

        window.display();
    }
}