#include "pge.h"

class Ray {

public:
    const olc::vf2d pos;
    const olc::vf2d dir;
    const float length;

    Ray(olc::vf2d pos, olc::vf2d dir, float length) : pos(pos), dir(dir), length(length) {}

};