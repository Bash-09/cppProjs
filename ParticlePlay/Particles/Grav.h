#pragma once

#include "../Particle.h"

class P_Grav : public Particle {
    public:
        P_Grav(V2f pos, olc::Renderable* texture);
        bool go(float delta) override;

    private:
        V2f vel = {0, 0};

};
