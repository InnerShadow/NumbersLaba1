#include <iostream>
#include "matrix.hpp"
#include "Xvector.hpp"

void FillDefualtVecForTask13(XVector& vec){
    vec.at(0) = 1.0f;
    vec.at(1) = 2.0f;
    vec.at(2) = 3.0f;
    vec.at(3) = -1.0f;
}

int main(void){

    Matrix mtr(4);

    XVector defualtVec(4);
    FillDefualtVecForTask13(defualtVec);

    mtr.FillTask13();
    mtr.Print();
    Matrix GauseMtr = mtr.ForwardGause(true, true);
    GauseMtr.Print();
    XVector vec = GauseMtr.BackGause();

    vec.Print();

    Matrix mtr1 = mtr;
    mtr1.TekeNewVector(vec);
    mtr1.Print();

    XVector AX = mtr1 * vec;

    XVector deltaVec = AX - defualtVec;

    // std::cout << "Deltavec: ";
    // deltaVec.Print();

    double delta = deltaVec.GetMaxElement();

    std::cout << "Delta: " << delta << std::endl;

    Matrix mtr2 = mtr1.ForwardGause(true, true);

    mtr2.Print();

    XVector SolutionMTR2 = mtr2.BackGause();

    XVector SIGMAVec = SolutionMTR2 + vec;

    // std::cout << "Xyi: " << vec.GetMinElement()<< std::endl;

    double Sigma = SIGMAVec.GetMinElement() / vec.GetMaxElement();

    std::cout << "SIGMA: " << Sigma << std::endl;

    Matrix LDLMatrix(3);

    LDLMatrix.FillLambdaTask(1, 100, 200);

    std::cout << "Labmda task: \n";
    LDLMatrix.Print();

    Matrix LT = LDLMatrix.ForwardGause(false, true);

    LT.Print();

    Matrix L = LDLMatrix.ForwardGause(false, true).GetTransponent();

    L.Print();

    Matrix D = LDLMatrix.ForwardGause(false, false);
    D = D.GetTransponent();
    D = D.ForwardGause(false, false);

    D.Print();

    Matrix Reverse = L * D * LT;

    LDLMatrix.ForwardGause(true, true).BackGause().Print();

    return 0;
}