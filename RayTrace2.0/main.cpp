#define OLC_PGE_APPLICATION

#include "pge.h"
#include <iostream>
#include "renderer.h"


class Main : public olc::PixelGameEngine{
public:
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
};

olc::vi2d res = {600, 600};
bool fullscreen = false;
bool vsync = true;

int main() {

    Main main;
    if(main.Construct(res.x, res.y, 1, 1, fullscreen, vsync)) {
        main.Start();
    }

}
void buildScene();

//Potential to split up rendering so you can see it happening
bool Main::OnUserUpdate(float fElapsedTime) {
    return true;
}

Camera cam;
std::vector<Collideable*> scene;

bool Main::OnUserCreate() {
    Clear(olc::BLANK);
    buildScene();

    render(*this, {res.x, res.y}, cam, scene);

    return true;
}



Material m1;
Material m2;

Sphere sp1;
Plane p1;

void buildScene() {
    cam.pos.y += 0.5;
    cam.setDir({0, -0.3, 1});

    sp1.pos = {0, 0, 1};
    sp1.rad = 0.5;
    sp1.mat = &m1;

    p1.pos = {0, 0, 1};
    p1.norm = {0, 1, 0};
    p1.norm.normalize();
    p1.mat = &m2;

    m1.col = {0, 0, 1};
    m2.col = {0, 1, 0};

    scene.push_back(&sp1);
    scene.push_back(&p1);
}
