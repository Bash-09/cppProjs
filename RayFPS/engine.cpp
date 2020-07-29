
#include "engine.h"

Engine::Engine(int x, int y) {
    res = {x, y};
}

Engine::~Engine() {

}

Barrier bar({100, 100}, {300, 200});


bool Engine::OnUserCreate() {



    return true;
}

bool Engine::OnUserUpdate(float fElapsedTime) {



    return true;
}