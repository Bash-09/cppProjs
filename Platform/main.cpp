#include "Platform.h"

#include <thread>
#include <chrono>

/*

Engine would prolly work well as SDL2 + OpenAL if I ever wanna add audio

*/
const int screenWidth = 640;
const int screenHeight = 480;

bool quit = false;
SDL_Event e;

using namespace Platform;

int main() {

    if(!init(screenWidth, screenHeight, "Hello World")) return 0;

    

    //Main window loop
    while(!quit) {
        //Poll events
        while( SDL_PollEvent( &e ) != 0) {
            //Quit button
            if(e.type == SDL_QUIT) {
                quit = true;
            }
            if(e.type == SDL_KEYDOWN) {
                Keyboard::press(e.key.keysym.sym);
            }
            if(e.type == SDL_KEYUP) {
                Keyboard::release(e.key.keysym.sym);
            }

        }

        std::cout << Keyboard::isPressed(Keyboard::Key::a) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }


//        SDL_UpdateWindowSurface( window );

    exit();

    return 0;
}