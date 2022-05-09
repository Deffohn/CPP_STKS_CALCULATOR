#include "squarerootoperator.hpp"

SquareRootOperator::SquareRootOperator(double_error a)
{
    this->a = a;
}

double_error SquareRootOperator::execute()
{
    bool erroring = a.error;
    return {erroring, sqrt(this->a.value)};
}
