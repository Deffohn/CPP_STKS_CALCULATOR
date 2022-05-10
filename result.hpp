#ifndef RESULT_HPP
#define RESULT_HPP

#include "plusoperator.hpp"
#include "typevalue.hpp"

#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdlib>

class Result{
private:
    bool reversePolish = false;
public:
    Result(bool reversePolish);

    std::string CleanCalcul(std::string calcul);

    std::string CleanReversePolishCalcul(std::string calcul);

    int OperatorScan(char current_strong_operator, int pos_strong_operator, char current_operator, int pos_current_operator);

    int BracketScan(std::string calcul);

    double_error Numbering(std::string calcul, double_error val, bool isComa, bool isNegative, double precision, int cursor, std::string full_calcul);

    double_error Forward(std::string calcul, int cursor, std::string full_calcul);
    double_error ForwardReversePolish(const std::string &calcul);

};



#endif // RESULT_HPP
