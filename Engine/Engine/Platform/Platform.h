#pragma once

#include <string>
#include <iostream>
#include <SDL2/SDL.h>

#include "Keyboard.h"
#include "Mouse.h"

namespace Platform {

    //Creates window
    bool initWindow(int screenWidth = 640, int screenHeight = 480, char* title = "Hello World");
    void closeWindow();

    bool handleInput();

}