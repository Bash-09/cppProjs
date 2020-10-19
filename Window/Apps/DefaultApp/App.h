#include "../../Engine/Engine.h"

class Application : public Engine {
public:

    Application(Window* window, Renderer* rend);
    ~Application();

private:
    virtual void Init() override;
    virtual void Update(float delta) override;
    virtual void Render() override;
    virtual void Close() override;

};