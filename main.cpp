#include "ConLib/Console.hpp"
#include "Shaders/Frag.hpp"

int main(){
    Frag shader;
    Console<Frag> console(shader, {240, 60}); // 500 290

    while(true){
        console.Update();
    }
}