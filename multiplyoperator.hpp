#ifndef MULTIPLYOPERATOR_HPP
#define MULTIPLYOPERATOR_HPP

#include "operator.hpp"

#include <typevalue.hpp>

class MultiplyOperator : public Operator
{
    public:
        MultiplyOperator(double_error a, double_error b);
        double_error execute();
};

#endif // MULTIPLYOPERATOR_HPP
