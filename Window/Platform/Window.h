#pragma once

#include <SDL2/SDL_opengl.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <string>

/*
Start by Creating a window:
window.createWindow();

*/

class Window {
public:
    Window();
    ~Window();

    void createWindow(const std::string& title = "Hello World", uint32_t screenWidth = 600, uint32_t screenHeight = 400, bool vsync = true);
    void updateWindow();
    void closeWindow();

    int getWidth();
    int getHeight();

    void quit();

private:
    SDL_Window* window = nullptr;
    SDL_GLContext glContext = nullptr;



};

