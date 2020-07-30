
#include "engine.h"

Engine::Engine(int x, int y) {
    res = {x, y};
}

Engine::~Engine() {

}

Barrier bar({100, 300}, {300, 100});
Collision *col = nullptr;

bool Engine::OnUserCreate() {

    return true;
}

bool Engine::OnUserUpdate(float fElapsedTime) {
    Clear(olc::BLACK);

    olc::vf2d mouse = {(float)GetMouseX(), (float)GetMouseY()};
    if(mouse.x == 0 && mouse.y == 0) {
        mouse.x = 1;
        mouse.y = 1;
    }

    Ray ray({0, 0}, mouse);
    col = bar.trace(ray);
        std::cout << ray.pos.x << std::endl;

    if(col != nullptr) {
        DrawLine(ray.pos, col->pos);
    } else {
        DrawLine(ray.pos, mouse);
    }

    return true;
}