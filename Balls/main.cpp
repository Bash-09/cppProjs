
#define OLC_PGE_APPLICATION

#include <iostream>
#include "pge.h"

#include "world.h"

World world({600, 600});

class Launch : public olc::PixelGameEngine {
public:
    bool OnUserCreate() override {

        world.addBalls(5);

        return true;
    }
    bool OnUserUpdate(float fElapsedTime) override {

        world.go(fElapsedTime);
        world.render(*this);

        return true;
    }

}launch;

int main() {

    if(launch.Construct(600, 600, 1, 1))
        launch.Start();



    return 0;
}