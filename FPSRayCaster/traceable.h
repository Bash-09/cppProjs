#pragma once

#include "collision.h"

class Traceable {

public:
    virtual Collision *trace(Ray &ray) = 0;
    float height = 1;

};