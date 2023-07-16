#include <MathLib/VectorFuncs.hpp>
#include <iostream>
#include <windows.h>
#include <sstream>

std::string pixel(vec3 r){
    std::stringstream ss;
    ss << "\033[48;2;" << abs(clamp(0, 255, round(r.x))) << ";" << abs(clamp(0, 255, round(r.y))) <<";" << abs(clamp(0, 255, round(r.z))) <<"m "<<"\033[0;0m";
    return ss.str();
}

class Screen{
    public:

    HANDLE buffer1, buffer2;
    DWORD buffWritten1, buffWritten2;
    int ActiveBuffer = 0;
    Screen(){
        buffer1 = GetStdHandle(STD_OUTPUT_HANDLE);
        buffer2 = CreateConsoleScreenBuffer(GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    }

    void Write(std::string &s){
        WriteConsole(ActiveBuffer == 0 ? buffer1 : buffer2,
                     s.c_str(),
                     s.size(),
                     ActiveBuffer == 0 ? &buffWritten1 : &buffWritten2,
                     NULL);
    }

    void ShowBuffer(){
        SetConsoleCursorPosition(ActiveBuffer == 0 ? buffer1 : buffer2, {0, 0});
    }

    void SwapBuffers(){
        SetConsoleActiveScreenBuffer(ActiveBuffer == 0 ? buffer1 : buffer2);
        ActiveBuffer == 0 ? ActiveBuffer = 1 : ActiveBuffer = 0;
    }

    void quit(){
        CloseHandle(buffer1);
        CloseHandle(buffer2);
    }
};