#include "world.h"

World::World(olc::vf2d size = {600, 600})  {
    this->size = size;
}

World::~World() {

}


bool World::touching(Ball& b1, Ball& b2) {

    float r2 = b1.r+b2.r;
    r2 *= r2;

    olc::vf2d vdist = b2.pos - b1.pos;
    float fdist = vdist.mag2();

    if(fdist < r2) return true;

    return false;
}


void World::resolve(Ball& b1, Ball& b2) {

    olc::vf2d n = b2.pos - b1.pos;
    olc::vf2d t = {-n.y, n.x};

    float dist = n.mag();
    dist = b1.r+b2.r - dist;
    dist *= 1.001;
    float offset = dist/2;

    b1.pos += n*-offset;
    b2.pos += n*offset;

    t = t.norm();
    n = n.norm();

    olc::vf2d p1 = b1.pos;
    olc::vf2d p2 = b2.pos;

    float m1 = b1.r;
    float m2 = b2.r;

    olc::vf2d v1 = b1.vel;
    olc::vf2d v2 = b2.vel;

    float dn1 = v1.x*n.x + v1.y*n.y;
    float dt1 = v1.x*t.x + v1.y*t.y;

    float dn2 = v2.x*n.x + v2.y*n.y;
    float dt2 = v2.x*t.x + v2.y*t.y;

    float fm1 = (dn1 * (m1-m2) + 2 * m2 * dn2) / (m1 + m2);
    float fm2 = (dn2 * (m2-m1) + 2 * m1 * dn1) / (m1 + m2);

    olc::vf2d vo1 = t * dt1 + n * fm1;
    olc::vf2d vo2 = t * dt2 + n * fm2;

    b1.vel = vo1;
    b2.vel = vo2;

}


void World::go(float delta) {

    //Physics and bounds Check
    for(Ball &b : balls) {
        //Check left edge
        if(b.pos.x-b.r < 0) {
            b.pos.x = b.r;
            b.vel.x = abs(b.vel.x);
        }
        //Check top
        if(b.pos.y-b.r < 0) {
            b.pos.y = b.r;
            b.vel.y = abs(b.vel.y);
        }
        //Check right edge
        if(b.pos.x+b.r > size.x) {
            b.pos.x = size.x - b.r;
            b.vel.x = -abs(b.vel.x);
        }
        //Check bottom
        if(b.pos.y+b.r > size.y) {
            b.pos.y = size.y - b.r;
            b.vel.y = -abs(b.vel.y);
        }

        for(Ball &b2 : balls) {
            if(&b2 == &b) continue;

            if(touching(b, b2))
                resolve(b, b2);
        }

    }

    //Move balls
    for(Ball &b : balls) {
        b.move(delta);

        b.applyForce({0, 1}, 10);
    }

}


void World::render(olc::PixelGameEngine &pge) {

    pge.Clear(olc::BLACK);

    for(Ball &b : balls) {

        pge.DrawCircle(b.pos, b.r);

    }

}

void World::addBalls(int num) {

    for(int i = 0; i < num; i++) {
        Ball *b = new Ball;

        olc::vf2d pos = {0, 0};
        bool valid = false;
        while(!valid) {
            valid = true;

            pos.x = (float) rand()/RAND_MAX;
            pos.y = (float) rand()/RAND_MAX;
            pos = pos * size;

            for(Ball &b2 : balls) {
                if(touching(*b, b2)) {
                    valid = false;
                    break;
                }
            }

        }

        b->pos = pos;
        balls.push_back(*b);

    }

}