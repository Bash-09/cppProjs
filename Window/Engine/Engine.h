#pragma once

#include "../Platform/Window.h"
#include "../Renderer/Renderer.h"

#include "Input/Keyboard.h"

class Engine {
public:

    Engine(Window* window, Renderer* rend) : window(window), rend(rend) {

    }
    ~Engine() {
        
    }
    //Just some useful stuff to have.
    Window* window;
    Renderer* rend;

    Keyboard keyboard;

    bool Setup() { //Start stuff
        if(!window->isWindowOpen()) {
            std::cout << "Please create a window before running Setup!\n";
            return false;
        }
        rend->initGL();
        Init();
        return true;
    }

    //Game Loop stuff, bigger than I expected
    void enterLoop(); //Start the game loop on this thread
    void exitLoop(); //Tell the gameloop to stop once it finishes
    bool isGameLoopRunning(); //Well, is the game loop running?
    float frameIntervalLimit = 0.25; //Fraction of a second the fps is updated
    int getFPS(); //Does what it says
private:
    void GameLoop(); //The actual gameloop itself
    bool stopLoop = true; //Checked each frame for if the Gameloop should stop
    bool loopRunning = false; //Updated before and after the loop starts/finishes
    int fps = 0; //Not even gonna write anything here


    //Application stuff to make your own app!
protected:
    virtual void Init() = 0;
    virtual void Update(float delta) = 0;
    virtual void Render() = 0;
    virtual void Close() = 0;

};