#include "poweroperator.hpp"

#include <cmath>

PowerOperator::PowerOperator(double_error a, double_error b) : Operator(a, b)
{
}

//execute
double_error PowerOperator::execute()
{
    bool erroring = (a.error or b.error);
    if (a.value == 0 and b.value == 0) return {true, 0};
    return {erroring, pow(this->a.value, this->b.value)};
}
