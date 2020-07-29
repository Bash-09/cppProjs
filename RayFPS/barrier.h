#include "pge.h"
#include "collision.h"
#include "traceable.h"

class Barrier : public Traceable {
public:
    Barrier(olc::vf2d p1, olc::vf2d p2) {
        dir = p2 - p1;
        t = dir.mag();
        dir = dir.norm();
    }
    Barrier(olc::vf2d p1, olc::vf2d dir, float length) {
        p2 = p1 + (dir * length);
    }

private:
    olc::vf2d p1 = {0, 0};
    olc::vf2d p2 = {0, 0};
    float t = 0;
    olc::vf2d dir = {0, 0};

public:
    olc::vf2d p1() {return p1;}
    olc::vf2d p2() {return p2;}
    olc::vf2d dir() {return dir;}
    float mag() {return t;}

    Collision trace(Ray& ray) override;

};