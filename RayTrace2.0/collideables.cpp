#include "collideables.h"

Collision Sphere::trace(Collision &col, Ray &ray) {

    float a = ray.dir.x*ray.dir.x + ray.dir.y*ray.dir.y + ray.dir.z*ray.dir.z;
    if(a == 0) return col;
    float b = 2 * (ray.dir.x*(ray.pos.x + pos.x) + ray.dir.y*(ray.pos.y + pos.y) + ray.dir.z*(ray.pos.z + pos.z));
    float c = ray.pos.x*ray.pos.x + pos.x*(pos.x - 2*ray.pos.x) + ray.pos.y*ray.pos.y + pos.y*(pos.y - 2*ray.pos.y) + ray.pos.z*ray.pos.z + pos.z*(pos.z - 2*ray.pos.z);

    float det = b*b - 4*a*c;
    if(det < 0) return col;

    float t1 = (-b + sqrt(det)) / 2*a;
    float t2 = (-b - sqrt(det)) / 2*a;

    float t = t1;
    if((t < 0 && t2 > 0) || (t2 < t && t2 > 0)) t = t2;

    if(t < 0 || t > col.t) return col;

    V3f n = ray.pos + ray.dir * t - pos;
    n.normalize();

    Collision outCol = {ray, t, n, this};
    return outCol;
}