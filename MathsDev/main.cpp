

#include "maths.h"

using namespace std;


M2 mat2;
M2 mat22;

int main() {

    mat2.vals[0][0] = 7;
    mat2.vals[0][1] = 2;
    mat2.vals[1][1] = 1;
    mat2.vals[1][0] = 3;
    // mat2.vals[2][1] = 3;
    // mat2.vals[0][2] = -12;
    // mat2.vals[2][3] = 6;
    // mat2.vals[3][1] = 5;

    mat2.print();

    mat22 = mat2;
    mat22.invert();
    mat22.print();

    mat2 *= mat22;
    mat2.print();


    return 0;
}