#include "Applications/Example/Example.h"


int main() {
    Engine* app = new Example();
    app->Run();
    delete app;
}
