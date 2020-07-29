#include "ball.h"

using namespace std;


class World {

public:
    World(olc::vf2d size);
    ~World();

    vector<Ball> balls;
    olc::vf2d size;

    bool touching(Ball& b1, Ball& b2);
    void resolve(Ball& b1, Ball& b2);
    void go(float delta);
    void render(olc::PixelGameEngine &pge);
    void addBalls(int num);


};