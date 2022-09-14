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
    Matrix GauseMtr = mtr.ForwardGause();
    GauseMtr.Print();
    XVector vec = GauseMtr.BackGause();

    std::cout << "Vec: ";
    vec.Print();

    Matrix mtr1 = mtr;
    mtr1.TekeNewVector(vec);

    XVector AX = mtr1 * vec;

    std::cout << "aX:" ;
    AX.Print();

    XVector deltaVec = AX - defualtVec;

    std::cout << "Deltavec: ";
    deltaVec.Print();

    double delta = deltaVec.GetMaxElement();

    std::cout << "Delta: " << delta << std::endl;

    std::cout << "mtr1: \n";
    mtr1.TekeNewVector(AX);
    mtr1.Print();

    Matrix mtr2 = mtr1.ForwardGause();

    std::cout << "mtr2: \n";
    mtr2.Print();

    XVector SolutionMTR2 = mtr2.BackGause();

    std::cout << "SolutionMTR2: ";
    SolutionMTR2.Print();

    SolutionMTR2.TurnAllAbs();
    vec.TurnAllAbs();
    // XVector SIGMAVec = SolutionMTR2 - vec;

    // std::cout << "SigmaVec: ";
    // SIGMAVec.Print();

    double Sigma = 0.f;
    double max = 0.f;
    for(int i = 0; i < vec.size(); i++){
        max = (SolutionMTR2.at(i) - vec.at(i)) / (vec.at(i));
        if(Sigma < max){
            Sigma = max;
        }
    }

    std::cout << "SigMA: " << Sigma << std::endl;

    Matrix LDLMatrix(3);

    LDLMatrix.FillLambdaTask(1.234, 2.3243, 3.5324);

    std::cout << "Labmda task: \n";
    LDLMatrix.Print();

    LDLMatrix.ForwardGause().BackGause().Print();

    LDLMatrix = LDLMatrix.LDLT();

    // LDLMatrix.Print();

    XVector resualt = LDLMatrix * LDLMatrix.GetVector();

    //resualt.Print();

    return 0;
}