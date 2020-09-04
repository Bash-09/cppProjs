#pragma once

#include <vector>
#include "ray.h"

class Sphere : public Collideable {
public:
    V3f pos = {0};
    float rad = 1;

    virtual Collision trace(Collision &col, Ray &ray);

};


class Plane : public Collideable {
public:
    V3f pos = {0};
    V3f norm = {0, 1, 0};

    virtual Collision trace(Collision &col, Ray &ray);
};
