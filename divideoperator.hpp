#ifndef DIVIDEOPERATOR_HPP
#define DIVIDEOPERATOR_HPP

#include "operator.hpp"

#include <typevalue.hpp>

class DivideOperator : public Operator
{
    public:
        DivideOperator(double_error a, double_error b);
        double_error execute();
};

#endif // DIVIDEOPERATOR_HPP
