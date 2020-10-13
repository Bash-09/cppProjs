#pragma once

#include <GL/gl.h>
#include <GL/glu.h>

#include "../Platform/Window.h"

class Renderer {
public:
    Renderer(Window* window);
    ~Renderer();

    void initGL();


private:

    Window* window;



};