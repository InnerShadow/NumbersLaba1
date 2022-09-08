#pragma once
#include <vector>
#include <cmath>
#include <iostream>

class XVector : public std::vector<double>{

public:

    XVector(int size);

    XVector() : std::vector<double>(){}

    double CountLenght();

    void Print();

    XVector operator-(XVector vec);

    double GetMaxElement();

    XVector operator+(XVector vec);

    double GetMinElement();

    void TurnAllAbs();

};