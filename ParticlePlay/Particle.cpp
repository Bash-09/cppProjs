
#include "Particle.h"


Particle::Particle(V2f pos, olc::Renderable* texture) : texture(texture), pos(pos)  {
    size = 25;
    lifetime = 4;
}

Particle::~Particle() {

}

void Particle::render(olc::PixelGameEngine* pge) {
    if(texture == nullptr) {
        pge->FillRect((int)pos.x-size/2, (int)pos.y-size/2, size, size, olc::WHITE);
    } else {
        pge->DrawDecal({pos.x-size/2, pos.y-size/2}, texture->Decal(), {(float)size/(float)texture->Sprite()->width, (float)size/(float)texture->Sprite()->height}); 
    }
}
