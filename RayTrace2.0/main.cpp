#define OLC_PGE_APPLICATION

#include "pge.h"
#include "iostream"
#include "renderer.h"


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
void buildScene();
bool Main::OnUserUpdate(float fElapsedTime) {


    return true;
}

Camera cam;

bool Main::OnUserCreate() {
    buildScene();

    render(*this, {res.x, res.y}, cam);

    return true;
}


void buildScene() {

}