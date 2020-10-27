#pragma once

#define WIN_SDL

#include "Event/Events.h"

class Engine {
public:
    Engine() {}
    ~Engine() {}

    void Run() {
        Init();
        while(true) {
            Update();
            Render();
        }
        Close();
    }

protected:
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Close() = 0;

};
