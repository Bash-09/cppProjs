#pragma once

#include "camera.h"
#include "pge.h"


class Eq {

public:
    float minX = 0;
    float maxX = 100;

    virtual float get(float x) = 0;

};

class RiemannSum {
public:
    RiemannSum();
    ~RiemannSum();

    Camera cam;

    int res = 10;

    float calculate(Eq& eq, olc::PixelGameEngine &pge);

private:

};