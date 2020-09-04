

#define OLC_PGE_APPLICATION
#include "engine.h"


int main() {

    Engine engine(600, 600);
    engine.Construct(600, 600, 1, 1);
    engine.Start();

    return 0;
}