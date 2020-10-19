#include "Apps/Test1/Test1.h"

int main() {

    Window window;
    Renderer rend;

    Test1 app(&window, &rend);

    window.createWindow("Test Window", 600, 400, true);

    app.Setup();
    app.enterLoop();

    std::cout << "Closing!\n";

    return 0;

}