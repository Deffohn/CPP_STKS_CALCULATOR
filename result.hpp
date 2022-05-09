#ifndef RESULT_HPP
#define RESULT_HPP

#include "plusoperator.hpp"
#include <typevalue.hpp>

#include <iostream>

std::string CleanCalcul(std::string calcul);

int BracketScan(std::string calcul);

double_error Numbering(std::string calcul, double_error val, bool isComa, double precision);

double_error Forward(std::string calcul);

#endif // RESULT_HPP
