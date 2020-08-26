#define OLC_PGE_APPLICATION

#include "pge.h"
#include "iostream"
#include "maths.h"
#include "riemann.h"


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


class TestEq : public Eq {
    float get(float x) {
        return x*x;
    }
};

TestEq test1{};

RiemannSum sum{};


bool Main::OnUserCreate() {

    sum.cam.translate({(float)-res.x/2, (float)-res.y/2});
    sum.calculate(test1, *this);


    return true;
}

bool Main::OnUserUpdate(float fElapsedTime) {


    return true;
}