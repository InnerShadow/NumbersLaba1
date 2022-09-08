
#include "Xvector.hpp"

double TakeABS(double value){
    if(value > 0){
        return value;
    } else {
        return value * (-1);
    }
}

double XVector::CountLenght(){
    double value = 0.f;
    for(int i = 0; i < size(); i++){
        value += pow(at(i), 2);
    }
    value = sqrt(value);
    return value;
}

XVector::XVector(int size) : std::vector<double>(size){}

void XVector::Print(){
    for(int i = 0; i < size(); i++){
        std::cout << at(i) << " ";
    }
    std::cout << std::endl;
}

XVector XVector::operator-(XVector vec){
    XVector tempvec(size());
    for(int i = 0; i < size(); i++){
        tempvec.at(i) = at(i) - vec.at(i);
    }
    return tempvec;
}

XVector XVector::operator+(XVector vec){
    XVector tempvec(size());
    for(int i = 0; i < size(); i++){
        tempvec.at(i) = at(i) + vec.at(i);
    }
    return tempvec;
}

double XVector::GetMinElement(){
    double value = 10000.f;
    for(int i = 0 ; i < size(); i++){
        if(TakeABS(at(i)) < value){
            value = TakeABS(at(i));
        }
    }
    return value;
}

double XVector::GetMaxElement(){
    double value = 0.f;
    for(int i = 0 ; i < size(); i++){
        if(TakeABS(at(i)) > value){
            value = TakeABS(at(i));
        }
    }
    return value;
}