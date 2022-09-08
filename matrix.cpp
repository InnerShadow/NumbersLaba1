#include "matrix.hpp"

Matrix::Matrix(int size){

    std::vector<std::vector<double>> TempMatrix(size, std::vector<double>(size, 0));
    XVector vec(size);
    matrix = TempMatrix;
    Vector = vec;
}

void Matrix::Print(){

    for(int i = 0; i < matrix.size(); i++){
        for(int i_n = 0; i_n < matrix.at(i).size(); i_n++){
            printf("%10.3f%", matrix.at(i).at(i_n));
        }
        printf("%10.3f", Vector.at(i));
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::PrintWithotB(){
    for(int i = 0; i < matrix.size(); i++){
        for(int i_n = 0; i_n < matrix.at(i).size(); i_n++){
            printf("%10.3f%", matrix.at(i).at(i_n));
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::GetMaxElement(int& swapTo, int column){

    int lastMax = INT32_MIN;

    for(int i = column; i < matrix.size(); i++){
        if(abs(matrix.at(i).at(column)) > lastMax){
            lastMax = matrix.at(column).at(i);
            swapTo = i;
        }
    }
}

Matrix Matrix::ForwardGause(bool IFB, bool IdDiagonal1){
    Matrix tempMatrix = *this;

    for(int i = 0; i < tempMatrix.matrix.size(); i++){

        // std::cout << "Befor swap: " << std::endl;
        // tempMatrix.Print();

        // int swapTo = 0;
        // tempMatrix.GetMaxElement(swapTo, i);
        // tempMatrix.matrix.at(i).swap(tempMatrix.matrix.at(swapTo));
        // std::swap(Vector.at(i), Vector.at(swapTo));

        // std::cout << "After swap: " << std::endl;
        // tempMatrix.Print();

        std::vector<double> coefficients(matrix.size() + 1, 0);
        for(int i_n = i + 1; i_n < tempMatrix.matrix.size(); i_n++){
            coefficients.at(i_n - 1) = tempMatrix.matrix.at(i_n).at(i) / tempMatrix.matrix.at(i).at(i);
        }

        for(int i_m = i; i_m < matrix.size(); i_m++){
            for(int i_n = i + 1; i_n < matrix.size(); i_n++){
                tempMatrix.matrix.at(i_n).at(i_m) -= tempMatrix.matrix.at(i).at(i_m) * coefficients.at(i_n - 1);
            }
        }

        if(IFB){
            for(int i_n  = i + 1; i_n < matrix.size(); i_n++){
                tempMatrix.Vector.at(i_n) -= tempMatrix.Vector.at(i) * coefficients.at(i_n - 1);
            }
            tempMatrix.Vector.at(i) /= tempMatrix.matrix.at(i).at(i);
        }

        if(IdDiagonal1){
            for(int i_n = matrix.size() - 1; i_n >= i; i_n--){
                tempMatrix.matrix.at(i).at(i_n) /= tempMatrix.matrix.at(i).at(i);
            }
        }
    }

    return tempMatrix;
}

Matrix Matrix::operator* (Matrix mtr){
    Matrix tempMatrix(matrix.size());
    for(int  i = 0; i < matrix.size(); i++){
        for(int i_n = 0; i_n < matrix.size(); i_n++){
            double sum = 0.f;
            for(int i_m = 0; i_m < matrix.size(); i_m++){
                sum += matrix.at(i).at(i_m) * mtr.matrix.at(i_m).at(i_n);
            }
            tempMatrix.matrix.at(i).at(i_n) = sum;
        }
    }
    return tempMatrix;
}


XVector Matrix::BackGause(){
    XVector tempVector(matrix.size());
    for(int i = tempVector.size() - 1; i >= 0; i--){
        double value = Vector.at(i);
        for(int i_n = tempVector.size() - 1; i_n > i; i_n--){
            value -= matrix.at(i).at(i_n) * tempVector.at(i_n);
            // std::cout << "Value: " << value << std::endl;
        }
        tempVector.at(i) = value / matrix.at(i).at(i);
    }
    return tempVector;
}

void Matrix::TekeNewVector(XVector Vector){
    this->Vector = Vector;
}

XVector Matrix::operator* (XVector vec){
    XVector tempVector(Vector.size());
    for(int i = 0; i < matrix.size(); i++){
        for(int i_n = 0; i_n < matrix.size(); i_n++){
            tempVector.at(i) += matrix.at(i).at(i_n) * vec.at(i_n);
            // std::cout << tempVector.at(i) << std::endl;
        }
        // std::cout << std::endl;
    }


    return tempVector;
}

Matrix Matrix::GetTransponent(){
    Matrix tempMatrix(matrix.size());
    for(int i = 0; i < matrix.size(); i++){
        for(int i_n = 0; i_n < matrix.size(); i_n++){
            tempMatrix.matrix.at(i).at(i_n) = matrix.at(i_n).at(i);
        }
    }
    return tempMatrix;
}

void Matrix::FillTask13(){
    matrix.at(0).at(0) = 2.0f;
    matrix.at(0).at(1) = 1.0f;
    matrix.at(0).at(2) = -0.1f;
    matrix.at(0).at(3) = 1.0f;
    // matrix.at(0).at(4) = 1.0f;
    matrix.at(1).at(0) = 0.4f;
    matrix.at(1).at(1) = 0.5f;
    matrix.at(1).at(2) = 4.0f;
    matrix.at(1).at(3) = -8.5f;
    // matrix.at(1).at(4) = 2.0f;
    matrix.at(2).at(0) = 0.3f;
    matrix.at(2).at(1) = -1.0f;
    matrix.at(2).at(2) = 1.0f;
    matrix.at(2).at(3) = 5.2f;
    // matrix.at(2).at(4) = 3.0f;
    matrix.at(3).at(0) = 1.0f;  // 1.0f
    matrix.at(3).at(1) = 0.2f;
    matrix.at(3).at(2) = 2.5f;
    matrix.at(3).at(3) = -1.0f;
    // matrix.at(3).at(4) = -1.0f;

    Vector.at(0) = 1.0f;
    Vector.at(1) = 2.0f;
    Vector.at(2) = 3.0f;
    Vector.at(3) = -1.0f;
}

void Matrix::FillLambdaTask(double Lambda1, double Lambda2, double Lambda3){
    matrix.at(0).at(0) = 2 * Lambda1 + 4 * Lambda2;
    matrix.at(0).at(1) = 2 * (Lambda1 - Lambda2);
    matrix.at(0).at(2) = 2 * (Lambda1 - Lambda2);
    // matrix.at(0).at(3) = -4 * Lambda1 - 2 * Lambda2;
    matrix.at(1).at(0) = 2 * (Lambda1 - Lambda2);;
    matrix.at(1).at(1) = 2 * Lambda1 + Lambda2 + 3 * Lambda3;
    matrix.at(1).at(2) = 2 * Lambda1 + Lambda2 - 3 * Lambda3;
    // matrix.at(1).at(3) = -4 * Lambda1 + Lambda2 + 9 * Lambda3;
    matrix.at(2).at(0) = 2 * (Lambda1 - Lambda2);
    matrix.at(2).at(1) = 2 * Lambda1 + Lambda2 - 3 * Lambda3;
    matrix.at(2).at(2) = 2 * Lambda1 + Lambda2 + 3 * Lambda3;
    // matrix.at(2).at(3) = -4 * Lambda1 + Lambda2 - 9 * Lambda3;

    Vector.at(0) = -4 * Lambda1 - 2 * Lambda2;
    Vector.at(1) = -4 * Lambda1 + Lambda2 + 9 * Lambda3;
    Vector.at(2) = -4 * Lambda1 + Lambda2 - 9 * Lambda3;
}
