#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"

using namespace std;

int main() {
    Matrix<int> mat({
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    });

    Matrix<int> kernel({
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    });
    int i = 0;
    int j = 3;
    //cout << mat.calculateCoef(kernel);
    mat.convolutionMat(kernel).print();
    //mat.fromCoefToMat(kernel, i, j).print();
    return 0;
}
