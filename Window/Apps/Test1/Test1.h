#include "../../Engine/Engine.h"

class Test1 : public Engine {
public:

    Test1(Window* window, Renderer* rend);
    ~Test1();

private:
    virtual void Init() override;
    virtual void Update(float delta) override;
    virtual void Render() override;
    virtual void Close() override;

};