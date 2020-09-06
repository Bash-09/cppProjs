#pragma once

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<X11/X.h>
#include<X11/Xlib.h>
#include<GL/gl.h>
#include<GL/glx.h>
#include<GL/glu.h>

#include <pthread.h>

#include "platform.h"

class Platform_Linux : public Platform {
public:
    void StartWindow() override;
    void NewThread(void* target) override;

    Display                 *dpy;
    Window                  root;
    GLint                   att[5] = {GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None};
    XVisualInfo             *vi;
    Colormap                cmap;
    XSetWindowAttributes    swa;
    Window                  win;
    GLXContext              glc;
    XWindowAttributes       gwa;
    XEvent                  xev;

};