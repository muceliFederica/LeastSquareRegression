#ifndef LEASTSQUAREREGRESSIONLIBRARY_H
#define LEASTSQUAREREGRESSIONLIBRARY_H

#include "leastsquareregressionlibrary_global.h"
#include <Eigen/LU>
#include <Eigen/Dense>

using Eigen::MatrixXf;
using std::vector;
class LEASTSQUAREREGRESSIONLIBRARYSHARED_EXPORT LeastSquareRegressionLibrary
{

    public:
        LeastSquareRegressionLibrary();
        std::vector<float> solveLinearSystem(std::vector<float> xCoords, std::vector<float> yCoords, int degree);
    private:
        MatrixXf createVandermondeMatrix(std::vector<float> xCoords,int degree);
        vector<float> convertToVector(MatrixXf m);
        MatrixXf convertToMatrix(vector<float> v);
};

#endif // LEASTSQUAREREGRESSIONLIBRARY_H
