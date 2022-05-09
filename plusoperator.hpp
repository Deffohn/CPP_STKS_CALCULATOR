#ifndef PLUSOPERATOR_H
#define PLUSOPERATOR_H
#include "operator.hpp"
#include <iostream>

#include <typevalue.hpp>

class PlusOperator : public Operator
{
    public:
        PlusOperator(double_error a, double_error b);
        double_error execute();
};

#endif // PLUSOPERATOR_H
