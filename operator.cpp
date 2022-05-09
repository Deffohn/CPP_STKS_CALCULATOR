#include "operator.hpp"


//Constructor double a, double b
Operator::Operator(double_error a, double_error b)
{
    this->a = a;
    this->b = b;
}


//PrintError
void Operator::printError(std::string error)
{
    std::cout << error << std::endl;
}


