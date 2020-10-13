#include "Engine/Engine.h"


void Application::init() {

}

void Application::update(float elapsed) {

}

void Application::render() {

}



int main() {

    Application app;

    Window window;
    Renderer rend(&window);
    window.createWindow();

    rend.initGL();

    SDL_Delay(2000);

    return 0;
}