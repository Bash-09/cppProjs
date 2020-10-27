#include "Basic.h"


P_Basic::P_Basic(V2f pos, olc::Renderable* texture) : Particle(pos, texture) {
    vel.x = (rand()%300);
    vel.y = (rand()%300);
    if(rand()%2 > 0) vel.x *= -1;
    if(rand()%2 > 0) vel.y *= -1;

    size = 200;
    lifetime = 10;
}

bool P_Basic::go(float delta) {
//   pos += vel * delta; 
    pos.x += vel.x * delta;
    pos.y += vel.y * delta;

//    std::cout << pos.x << ", " << pos.y << "\n";
    age += delta;
    if(age > lifetime) return false;
    return true;

}
