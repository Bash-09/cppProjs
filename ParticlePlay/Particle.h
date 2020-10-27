#pragma once

#include "pge.h"
#include "maths.h"

class Particle {
public:
    Particle(V2f pos, olc::Renderable* texture);
    ~Particle();

    olc::Renderable* texture = nullptr;
    
    virtual void render(olc::PixelGameEngine* pge);
    virtual bool go(float delta) = 0;

    int size;
    float lifetime;
protected:
    float age = 0;
    V2f pos = {0, 0};

};
