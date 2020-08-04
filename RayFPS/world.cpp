
#include "world.h"


void World::renderMap(olc::PixelGameEngine* pge) {

    pge->Clear(olc::BLACK);

    for(Barrier *b : bars) {
        pge->DrawLine(b->getP1(), b->getP2());
    }

}

Trace* World::trace(Ray& ray) {
    
    Collision *col = nullptr;
    Traceable *target = nullptr;

    for(int i = 0; i < bars.size(); i++) {
        bool updated = false;
        Collision *c = bars[i]->trace(ray);

        if(c == nullptr) continue;
        if(col == nullptr && c->t > 0) {
            delete col;
            col = c;
            target = bars[i];
            updated = true;
        }
        if(c->t > 0 && c->t < col->t) {
            delete col;
            col = c;
            target = bars[i];
            updated = true;
        }
        if(!updated) delete c;
    }

    return new Trace(col, target);

}