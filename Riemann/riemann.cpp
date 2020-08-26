#include "riemann.h"

RiemannSum::RiemannSum() {

}
RiemannSum::~RiemannSum() {

}

float RiemannSum::calculate(Eq& eq, olc::PixelGameEngine &pge) {
    float total = 0;
    float scale = eq.maxX - eq.minX;
    scale /= res;

    bm::v2i begin = cam.WorldToScreen({eq.minX, 0});
    bm::v2i end = cam.WorldToScreen({eq.maxX, 0});
    pge.DrawLine(begin.x, begin.y, end.x, end.y, olc::RED);

    bm::v2f last = eq.get(0);
    bm::v2i scLast = cam.WorldToScreen(last);
    for(int i = 1; i < res; i++) {
        float nextX = eq.minX + i*scale;
        bm::v2f next = {nextX, eq.get(nextX)};
        bm::v2i scNext = cam.WorldToScreen(next);

        pge.DrawLine(scLast.x, scLast.y, scNext.x, scNext.y);

        last = next;
        scLast = scNext;

    }

    return 0;

}