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

    std::cout << "Vec: ";
    vec.Print();

    Matrix mtr1 = mtr;
    mtr1.TekeNewVector(vec);

    XVector AX = mtr1 * vec;

    XVector deltaVec = AX - defualtVec;

    std::cout << "Deltavec: ";
    deltaVec.Print();

    double delta = deltaVec.GetMaxElement();

    std::cout << "Delta: " << delta << std::endl;

    mtr1.Print();

    Matrix mtr2 = mtr1.ForwardGause(true, true);

    mtr2.Print();

    XVector SolutionMTR2 = mtr2.BackGause();

    std::cout << "Solution: ";
    SolutionMTR2.Print();

    SolutionMTR2.TurnAllAbs();
    vec.TurnAllAbs();
    XVector SIGMAVec = SolutionMTR2 - vec;

    std::cout << "SigmaVec: ";
    SIGMAVec.Print();

    double Sigma = SIGMAVec.GetMinElement() / vec.GetMaxElement();

    std::cout << "SIGMA: " << Sigma << std::endl;

    Matrix LDLMatrix(3);

    LDLMatrix.FillLambdaTask(1.2, 2.3, 3.4);

    std::cout << "Labmda task: \n";
    LDLMatrix.Print();

    LDLMatrix.ForwardGause(true, true).BackGause().Print();

    LDLMatrix = LDLMatrix.LDLT();

    LDLMatrix.Print();

    XVector resualt = LDLMatrix * LDLMatrix.GetVector();

    //resualt.Print();

    return 0;
}