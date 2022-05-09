#include "divideoperator.hpp"

DivideOperator::DivideOperator(double_error a, double_error b) : Operator(a, b)
{
}

//execute
double_error DivideOperator::execute()
{
    bool erroring = (a.error or b.error);
    if (b.value == 0) return {true, 0};
    return {erroring, this->a.value / this->b.value};
}
