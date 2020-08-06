#define OLC_PGE_APPLICATION

#include "pge.h"
#include "iostream"
#include "player.h"
#include "collideables.h"


class Main : public olc::PixelGameEngine{
public:
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
};

olc::vi2d res = {600, 600};
bool fullscreen = false;
bool vsync = false;

int main() {

    Main main;
    if(main.Construct(res.x, res.y, 1, 1, fullscreen, vsync)) {
        main.Start();
    }

}
/*
*   Program actual start
*
*/

Barrier b1 = Barrier({300, 100}, {100, 300});

Player p;

bool Main::OnUserCreate() {
    return true;
}

bool Main::OnUserUpdate(float fElapsedTime) {
    Clear(olc::BLACK);

    //DrawCircle(p.pos, 5);
    //DrawLine(p.pos, p.pos+p.dir*10);
    DrawCircle(res/2, 5);
    DrawLine(res/2, {res.x/2, res.y/2 - 10});

    p.renderMap(this, b1, res/2);




    //Player controls
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