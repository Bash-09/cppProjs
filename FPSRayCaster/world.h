
#pragma once

#include "pge.h"
#include "barrier.h"
#include "trace.h"

class World {

private:
    std::vector<Barrier*> bars;

public:
    void destroy() {
        for(Barrier* b : bars) {
            delete b;
        }
        bars.clear();
    }
    void clear() {bars.clear();}
    void add(Barrier *bar) {bars.push_back(bar);}

    void renderMap(olc::PixelGameEngine* pge);
    Trace *trace(Ray& ray);

};