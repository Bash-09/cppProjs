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


bm::v2f p1 = {200, 400};
bm::v2f p2 = {400, 400};

bm::v2f cp1 = {200, 200};
bm::v2f cp2 = {400, 200};


void draw(olc::PixelGameEngine &pge) {
    pge.Clear(olc::BLACK);

    pge.FillCircle(p1.x, p1.y, 10, olc::RED);
    pge.FillCircle(p2.x, p2.y, 10, olc::RED);

    pge.FillCircle(cp1.x, cp1.y, 10, olc::BLUE);
    pge.FillCircle(cp2.x, cp2.y, 10, olc::BLUE);

    pge.DrawLine(p1.x, p1.y, cp1.x, cp1.y);
    pge.DrawLine(p2.x, p2.y, cp2.x, cp2.y);

    bm::v2f l11 = cp1 - p1;
    bm::v2f l12 = cp2 - cp1;
    bm::v2f l13 = p2 - cp2;

    for(int i = 0; i < 100; i++) {
        float dist = (float)i / 100;

        bm::v2f l21 = p1 + (l11 * dist);
    }

}


bool Main::OnUserCreate() {
    return true;
}

bool Main::OnUserUpdate(float fElapsedTime) {

    draw(*this);

    return true;
}