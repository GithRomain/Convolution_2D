//
// Created by Romain Pasquier on 14/09/2022.
//

#ifndef CONVOLUTION_2D_MATRIX_H
#define CONVOLUTION_2D_MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

template <class I>
class Matrix{
private:
    vector<vector<I>> mat;

public:
    //Constructor
    //To do : empty constructor
    Matrix(vector<vector<I>> mat);

    //Copy Constructor
    Matrix(Matrix<I> const &mat);

    //Calculate int value thanks to the matrix and the kernel
    //To do : verify if mat and kernel size are the same
    int calculateCoef(Matrix<I> &kernel);

    //FromCoef in mat to mat with the size of the kernel
    Matrix<I> fromCoefToMat(Matrix<I> &kernel, int &indI, int &indJ);

    //return the convolution mat
    Matrix<I> convolutionMat(Matrix<I> kernel);


    //Print the matrix attribute
    void print();
};


#endif //CONVOLUTION_2D_MATRIX_H
