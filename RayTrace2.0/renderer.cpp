#include "renderer.h"


void render(olc::PixelGameEngine &pge, V2i res, Camera &cam) {

    for(int i = 0; i < res.x; i++) {
        for(int j = 0; j < res.y; j++) {
            float x = (float)i / (float)res.x;
            float y = 1 - (float)j / (float)res.y;

            pge.FillRect(x, y, 1, 1, getPixel({(float)x, (float)y}, cam));

        }
    }

}

Collision castRay(Ray &ray) {
    Sphere sp1;
    sp1.pos = {0, 0, 1};
    sp1.rad = 0.5;

    Collision col = {ray, 1000, ray.dir, nullptr};

    col = sp1.trace(col, ray);

    return col;
}

olc::Pixel getPixel(V2f coords, Camera &cam) {

    Ray ray = cam.getOutRay(coords);
    Collision col = castRay(ray);

    ray.dir.print();
    return olc::PixelF(ray.dir.x,ray.dir.y,ray.dir.z);

    /*

    if(col.target == nullptr) return olc::BLACK;
    else return olc::BLUE;
    */

}

Ray Camera::getOutRay(V2f coords) {

    V3f p = pos + x*coords.x - x/2 + y*coords.y - y/2;
    V3f d = z;

    return {p, d};
}

void Camera::updateDir(V3f newDir) {
    V3f seed = {0, 1, 0};
    z = newDir;
    x = z.cross(seed);
    y = x.cross(z);
}