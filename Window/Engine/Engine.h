#pragma once

#include "../Platform/Window.h"
#include "../Renderer/Renderer.h"

class Application {
public:
    Application() : rend(&window) {};
    ~Application();

    void init();
    void update(float delta);
    void render();
    void close();

private:
    Window window;
    Renderer rend;

};