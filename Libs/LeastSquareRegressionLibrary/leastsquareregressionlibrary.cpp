#include "leastsquareregressionlibrary.h"


LeastSquareRegressionLibrary::LeastSquareRegressionLibrary()
{
}


std::vector<float> LeastSquareRegressionLibrary::solveLinearSystem(std::vector<float> xCoords, std::vector<float> yCoords, int degree)
{
    MatrixXf vandermondeMatrix=createVandermondeMatrix(xCoords,degree);
    MatrixXf y=convertToMatrix(yCoords);

    MatrixXf coeffRegressionLineM=(vandermondeMatrix.transpose() * vandermondeMatrix).ldlt().solve(vandermondeMatrix.transpose() *y);
    vector<float> coeffRegressionLine=convertToVector(coeffRegressionLineM);
    return coeffRegressionLine;
}

MatrixXf LeastSquareRegressionLibrary::createVandermondeMatrix(std::vector<float> xCoords,int degree)
{
    MatrixXf VandermondeMatrix(xCoords.size(),degree+1);
    for(int i=0;i<VandermondeMatrix.rows();i++)
    {
        for(int j=0;j<VandermondeMatrix.cols();j++)
        {
            VandermondeMatrix(i,j)=pow(xCoords.at(i),j);
        }
    }
    return VandermondeMatrix;
}

vector<float> LeastSquareRegressionLibrary::convertToVector(MatrixXf m)
{
    vector<float> v;
    for(int i=0;i<m.rows();i++)
    {
        v.push_back(m(i));
    }
    return v;
}

MatrixXf LeastSquareRegressionLibrary::convertToMatrix(vector<float> v)
{
    MatrixXf m=MatrixXf(v.size(),1);
    for(unsigned int i=0;i<v.size();i++)
    {
        m(i,0)=v.at(i);
    }
    return m;

}
