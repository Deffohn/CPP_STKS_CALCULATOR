#ifndef POWEROPERATOR_HPP
#define POWEROPERATOR_HPP

#include "operator.hpp"

#include <typevalue.hpp>

class PowerOperator : public Operator
{
    public:
        PowerOperator(double_error a, double_error b);
        double_error execute();
};



#endif // POWEROPERATOR_HPP
