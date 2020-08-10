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

bm::v2f test1(0.5, 0.5);
bm::v2f test2(0.25, 0.75);


bool Main::OnUserCreate() {

    test1.print();
    test2.print();

    (test1 + test2).print();

    test1 += test2;
    test1.print();

    test1 *= 2;
    test1.print();

    return true;
}

bool Main::OnUserUpdate(float fElapsedTime) {



    return true;
}