
#define OLC_PGE_APPLICATION

#include <iostream>
#include "main.h"
#include "world.h"

Launch launch;
World world;

int main() {

    if(launch.Construct(600, 600, 1, 1)) {
        launch.Start();
    }

}



bool Launch::OnUserCreate() {

    world.pSprIsom = new olc::Sprite("isometric_demo.png");
    world.pWorld = new int[world.vWorldSize.x * world.vWorldSize.y]{0};

    return true;
}

bool Launch::OnUserUpdate(float fElapsedTime) {

    Clear(olc::WHITE);


    return true;
}

