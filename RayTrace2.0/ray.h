#pragma once

#include "maths.h"

class Ray;
class Collision;
class Collideable;
class Material;
class Scene;
class Light;

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
        pos(ray.pos + ray.dir * (t*0.999)), 
        normal(normal), 
        target(target) {}
};

class Collideable {
public:

    virtual Collision trace(Collision &col, Ray &ray) = 0;
    Material *mat;

};


class Material {
public:
    Material() {}

    V3f col = {1, 1, 1};

};

class Light {
public:
    V3f pos;
    V3f col;
    float intensity;
};

class Scene {
public:
    std::vector<Collideable*> objs;
    std::vector<Light*> lights;
};