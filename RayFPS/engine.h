
#include "pge.h"
#include "barrier.h"
#include "ray.h"
#include "collision.h"

class Engine : public olc::PixelGameEngine {
private:
    olc::vi2d res;

public:
    Engine(int x, int y);
    ~Engine();

    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;

};
