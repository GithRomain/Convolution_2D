//
// Created by Romain Pasquier on 14/09/2022.
//

#include "Matrix.h"

template <class I>
Matrix<I>::Matrix(vector<vector<I>> mat) {
    this->mat = mat;
}

template <class I>
Matrix<I>::Matrix(Matrix<I> const &mat) {
    this->mat = mat.mat;
}

template <class I>
void Matrix<I>::print(){
    for (vector<I> &l : mat) {
        for (I &c: l) {
            cout << c << ". ";
        }
        cout << endl;
    }
}

template <class I>
int Matrix<I>::calculateCoef(Matrix<I> &kernel) {
    //initialize the coef to return
    int coef = 0;
    //initialize indexs
    int i = 0;
    int j = 0;

    for (vector<I> &l : mat){
        for (I &c : l){
            coef += c * kernel.mat.at(i).at(j);
            //incr
            j++;
        }
        //incr
        i++;
        //reset j for a new i
        j = 0;
    }
    return coef;
}

template <class I>
Matrix<I> Matrix<I>::fromCoefToMat(Matrix<I> &kernel, int &indI, int &indJ) {
    //initialize an empty mat to convert into Matrix object and return at the end
    vector<vector<I>> matrix(kernel.mat.size(), vector<I>(kernel.mat.at(0).size(), 0));
    Matrix<I> res(matrix);
    //initialize index of the top of the kernel (index of the center - size of kernel / 2)
    int i = indI - kernel.mat.size()/2;
    int j = indJ - kernel.mat.at(0).size()/2;

    for (vector<I> &l : res.mat){
        for (I &c : l){
            //only modify element when the filter touch the matrix, even leave a 0 (on the border)
            if (i >= 0 && j >= 0 && i <= kernel.mat.size() && j <= kernel.mat.at(0).size()) {
                c = mat.at(i).at(j);
            }
            //incr
            j++;
        }
        //incr j
        i++;
        //reset j
        j = indJ - kernel.mat.at(0).size()/2;
    }
    return res;
}

template <class I>
Matrix<I> Matrix<I>::convolutionMat(Matrix<I> kernel) {
    Matrix<I> convolution(mat);
    //initialize indexs
    int i = 0;
    int j = 0;

    for (vector<I> &l : convolution.mat){
        for (I &c : l){
            c = fromCoefToMat(kernel, i, j).calculateCoef(kernel);
            //incr
            j++;
        }
        //incr
        i++;
        //reset j for a new i
        j = 0;
    }
    return convolution;
}
