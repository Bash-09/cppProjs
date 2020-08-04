#pragma once

#include "pge.h"
#include "traceable.h"

class Trace { 

public:
    const Collision *col;
    const Traceable *target;

    Trace(Collision *col, Traceable *target) : col(col), target(target) {};

};