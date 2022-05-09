#include "plusoperator.hpp"
//constructor double a, double b
PlusOperator::PlusOperator(double a, double b) : Operator(a, b)
{
}

//execute
double PlusOperator::execute()
{
    double result = a + b;
    return result;
}


