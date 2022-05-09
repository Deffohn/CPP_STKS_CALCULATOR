#ifndef OPERATOR_HPP
#define OPERATOR_HPP
#include <iostream>
#include "mainwindow.hpp"

#include <typevalue.hpp>

class Operator
{
    protected:
        double_error a;
        double_error b;
    public:
        Operator(double_error a, double_error b);
        //virtual execute(double_error a, double_error b);
        virtual double_error execute() = 0;
        void printError(std::string error);
        
};

#endif // OPERATOR_HPP
