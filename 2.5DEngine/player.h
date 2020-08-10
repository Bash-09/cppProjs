#pragma once

#include "pge.h"
#include "collideables.h"
#include <vector>

class Player {

private:
    std::vector<Barrier**> bars;

public:
    Player() {}
    ~Player() {}

    void add(Barrier** bar) {
        bars.push_back(bar);
    }

    olc::vf2d pos = {0, 0};
    olc::vf2d dir = {0, -1};

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

    void renderFP(olc::PixelGameEngine *pge, olc::vi2d res);
    void renderFP(olc::PixelGameEngine *pge, olc::vi2d res, Barrier* bar);
    void renderMap(olc::PixelGameEngine *pge, olc::vi2d res);

    void remove(Barrier* bar) {
        for(std::vector<Barrier**>::iterator b = bars.begin(); b != bars.end(); b++) {
            if(**b == bar) b = bars.erase(b);
        }
    }
private:
    Collision* castRay(Ray& ray);

};