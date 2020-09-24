#include "Engine/Engine.h"

int main() {
    Engine::start();
}


void init() {
    std::cout << "Initialised\n";
}

void update(float elapsed) {
    //std::cout << "Looping\n";
    std::cout << elapsed << "\n";

    auto events = Keyboard::getEvents();

    for(auto i = events.begin(); i != events.end(); i++) {
        if(i->press) {
            std::cout << Keyboard::getChar(i->key) << "\n";
        }
    }

    std::cout << Engine::FPS() << "\n";
    

}

void render() {
    //std::cout << "Rendering\n";
}

void destroy() {
    std::cout << "Closing\n";
}