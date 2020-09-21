#pragma once

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace Plat {

    //Create what we need for our window
    SDL_Window* window = nullptr;
    SDL_Surface* screenSurface = nullptr;


    //Creates window
    bool init(int screenWidth = 640, int screenHeight = 480, char* title = "") {
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
    void exit() {

        //Clean up shit and destroy the window
        SDL_FreeSurface(screenSurface);
        screenSurface = nullptr;
        SDL_DestroyWindow(window);
        window = nullptr;
        //Quit SDL
        SDL_Quit();

    }


}