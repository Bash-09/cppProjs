#include "../Renderer.h"

Renderer::Renderer() {

}

Renderer::~Renderer() {

}

void Renderer::initGL() {

    glClearColor( 0.f, 1.f, 1.f, 1.f );
    glClear( GL_COLOR_BUFFER_BIT );


    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glBegin( GL_QUADS );
        glVertex2f( -0.5f, -0.5f );
        glVertex2f( 0.5f, -0.5f );
        glVertex2f( 0.5f, 0.5f );
        glVertex2f( -0.5f, 0.5f );
    glEnd();

}