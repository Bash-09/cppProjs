#include "collideables.h"

bool comp(float def, float comp) {
    if(comp <= 0) return false;
    if(def <= 0) return true;
    if(comp < def) return true;
    return false;
}

//(not very) Complicated maths (but good luck figuring out what it does from just this)
Collision Sphere::trace(Collision &col, Ray &ray) {

    V3f va = ray.dir * ray.dir;
    V3f vb = ray.dir * (ray.pos - pos) * 2;
    V3f vc = ray.pos * ray.pos + pos * pos - ray.pos * pos * 2;

    float a = va.x + va.y + va.z;
    float b = vb.x + vb.y + vb.z;
    float c = vc.x + vc.y + vc.z - rad*rad;
    
    float det = b * b - 4 * a * c;
    if(det < 0) return col;

    float t1 = (-b + sqrt(det)) / 2*a;
    float t2 = (-b - sqrt(det)) / 2*a;

    float t = t1;
    if((t < 0 && t2 > 0) || (t2 < t && t2 > 0)) t = t2;

    if(!comp(col.t, t)) return col;

    V3f n = ray.pos + ray.dir * t - pos;
    n.normalize();

    Collision outCol = {ray, t, n, this};
    return outCol;
}


Collision Plane::trace(Collision &col, Ray &ray) {

    V3f vnum = norm * (pos - ray.pos);
    V3f vden = ray.dir * norm;

    float num = vnum.x + vnum.y + vnum.z;
    float den = vden.x + vden.y + vden.z;

    float t = num / den;

    if(!comp(col.t, t)) return col;

    Collision out = {ray, t, norm, this};
    return out;
}
