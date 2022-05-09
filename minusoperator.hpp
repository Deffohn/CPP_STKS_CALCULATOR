#ifndef MINUSOPERATOR_HPP
#define MINUSOPERATOR_HPP

#include "operator.hpp"

#include <typevalue.hpp>

class MinusOperator : public Operator
{
    public:
        MinusOperator(double_error a, double_error b);
        double_error execute();
};

#endif // MINUSOPERATOR_HPP
