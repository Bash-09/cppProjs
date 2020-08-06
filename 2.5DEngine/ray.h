#pragma once

#include "pge.h"


class Ray {
public:
    Ray(olc::vf2d pos, olc::vf2d dir) : pos(pos), dir(dir.norm()){

    }

    const olc::vf2d pos;
    const olc::vf2d dir;

private:


};

class Collideable;

class Collision {
public:
    Collision(Ray *ray, Collideable *target, float t) : ray(ray), target(target), t(t), pos(ray->pos + ray->dir * t) {

    }
    ~Collision() {
        delete ray;
    }

    const Ray *ray;
    const Collideable *target;
    const float t;
    const olc::vf2d pos;

private:

};

class Collideable {
public:
    virtual Collision *trace(Ray &ray) = 0;

private:

};