
#include "world.h"


void World::renderMap(olc::PixelGameEngine* pge) {

    pge->Clear(olc::BLACK);

    for(Barrier *b : bars) {
        pge->DrawLine(b->getP1(), b->getP2());
    }

}

void World::renderFP(olc::PixelGameEngine* pge) {

}

Collision* World::trace(Ray& ray) {
    
    Collision** cols = new Collision*[bars.size()];

    for(int i = 0; i < bars.size(); i++) {
        cols[i] = bars[i]->trace(ray);
    }

    Collision* col = nullptr;

    for(int i = 0; i < bars.size(); i++) {
        if(cols[i] == nullptr) continue;
        if(col == nullptr && cols[i]->t > 0) col = cols[i];
        if(cols[i]->t > 0 && cols[i]->t < col->t) col = cols[i];
    }

    delete[] cols;

    return col;

}