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

bm::v2f test1 = {0.5, 0.5};
bm::v2f test2(test1);


bool Main::OnUserCreate() {

    test1.print();
    test2.print();

    test2 += 0.25;
    test2.x -= 0.5;
    test2.print();

    (test1 + test2).print();

    test1 += test2;
    test1.print();

    test1 *= 2;
    test1.print();

    bm::v3f t1(1, 0, 1);
    bm::v3f t2(0, 1, 0);

    bm::cross(t1, t2).print();
    std::cout << std::endl;

    bm::m2 mat1;
    mat1.identity().print();
    bm::m2 mat2;
    mat2.identity();
    mat2.vals[0][0] = 2;
    mat2.vals[0][1] = 3;
    mat2.vals[1][0] = 4;
    mat2.vals[1][1] = 5;
    mat2.print();

    (mat1 * mat2).print();


    return true;
}

bool Main::OnUserUpdate(float fElapsedTime) {



    return true;
}