
#include "barrier.h"
#include "traceable.h"

Collision* Barrier::trace(Ray &ray) {

    if(ray.dir.x == dir.x && ray.dir.y == dir.y) return nullptr;
    if(ray.dir.x == 0 && ray.dir.y == 0) return nullptr;

    float disc = 1/(-ray.dir.y*dir.x + ray.dir.x*dir.y);

    float P1 = ray.pos.x - p1.x;
    float P2 = ray.pos.y - p1.y;

    float D00, D01, D10, D11;

    D00 = -ray.dir.y;   D01 = ray.dir.x;
    D10 = -dir.y;       D11 = dir.x;

    D00 *= disc;
    D01 *= disc;
    D10 *= disc;
    D11 *= disc;

    float t1 = D10 * P1 + D11 * P2;
    float t2 = D00 * P1 + D01 * P2;

    if(t1 < 0 || t2 < 0 || t2 > t) return nullptr;

    return new Collision(&ray, t1);

}
