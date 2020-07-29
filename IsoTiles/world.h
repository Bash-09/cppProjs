#include "pge.h"

class World {
public:
    World();
    ~World();

public:
    olc::vi2d vWorldSize = {14, 10};
    olc::vi2d vTileSize = {40, 20};
    olc::vi2d vOrigin = {5, 1};
    olc::Sprite *pSprIsom = nullptr;
    int *pWorld = nullptr;

    void render(olc::PixelGameEngine *pge);
    olc::vi2d toScreen(int x, int y);

};