#pragma once

#include "pge.h"
#include "ray.h"

class Collision {

public:
    const float t;
    const Ray *ray;
    const olc::vf2d pos;

    Collision(Ray *ray, float t) : t(t), ray(ray), pos(ray->pos+(ray->dir*t)) {
        
    }

    void render(olc::PixelGameEngine *pge) {
        pge->DrawLine(ray->pos, pos);
    }

};
