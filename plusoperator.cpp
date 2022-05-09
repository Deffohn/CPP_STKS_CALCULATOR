#include "plusoperator.hpp"
//constructor double a, double b
PlusOperator::PlusOperator(double_error a, double_error b) : Operator(a, b)
{
}

//execute
double_error PlusOperator::execute()
{
    bool erroring = (a.error or b.error);
    return {erroring, this->a.value + this->b.value};
}


