#pragma once

#include "pge.h"
#include "ray.h"


class Barrier : public Collideable {
public:
    Barrier(olc::vf2d p1, olc::vf2d p2) : p1(p1), p2(p2), dir((p2 - p1).norm()), t(dir.mag()) {

    }
    Barrier(olc::vf2d p1, olc::vf2d dir, float length) : p1(p1), dir(dir.norm()), t(length) {
        p2 = this->dir * length + p1;
    }

    olc::vf2d p1;
    olc::vf2d p2;
    olc::vf2d dir;
    float t;

    virtual Collision *trace(Ray &ray) override;

private:

};