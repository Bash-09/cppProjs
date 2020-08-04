
#include "engine.h"
#include "world.h"
#include "player.h"

Engine::Engine(int x, int y) {
    res = {x, y};
}

Engine::~Engine() {

}

World world;

Barrier bar({100, 100}, {300, 100});
Barrier bar2({100, 300}, {100, 100});
Barrier bar3({150, 150}, {250, 250});

Barrier wall1({0, 0}, {0, 600});
Barrier wall2({0, 600}, {600, 600});
Barrier wall3({600, 600}, {600, 0});
Barrier wall4({600, 0}, {0, 0});

Player p;

bool Engine::OnUserCreate() {

    world.add(&bar);
    world.add(&bar2);
    world.add(&bar3);

    world.add(&wall1);
    world.add(&wall2);
    world.add(&wall3);
    world.add(&wall4);

    p.setPos(res/2);

    return true;
}

bool Engine::OnUserUpdate(float fElapsedTime) {
    Clear(olc::BLACK);

    world.renderMap(this);
    p.render(world, *this, res);

    DrawCircle(p.pos, 5);
    DrawLine(p.pos, p.pos+p.dir*10);


    float turnSpeed = 170;
    if(GetKey(olc::LEFT).bHeld) {
        p.turn(-turnSpeed*fElapsedTime);
    }
    if(GetKey(olc::RIGHT).bHeld) {
        p.turn(turnSpeed*fElapsedTime);
    }

    float speed = 100;
    if(GetKey(olc::W).bHeld) {
        p.translate(p.dir * speed * fElapsedTime);
    }
    if(GetKey(olc::A).bHeld) {
        olc::vf2d n = {p.dir.y, -p.dir.x};
        p.translate(n * speed * fElapsedTime);
    }
    if(GetKey(olc::S).bHeld) {
        p.translate(p.dir * -speed * fElapsedTime);
    }
    if(GetKey(olc::D).bHeld) {
        olc::vf2d n = {p.dir.y, -p.dir.x};
        p.translate(n * -speed * fElapsedTime);
    }

    return true;
}