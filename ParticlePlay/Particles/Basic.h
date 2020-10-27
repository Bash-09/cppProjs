#pragma once

#include <math.h>
#include "../Particle.h"

class P_Basic : public Particle {
    public:
        P_Basic(V2f pos, olc::Renderable* texture);
        bool go(float delta) override;
    private:
        V2f vel = {5, 5};
};
