
#pragma once

#include "pge.h"
#include "barrier.h"

class World {

private:
    std::vector<Barrier*> bars;

public:
    void clear() {bars.clear();}
    void add(Barrier *bar) {bars.push_back(bar);}

    void renderMap(olc::PixelGameEngine* pge);
    void renderFP(olc::PixelGameEngine* pge);
    Collision *trace(Ray& ray);

};