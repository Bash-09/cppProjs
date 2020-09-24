#include "Loop.h"

namespace Loop {

    int fps = 0;
    int frames = 0;
    float frameInterval = 0;
    float frameIntervalLimit = 0.25;

    int FPS() { return fps; }

    bool Running = false;

    void stop() {
        Running = false;
    }

    //Main game loop
    void loop() {
        using clock = std::chrono::steady_clock;
        Running = true;

        frames = 0;

        auto last = clock::now();
        while(Running) {
            auto now = clock::now();
            auto delta = now - last;

            if(delta.count() < 100000) continue; //Don't bother if time is too short
            float fract = delta.count() / 1000;
            fract /= 100000;

            frames++;
            frameInterval += fract;
            if(frameInterval > frameIntervalLimit) {
                fps = frames * 1/frameInterval;
                frames = 0;
                frameInterval = 0;
            }

            Running = Platform::handleInput();
            update(fract);
            render();
            
            Keyboard::nextFrame();
            last = now;
        }
    }


}