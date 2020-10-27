#pragma once

#include "Engine.h"

class Example : public Engine {
    public:
        Example();
        ~Example();

    private:
        void Init() override;
        void Update() override;
        void Render() override;
        void Close() override;


};
