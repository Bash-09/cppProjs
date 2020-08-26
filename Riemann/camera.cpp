#include "camera.h"


Camera::Camera() {

}
Camera::~Camera() {

}

bm::v2i Camera::WorldToScreen(bm::v2f pos) {
    pos -= this->pos;

    pos.x /= xScale;
    pos.y /= -yScale;

    return bm::v2i((int)pos.x, (int)pos.y);
}

bm::v2f Camera::ScreenToWorld(bm::v2i screen) {
    bm::v2f pos = {(float)screen.x, (float)screen.y};
    pos.x *= xScale;
    pos.y *= -yScale;

    pos += this->pos;
    return pos;
}


void Camera::translate(bm::v2f mov) {
    pos += {mov.x, -mov.y};
}
void Camera::scaleX(float scale) {
    xScale *= scale;
}
void Camera::scaleY(float scale) {
    yScale *= scale;
}