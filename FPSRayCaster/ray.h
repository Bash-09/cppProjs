#include "pge.h"

class Ray {

public:
    const olc::vf2d pos;
    const olc::vf2d dir;

    Ray(olc::vf2d pos = {0, 0}, olc::vf2d dir = {1, 0}) : pos(pos), dir(dir.norm())
    {
        
    }

};