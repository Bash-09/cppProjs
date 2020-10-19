#include <chrono>

#include "Engine.h"

bool Engine::isGameLoopRunning() {
    return loopRunning;
}
int Engine::getFPS() {
    return fps;
}

void Engine::enterLoop() {
    GameLoop();
}

void Engine::exitLoop() {
    stopLoop = true;
}

int frames = 0; //Number of frames in last interval
float frameInterval = 0; //Time during this interval

void Engine::GameLoop() {
    using clock = std::chrono::steady_clock;

    stopLoop = false; //Set some flags
    loopRunning = true;

    auto last = clock::now();
    while(!stopLoop) { //Start the loop
        auto now = clock::now(); //Get time delta
        auto delta = now - last;

        if(delta.count() < 100000) continue; //Check if it should bother doing the loop
        float fract = delta.count() / 1000;
        fract /= 1000000; //Get delta as fraction of a second

        frames++;
        frameInterval += fract; //Calculate fps stuff
        if(frameInterval > frameIntervalLimit) {
            fps = (int)((float)frames/frameInterval);
            frameInterval = 0;
            frames = 0;
        }

        stopLoop = window->getInput(&keyboard);
        Update(fract); //Handle input and then update the game
        Render();

        last = now; //Update time
    }

    loopRunning = false;

}

