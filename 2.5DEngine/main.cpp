#define OLC_PGE_APPLICATION

#include "pge.h"
#include "iostream"
#include "player.h"
#include "collideables.h"


class Main : public olc::PixelGameEngine{
public:
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;

    void move(float fElapsedTime);
};

olc::vi2d res = {600, 600};
bool fullscreen = false;
bool vsync = true;

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

Barrier* b1 = new Barrier({300, 100}, {100, 300});

Barrier* b2 = new Barrier({0, 0}, {0, (float)res.y});
Barrier* b3 = new Barrier({0, (float)res.y}, {(float)res.x, (float)res.y});
Barrier* b4 = new Barrier({(float)res.x, (float)res.y}, {(float)res.x, 0});

Barrier* flower = new Barrier({200, 200}, {200, 230});
Barrier* flower2 = new Barrier({150, 150}, {150, 120});
Barrier* flower3 = new Barrier({110, 170}, {110, 140});
Barrier* flower4 = new Barrier({180, 150}, {210, 150});


Player p;

olc::Sprite spr;
olc::Decal* dec;

olc::Sprite flow;
olc::Decal* flowDec;

bool Main::OnUserCreate() {
    p.setPos({300, 300});

    spr.LoadFromFile("../res/textures/wall1.png");
    dec = new olc::Decal(&spr);

    flow.LoadFromFile("../res/textures/grass2.png");
    flowDec = new olc::Decal(&flow);
    flower->texture = flowDec;
    flower->textureWidth = 30;

    flower2->texture = flowDec;
    flower2->textureWidth = 30;
    flower3->texture = flowDec;
    flower3->textureWidth = 30;
    flower4->texture = flowDec;
    flower4->textureWidth = 30;

    b1->texture = dec;
    b2->texture = dec;
    b3->texture = dec;
    b4->texture = dec;

    b1->textureWidth = 100;
    b2->textureWidth = 100;
    b3->textureWidth = 100;
    b4->textureWidth = 100;

    p.add(&b1);
    p.add(&b2);
    p.add(&b3);
    p.add(&b4);

    p.add(&flower);
    p.add(&flower2);
    p.add(&flower3);
    p.add(&flower4);


    return true;
}



bool Main::OnUserUpdate(float fElapsedTime) {
    Clear(olc::BLACK);

    p.renderFP(this, res);
    p.renderMap(this, res);

    move(fElapsedTime);

    return true;
}

void Main::move(float fElapsedTime) {
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
}