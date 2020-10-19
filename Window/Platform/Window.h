#pragma once

#include <SDL2/SDL_opengl.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <string>

#include "../Engine/Input/Keyboard.h"
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

    bool getInput(Keyboard* eng);

    void quit();

    bool isWindowOpen();

private:
    bool windowOpen = false;

};

