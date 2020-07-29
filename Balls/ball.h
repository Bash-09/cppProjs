
#include "pge.h"

class Ball {
public:
    Ball();
    ~Ball();

    float r = 20;
    olc::vf2d pos = {0, 0};
    olc::vf2d vel = {0, 0};
    olc::vf2d acc = {0, 0};

    olc::Pixel col = olc::WHITE; 

    void applyForce(olc::vf2d dir, float mag);
    void move(float delta);
};