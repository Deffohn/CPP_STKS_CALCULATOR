#include "multiplyoperator.hpp"

MultiplyOperator::MultiplyOperator(double_error a, double_error b) : Operator(a, b)
{
}

//execute
double_error MultiplyOperator::execute()
{
    bool erroring = (a.error or b.error);
    return {erroring, this->a.value * this->b.value};
}
