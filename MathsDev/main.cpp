

#include "maths.h"

using namespace std;

Mat<float, 6> mat;
Mat<float, 6> mat2;

int main() {

    mat.vals[0][0] = 7;
    mat.vals[0][1] = 2;
    mat.vals[1][1] = 1;
    mat.vals[1][0] = 3;
    mat.vals[2][1] = 3;
    mat.vals[0][2] = 12;
    mat.vals[2][3] = 6;
    mat.vals[3][1] = 5;
    mat.vals[3][3] = 17;
    mat.vals[4][4] = 12;
    mat.vals[5][5] = 19;
    mat.vals[3][4] = 7;
    mat.vals[5][2] = 2;

    mat.print();

    mat2 = mat;
    mat2.invert();
    mat2.print();

    mat *= mat2;
    mat.print();


    return 0;
}