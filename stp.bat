cls
g++ -c sfmlDemo.cpp -I src/include
g++ -o sfmlDemo sfmlDemo.o -L src/lib -lsfml-graphics-d -lsfml-window-d -lsfml-system-d -lwinmm -lgdi32
sfmlDemo