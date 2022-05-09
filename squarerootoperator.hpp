#ifndef SQUAREROOTOPERATOR_HPP
#define SQUAREROOTOPERATOR_HPP

#include <cmath>

#include <typevalue.hpp>

class SquareRootOperator
{
protected:
    double_error a;
public:
    SquareRootOperator(double_error a);
    double_error execute();
};

#endif // SQUAREROOTOPERATOR_HPP
