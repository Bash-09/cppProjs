#define OLC_PGE_APPLICATION

#include "pge.h"
#include "iostream"
#include "maths.h"


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

bm::v2f l1p = {300, 100};
bm::v2f l2p = {100, 300};

bm::v2f l1d = {1, 1};
bm::v2f l2d = {1, 0};

bool Main::OnUserCreate() {

    l1d.normalize();
    l2d.normalize();

    bm::m3 a;
    a.vals[0][0] = 1;
    a.vals[0][1] = 2;
    a.vals[0][2] = 6;
    a.vals[1][0] = 4;
    a.vals[1][1] = 3;
    a.vals[1][2] = 6;
    a.vals[2][0] = 7;
    a.vals[2][1] = 8;
    a.vals[2][2] = 8;
    a.print();
    std::cout<<std::endl;
    bm::m3 b = a;
    b.invert();
    a *= b;
    a.print();

    return true;
}

bm::v2f dir = {0, -1};
bm::cn rot = {0.25}; 

bool Main::OnUserUpdate(float fElapsedTime) {
    Clear(olc::BLACK);

    l2d.x = l2p.x - GetMouseX();
    l2d.y = l2p.y - GetMouseY();
    if(l2d.mag2() == 0) {
        return true;
    }

    l2d.normalize();
    bm::v2f p = {l1p.x - l2p.x, l1p.y - l2p.y};
    bm::m2 d;
    d.vals[0][0] = l2d.x;
    d.vals[0][1] = -l1d.x;
    d.vals[1][0] = l2d.y;
    d.vals[1][1] = -l1d.y;

    bm::v2f t = d.invert() * p;

    DrawLine(l1p.x, l1p.y, l1p.x+l1d.x*t.y, l1p.y+l1d.y*t.y);
    DrawLine(l2p.x, l2p.y, l2p.x+l2d.x*t.x, l2p.y+l2d.y*t.x);


    DrawCircle(res/2, 30);
    dir *= rot;
    olc::vf2d pos = {dir.x * 30, dir.y * 30};
    pos += res/2;
    DrawLine(res/2, pos);

    return true;
}