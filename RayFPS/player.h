#pragma once

#include "pge.h"
#include "world.h"

class Player {

public:
    olc::vf2d pos = {0, 0};
    olc::vf2d dir = {1, 0};

public:
    void translate(olc::vf2d mov) {
        pos += mov;
    }
    void turn(float angle) {
        float rad = angle*2*acos(0)/180;

        float nx = dir.x * cos(rad) - dir.y * sin(rad);
        float ny = dir.x * sin(rad) + dir.y * cos(rad);

        dir.x = nx;
        dir.y = ny;
        dir = dir.norm();
    }
    void setPos(olc::vf2d p) {
        pos = p;
    }
    void setDir(olc::vf2d d) {
        dir = d.norm();
    }

    float fov = 90;

    void render(World& w, olc::PixelGameEngine& pge, olc::vi2d res);
};