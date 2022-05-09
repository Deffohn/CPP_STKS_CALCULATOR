#include "operator.hpp"

//Constructor double a, double b
Operator::Operator(double a, double b)
{
    this->a = a;
    this->b = b;
}

//PrintError
void Operator::printError(std::string error)
{
    std::cout << error << std::endl;
}

