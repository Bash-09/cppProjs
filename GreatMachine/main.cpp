#define OLC_PGE_APPLICATION

#include <iostream>

#include "pge.h"
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

bool Main::OnUserCreate() {
    return true;
}

bool Main::OnUserUpdate(float fElapsedTime) {

    std::cout << "Hello World" << std::endl;

    return true;
}