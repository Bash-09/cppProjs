
#include "engine.h"

Engine::Engine(int x, int y) {
    res = {x, y};
}

Engine::~Engine() {

}

Barrier bar({100, 300}, {300, 100});
Collision *col;
Ray ray({0, 0}, {-2, -1});

bool Engine::OnUserCreate() {

    col = bar.trace(ray);

    return true;
}

bool Engine::OnUserUpdate(float fElapsedTime) {

    DrawLine(bar.getP1(), bar.getP2());
    DrawLine(ray.pos, col->pos);

    return true;
}