#ifndef RESULT_HPP
#define RESULT_HPP

#include <iostream>


typedef struct{
    bool error;
    double value;
}double_error;


std::string CleanCalcul(std::string calcul);


#endif // RESULT_HPP
