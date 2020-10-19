#include "../Window.h"

//SDL does not start initialised
bool initSDL = false;
SDL_Window* window = nullptr;
SDL_GLContext glContext = nullptr;

Window::Window() {

}

Window::~Window() {

}

void Window::createWindow(const std::string& title, uint32_t screenWidth, uint32_t screenHeight, bool vsync) {
    //Init SDL
    if(!initSDL) {
        if( SDL_Init(SDL_INIT_EVERYTHING) < 0 ) {
            std::cout << "SDL could not be initialised! SDL_Error: " << SDL_GetError() << "\n";
            return;
        } else {
            initSDL = true;
        }
    }

    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 4 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );

    //Create window
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if(window == nullptr) {
        std::cout << "SDL could not create a window! SDL_Error: " << SDL_GetError() << "\n";
        return;
    }

    glContext = SDL_GL_CreateContext( window );
    if(glContext == nullptr) {
        std::cout << "SDL could not initialise OpenGL! SDL_Error: " << SDL_GetError() << "\n";
        return;
    }

    if( SDL_GL_SetSwapInterval(vsync) < 0 ) {
        std::cout << "Warning: VSync not set!\n";
    }

    windowOpen = true;
}

void Window::updateWindow() {
    SDL_GL_SwapWindow( window );
}

void Window::closeWindow() {
    SDL_DestroyWindow(window);
    SDL_Quit();
    windowOpen = false;
}

void Window::quit() {
    SDL_Quit();
}

bool Window::isWindowOpen() {
    return windowOpen;
}


int Window::getWidth() {
    int w = 0;
    SDL_GetWindowSize(window, &w, nullptr);
    return w;
}
int Window::getHeight() {
    int h = 0;
    SDL_GetWindowSize(window, nullptr, &h);
    return h;
}

SDL_Event e;
bool Window::getInput(Keyboard* key) {
    bool exit = false;
    key->nextFrame();
    while( SDL_PollEvent( &e ) != 0) {
        //Quit button
        if(e.type == SDL_QUIT) {
            exit = true;
        }
        
        if(e.type == SDL_KEYDOWN) {
            key->press((Key)e.key.keysym.sym);
        }
        if(e.type == SDL_KEYUP) {
            key->release((Key)e.key.keysym.sym);
        }
        

    }
    return exit;
}