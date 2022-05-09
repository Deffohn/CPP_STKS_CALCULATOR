#ifndef RESULT_HPP
#define RESULT_HPP

#include <iostream>

class Result
{

public:
    Result();

    std::string CleanCalcul(std::string calcul);

    float BracketPriority(std::string calcul);
    float Forward(std::string calcul);
};

#endif // RESULT_HPP
