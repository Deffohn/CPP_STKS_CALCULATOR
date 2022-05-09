#include "plusoperator.hpp"
//constructor double a, double b
PlusOperator::PlusOperator(double a, double b) : Operator(a, b)
{
    //set a & b
    this->a = a;
    this->b = b;
}

//execute
double PlusOperator::execute()
{
    return this->a + this->b;
}