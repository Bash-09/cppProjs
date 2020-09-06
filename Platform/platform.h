#pragma once

class Platform {
public:

    virtual void NewThread(void* target) = 0;
    virtual void StartWindow() = 0;


};