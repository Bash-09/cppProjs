#include "Platform.h"

namespace Platform {

    //Create what we need for our window
    SDL_Window* window = nullptr;
    SDL_Surface* screenSurface = nullptr;

    //Creates window
    bool initWindow(int screenWidth, int screenHeight, char* title) {
        //Initialise SDL
        if( SDL_Init(SDL_INIT_EVERYTHING) < 0 ) {
            std::cout << "Could not initialise SDL" << std::endl;
            return 0;
        }
        //Create the window and show it
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
        if( window == nullptr) {
            std::cout << "Could not create window\n";
            return 0;
        }
        //Get the screen surface
        screenSurface = SDL_GetWindowSurface(window);
        return true;
    }

    //Does the closing stuff
    void closeWindow() {

        //Clean up shit and destroy the window
        SDL_FreeSurface(screenSurface);
        screenSurface = nullptr;
        SDL_DestroyWindow(window);
        window = nullptr;
        //Quit SDL
        SDL_Quit();

    }

    SDL_Event e;
    bool handleInput() {
        bool exit = false;
        while( SDL_PollEvent( &e ) != 0) {
            //Quit button
            if(e.type == SDL_QUIT) {
                exit = true;
                break;
            }
            if(e.type == SDL_KEYDOWN) {
                Keyboard::press((Keyboard::Key)e.key.keysym.sym);
            }
            if(e.type == SDL_KEYUP) {
                Keyboard::release((Keyboard::Key)e.key.keysym.sym);
            }

        }
        if(exit) {
            closeWindow();
            return false;
        }
        return true;
    }

}