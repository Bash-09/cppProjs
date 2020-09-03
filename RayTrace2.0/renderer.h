#pragma once

#include "pge.h"
#include "ray.h"
#include "collideables.h"

class Camera {
public:
    V3f pos = {0};

    V3f getDir() {return z;}

    void setDir(V3f newDir) {updateDir(newDir);}

    Ray getOutRay(V2f coords);

    float fov = 60;

private:
    void updateDir(V3f newDir);

    V3f x = {1, 0, 0};
    V3f y = {0, 1, 0};
    V3f z = {0, 0, 1};

};

void render(olc::PixelGameEngine &pge, V2i res, Camera &cam, std::vector<Collideable*> scene);
Collision castRay(Ray &ray, std::vector<Collideable*> scene);
olc::Pixel getPixel(V2f coords, Camera &cam, std::vector<Collideable*> scene);