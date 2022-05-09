#ifndef PLUSOPERATOR_H
#define PLUSOPERATOR_H
#include "operator.hpp"
#include <iostream>

class PlusOperator : Operator
{
    private:
        double a;
        double b;
    public:
        PlusOperator(double a, double b);
        double execute();
};

#endif // PLUSOPERATOR_H
