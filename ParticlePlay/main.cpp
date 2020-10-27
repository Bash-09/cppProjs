#define OLC_PGE_APPLICATION

#include "pge.h"
#include <iostream>


class Main : public olc::PixelGameEngine{
public:
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
};

olc::vi2d res = {600, 600};
bool fullscreen = false;
bool vsync = false;

int main() {
    srand(time(nullptr));

    Main main;
    if(main.Construct(res.x, res.y, 1, 1, fullscreen, vsync)) {
        main.Start();
    }

}

#include "Particles/Basic.h"
#include "Particles/Grav.h"

std::vector<Particle*> parts;

float interval = 0.002;
float t = 0;
uint32_t maxParticles = 2000;

olc::Renderable tex;

Particle* a;
bool Main::OnUserCreate() {
//    tex.Load("/home/ethan/c++Proj/res/textures/dust.png");
    tex.Load("/home/ethan/c++Proj/res/textures/spark.png");

    return true;
}

bool Main::OnUserUpdate(float fElapsedTime) {
    V2f mPos = {(float)GetMouseX(), (float)GetMouseY()};

    this->Clear(olc::BLACK);

    std::cout << "Particles: "<<parts.size()<<"\n";

    t += fElapsedTime;
    if(t > interval) {
        t = 0;
        if(parts.size() < maxParticles) {
            parts.push_back(new P_Grav(mPos, &tex));
//            parts.push_back(new P_Basic(mPos, &tex));
        }
    }

    for(auto i = parts.begin(); i != parts.end(); i++) {
        if(!(*i)->go(fElapsedTime)) {
            delete (*i);
            parts.erase(i);
        } else {
            (*i)->render(this);
        }
    }

    return true;
}
