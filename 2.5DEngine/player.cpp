#include "player.h"

//Will have to make screen depth buffer for rendering first person per barrier

void Player::renderFP(olc::PixelGameEngine* pge, Barrier &b) {

}

void Player::renderMap(olc::PixelGameEngine* pge, Barrier &b, olc::vi2d middle) {
    olc::vf2d b1 = b.p1 - pos;
    olc::vf2d b2 = b.p2 - pos;

    olc::vf2d p1;
    olc::vf2d p2;

    p1.x = -dir.y*b1.x + dir.x*b1.y;
    p1.y = -dir.y*b1.y - dir.x*b1.x;

    p2.x = -dir.y*b2.x + dir.x*b2.y;
    p2.y = -dir.y*b2.y - dir.x*b2.x;

    //pge->DrawLine(middle + b.p1, middle + b.p2);
    pge->DrawLine(middle + p1, middle + p2);
}