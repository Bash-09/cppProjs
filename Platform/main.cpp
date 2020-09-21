#include "Platform.h"

/*

Engine would prolly work well as SDL2 + OpenAL if I ever wanna add audio

*/
const int screenWidth = 640;
const int screenHeight = 480;

bool quit = false;
SDL_Event e;

using namespace Plat;

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
                std::cout << e.key.keysym << "\n";
            }

        }



    }


//        SDL_UpdateWindowSurface( window );

    exit();

    return 0;
}