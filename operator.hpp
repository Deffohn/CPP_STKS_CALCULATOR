#ifndef OPERATOR_HPP
#define OPERATOR_HPP
#include <iostream>

class Operator
{
    protected:
        double a;
        double b;
    public:
        Operator(double a, double b);
        //virtual execute(double a, double b);
        virtual double execute() = 0;
        void printError(std::string error);
};

#endif // OPERATOR_HPP
