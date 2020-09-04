#pragma once

#include "pge.h"
#include "traceable.h"

class Barrier : public Traceable {
public:
    Barrier(olc::vf2d p1, olc::vf2d p2) : p1(p1), p2(p2) {
        dir = p2 - p1;
        t = dir.mag();
        dir = dir.norm();
    }
    Barrier(olc::vf2d p1, olc::vf2d direc, float length) : p1(p1), dir(direc.norm()), t(t) {
        p2 = p1 + (dir * length);
        t = length;
    }

private:
    olc::vf2d p1 = {0, 0};
    olc::vf2d p2 = {0, 0};
    float t = 0;
    olc::vf2d dir = {0, 0};

public:
    olc::vf2d getP1() {return p1;}
    olc::vf2d getP2() {return p2;}
    olc::vf2d getDir() {return dir;}
    float mag() {return t;}
    float height = 1;

    Collision* trace(Ray &ray) override;
};