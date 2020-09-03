#pragma once

#include "maths.h"

class Ray;
class Collision;
class Collideable;

class Ray {
public:
    V3f pos;
    V3f dir;

    Ray(V3f pos, V3f dir) : pos(pos), dir(dir.normalized()) {}
    Ray(const Ray &ray) : pos(ray.pos), dir(ray.dir) {}
    Ray() {}
};

class Collision {
public:
    Ray ray;
    float t;
    V3f pos;
    V3f normal;
    Collideable *target;

    Collision(Ray ray, float t, V3f normal, Collideable *target) : 
        ray(ray), t(t), 
        pos(ray.pos + ray.dir * t), 
        normal(normal), 
        target(target) {}
};

class Collideable {
public:

    virtual Collision trace(Collision &col, Ray &ray) = 0;


};