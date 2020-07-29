
#include "world.h"

World::World() {

}

World::~World() {

}


olc::vi2d World::toScreen(int x, int y) {

    return {x, y};

}


void World::render(olc::PixelGameEngine *pge) {

    for(int y = 0; y < vWorldSize.y; y++) {
        for(int x = 0; x < vWorldSize.x; x++) {

            olc::vi2d vWorld = toScreen(x, y);

            switch(pWorld[y*vWorldSize.x + x]) {
                case 0:
                    pge->DrawPartialSprite(vWorld.x, vWorld.y, pSprIsom, 1*vTileSize.x, 0, vTileSize.x, vTileSize.y);
                    break;
            }

        }
    }

}