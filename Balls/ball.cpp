#include "ball.h"

Ball::Ball() {

}
Ball::~Ball() {

}

void Ball::applyForce(olc::vf2d dir, float mag = 1) {

    acc += (dir*mag)/r;

}

void Ball::move(float delta) {

    vel += acc;
    acc = {0, 0};
    pos += vel*delta;
    
}