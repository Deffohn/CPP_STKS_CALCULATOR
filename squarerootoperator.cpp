#include "squarerootoperator.hpp"

SquareRootOperator::SquareRootOperator(double_error a)
{
    this->a = a;
}

double_error SquareRootOperator::execute()
{
    bool erroring = a.error;
    if (0 <= a.value) return {erroring, sqrt(this->a.value)};
    return {true, 0};
}
