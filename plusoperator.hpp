#ifndef PLUSOPERATOR_H
#define PLUSOPERATOR_H
#include "operator.hpp"
#include <iostream>

class PlusOperator : public Operator
{
    public:
        PlusOperator(double a, double b);
        double execute();
};

#endif // PLUSOPERATOR_H
