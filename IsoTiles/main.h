
#include "pge.h"

class Launch : public olc::PixelGameEngine {
public:
    Launch() {

    }
    ~Launch() {

    }

public:
    bool OnUserCreate();
    bool OnUserUpdate(float fElapsedTime);

};
