#include "Grav.h"


P_Grav::P_Grav(V2f pos, olc::Renderable* texture) : Particle(pos, texture) {
    vel.x = rand()%200;
    vel.y = -(rand()%600 + 150);
    if(rand()%2 > 0) vel.x *= -1;

    lifetime = 2;
    size = 15;
}


bool P_Grav::go(float delta) {
    pos.x += vel.x * delta;
    pos.y += vel.y * delta;

    vel.y += 400*delta;

    age += delta;
    if(age > lifetime) return false;
    return true;
}
