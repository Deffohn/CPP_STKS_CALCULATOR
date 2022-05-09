#include "minusoperator.hpp"

MinusOperator::MinusOperator(double_error a, double_error b) : Operator(a, b)
{
}

//execute
double_error MinusOperator::execute()
{
    bool erroring = (a.error or b.error);
    return {erroring, this->a.value - this->b.value};
}
