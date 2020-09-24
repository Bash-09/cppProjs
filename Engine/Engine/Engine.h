#pragma once

#include <iostream>

#include "Platform/Platform.h"
#include "Loop.h"
#include "Main.h"

namespace Engine {

    int FPS() {return Loop::FPS();}

    void start() {
        Platform::initWindow();
        init();
        Loop::loop();
        destroy();
    }

}