#include "result.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

#include <plusoperator.hpp>
#include <minusoperator.hpp>
#include <multiplyoperator.hpp>
#include <divideoperator.hpp>
#include <poweroperator.hpp>
#include <squarerootoperator.hpp>

const std::string Numbers("0123456789");

const std::string Operators("+-*/^");


Result::Result(bool reversePolish): reversePolish(reversePolish){}

std::string Result::CleanCalcul(std::string calcul)
{
    bool html_balise_test = false;
    std::string clean_calcul = "";
    for (int idx = 0; idx < calcul.length(); idx++)
    {
        if (calcul[idx] == '<')
        {
            html_balise_test = true;
        }
        else if (calcul[idx] == '>')
        {
            html_balise_test = false;
        }
        else if (!html_balise_test and calcul[idx] != ' ' and calcul[idx] != '=')
        {
            clean_calcul.append(std::string{ calcul[idx] });
        }
    }
    return clean_calcul;
}

std::string Result::CleanReversePolishCalcul(std::string calcul)
{
    bool html_balise_test = false;
    std::string clean_calcul = "";
    for (int idx = 0; idx < calcul.length(); idx++)
    {
        if (calcul[idx] == '<')
        {
            html_balise_test = true;
        }
        else if (calcul[idx] == '>')
        {
            html_balise_test = false;
        }
        else if (!html_balise_test)
        {
            clean_calcul.append(std::string{ calcul[idx] });
        }
    }
    return clean_calcul;
}

int Result::BracketScan(std::string calcul)
{
    int parenthesis_opens_amount = 1;
    int parenthesis_closes_amount = 0;
    int parenthesis_closes_at = -1;
    for (int idx = 0; idx < calcul.length(); idx++){
        switch (calcul[idx]){
            case '(':
                parenthesis_opens_amount++;
                break;
            case ')':
                parenthesis_closes_amount++;
                parenthesis_closes_at = idx;
                if (parenthesis_opens_amount == parenthesis_closes_amount)
                    return parenthesis_closes_at;
        }
    }
    return -1;
}

int Result::OperatorScan(char current_strong_operator, int pos_strong_operator, char current_operator, int pos_current_operator)
{
    if (pos_strong_operator == -1) return pos_current_operator;
    else {
        for (int idx_check_operator = 0; idx_check_operator < Operators.length(); idx_check_operator ++){
            if (current_operator == Operators[idx_check_operator]) return pos_current_operator;
            else if (current_strong_operator == Operators[idx_check_operator]) return pos_strong_operator;
        }
        return pos_current_operator;
    }
}

// make precision -1 if first char is '.' else if first is a number put '0'
double_error Result::Numbering(std::string calcul, double_error val, bool isComa, bool isNegative, double precision, int cursor, std::string full_calcul)
{
    if (val.error) return {true, 0};
    if (calcul.length() == 0){
        if (isNegative and full_calcul[cursor - 1] == '-') return {true, 0};
        return val;
    }
    if (isNegative and calcul[0] == '-') return {true, 0};
    if (calcul[0] == '-') return Numbering(calcul.erase(0, 1), val, false, true, 0, cursor + 1, full_calcul);
    if (calcul.length() > 1 and calcul[0] == '-' and calcul[1] == ' ') Numbering(calcul.erase(0, 2), val, false, true, 0, cursor + 2, full_calcul);

    if (isComa){
        if (calcul[0] == '.') return {true, 0};
        for (int test_idx = 0; test_idx < Numbers.length(); test_idx++){
            if (calcul[0] == Numbers[test_idx]){
                if (isNegative) {
                    val.value -= (calcul[0] - 48 /*ASCII char '0'*/) * std::pow(10, precision);
                    return Numbering(calcul.erase(0, 1), val, isComa, isNegative, --precision, cursor + 1, full_calcul);
                }
                val.value += (calcul[0] - 48 /*ASCII char '0'*/) * std::pow(10, precision);
                return Numbering(calcul.erase(0, 1), val, isComa, isNegative, --precision, cursor + 1, full_calcul);
            }
        }
        return {true, 0};
    }
    else {
        if (calcul[0] == '.') return Numbering(calcul.erase(0, 1), val, true, isNegative, -1, cursor + 1, full_calcul);
        for (int test_idx = 0; test_idx < Numbers.length(); test_idx++){
            if (calcul[0] == Numbers[test_idx]){
                if (isNegative) {
                    val.value = val.value * 10 - (calcul[0] - 48 /*ASCII char '0'*/);
                    return Numbering(calcul.erase(0, 1), val, false, isNegative, 0, cursor + 1, full_calcul);
                }
                val.value = val.value * 10 + (calcul[0] - 48 /*ASCII char '0'*/);
                return Numbering(calcul.erase(0, 1), val, false, isNegative, 0, cursor + 1, full_calcul);
            }
        }
        return {true, 0};
    }
}

double_error Result::Forward(std::string calcul, int cursor, std::string full_calcul)
{
    if (calcul.length() == 0) return {true, 0};

    int parenthesis_opens_at{ -1 };
    int parenthesis_closes_at{};

    int pos_strong_operator = -1;
    char current_strong_operator = 0;

    for (int idx = 0; idx < calcul.length(); idx++){
        switch (calcul[idx]){
            case 's': // sqrt(
            {
                if (calcul.length() > 4 and calcul[idx+1] == 'q' and calcul[idx+2] == 'r' and calcul[idx+3] == 't' and calcul[idx+4] == '(') {
                    parenthesis_opens_at = idx + 4;
                    parenthesis_closes_at = (parenthesis_opens_at + 1) + BracketScan(calcul.substr(parenthesis_opens_at + 1, calcul.length() - 1 - parenthesis_opens_at));
                    if (parenthesis_closes_at == -1) return {true, 0};
                    if (parenthesis_opens_at == 4 and parenthesis_closes_at == (calcul.length() - 1)){
                        SquareRootOperator squareRootOperator(Forward(calcul.substr(parenthesis_opens_at + 1, parenthesis_closes_at - 1 - parenthesis_opens_at), parenthesis_opens_at + 1, full_calcul));
                        return squareRootOperator.execute();
                    }

                    break;
                }
                return {true, 0};
            }
            case '(':
            {
                // TO FIX
                parenthesis_opens_at = idx;
                parenthesis_closes_at = (parenthesis_opens_at + 1) + BracketScan(calcul.substr(parenthesis_opens_at + 1, calcul.length() - 1 - parenthesis_opens_at));
                if (parenthesis_closes_at == -1) return {true, 0};
                if (parenthesis_opens_at == 0 and parenthesis_closes_at == calcul.length() - 1) return Forward(calcul.substr(parenthesis_opens_at + 1, calcul.length() - 2), parenthesis_opens_at + 1, full_calcul);
                idx = parenthesis_closes_at;
                break;
            }
            case '+':{
                pos_strong_operator = OperatorScan(current_strong_operator, pos_strong_operator, calcul[idx], idx);
                if (pos_strong_operator == idx) current_strong_operator = calcul[idx];
                break;
            }
            case '-':{
                if (idx == 0 or (calcul[idx - 1] == '.')) break;
                bool test = false;
                for (int test_idx = 0; test_idx < Numbers.length(); test_idx++){
                    if (full_calcul[cursor + idx - 1] == Numbers[test_idx]) test = true;
                    break;
                }
                if (test) break;
                pos_strong_operator = OperatorScan(current_strong_operator, pos_strong_operator, calcul[idx], idx);
                if (pos_strong_operator == idx) current_strong_operator = calcul[idx];
                break;
            }
            case '^':{
                pos_strong_operator = OperatorScan(current_strong_operator, pos_strong_operator, calcul[idx], idx);
                if (pos_strong_operator == idx) current_strong_operator = calcul[idx];
                break;
            }
            case '*':{
                pos_strong_operator = OperatorScan(current_strong_operator, pos_strong_operator, calcul[idx], idx);
                if (pos_strong_operator == idx) current_strong_operator = calcul[idx];
                break;
            }
            case '/':{
                pos_strong_operator = OperatorScan(current_strong_operator, pos_strong_operator, calcul[idx], idx);
                if (pos_strong_operator == idx) current_strong_operator = calcul[idx];
                break;
            }
        }
    }

    if (pos_strong_operator != -1){
        switch (current_strong_operator){
            case '+':{
                PlusOperator plusOperator(Forward(calcul.substr(0, pos_strong_operator), 0, full_calcul), Forward(calcul.substr(pos_strong_operator + 1), pos_strong_operator + 1, full_calcul));
                return plusOperator.execute();
            }
            case '-':{
                MinusOperator minusOperator(Forward(calcul.substr(0, pos_strong_operator), 0, full_calcul), Forward(calcul.substr(pos_strong_operator + 1), pos_strong_operator + 1, full_calcul));
                return minusOperator.execute();
            }
            case '^':{
                PowerOperator powerOperator(Forward(calcul.substr(0, pos_strong_operator), 0, full_calcul), Forward(calcul.substr(pos_strong_operator + 1), pos_strong_operator + 1, full_calcul));
                return powerOperator.execute();
            }
            case '*':{
                MultiplyOperator multiplyOperator(Forward(calcul.substr(0, pos_strong_operator), 0, full_calcul), Forward(calcul.substr(pos_strong_operator + 1), pos_strong_operator + 1, full_calcul));
                return multiplyOperator.execute();
            }
            case '/':{
                DivideOperator divideOperator(Forward(calcul.substr(0, pos_strong_operator), 0, full_calcul), Forward(calcul.substr(pos_strong_operator + 1), pos_strong_operator + 1, full_calcul));
                return divideOperator.execute();
            }
        }
    }

    return Numbering(calcul, {false, 0}, false, false, 0, cursor, full_calcul);
}

double_error Result::ForwardReversePolish(const std::string &calcul){
    std::istringstream iss(calcul);
    std::vector<double> constants;
    std::string arg;
    while (iss >> arg) {
        double argNum;
        if (std::istringstream(arg) >> argNum) {
            constants.push_back(argNum);
        }
        else if (arg == "sqrt"){
            if (constants.size() == 0) return {true, 0};
            double operand = constants.back();
            constants.pop_back();
            double_error result = {false, 0};
            SquareRootOperator squareRootOperator({false, operand});
            result = squareRootOperator.execute();
            if (result.error) return {true, 0};
            constants.push_back(result.value);
        }
        else {
            if (constants.size() == 0) return {true, 0};
            double secondOperand = constants.back();
            constants.pop_back();
            if (constants.size() == 0) return {true, 0};
            double firstOperand = constants.back();
            constants.pop_back();
            double_error result = {false, 0};
            if (arg == "*"){
                MultiplyOperator multiplyOperator({false, firstOperand}, {false, secondOperand});
                result = multiplyOperator.execute();
                if (result.error) return {true, 0};
                constants.push_back(result.value);
            }
            else if (arg == "/"){
                DivideOperator divideOperator({false, firstOperand}, {false, secondOperand});
                result = divideOperator.execute();
                if (result.error) return {true, 0};
                constants.push_back(result.value);
            }
            else if (arg == "-"){
                MinusOperator minusOperator({false, firstOperand}, {false, secondOperand});
                result = minusOperator.execute();
                if (result.error) return {true, 0};
                constants.push_back(result.value);
            }
            else if (arg == "+"){
                PlusOperator plusOperator({false, firstOperand}, {false, secondOperand});
                result = plusOperator.execute();
                if (result.error) return {true, 0};
                constants.push_back(result.value);
            }
            else if (arg == "^"){
                PowerOperator powerOperator({false, firstOperand}, {false, secondOperand});
                result = powerOperator.execute();
                if (result.error) return {true, 0};
                constants.push_back(result.value);
            }
            else { //just in case
                return {true, 0};
            }
        }
    }
    return {false, constants.back()};
}





