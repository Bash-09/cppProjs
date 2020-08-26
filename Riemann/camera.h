#pragma once

#include "maths.h"

class Camera {
private:
    bm::v2f pos;
    float xScale = 1;
    float yScale = 1;

public:
    Camera();
    ~Camera();

    bm::v2i WorldToScreen(bm::v2f pos);
    bm::v2f ScreenToWorld(bm::v2i screen);

    void translate(bm::v2f mov);
    void scaleX(float scale);
    void scaleY(float scale);
};