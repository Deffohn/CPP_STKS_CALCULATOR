#include "result.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <cmath>

#include <iostream>
#include <string>

std::string Numbers("0123456789");

std::string CleanCalcul(std::string calcul)
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

// Forward

int BracketScan(std::string calcul)
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
                break;
        }
    }
    if (parenthesis_opens_amount == parenthesis_closes_amount) return parenthesis_closes_at;
    return -1;
}


double_error Forward(std::string calcul)
{
    int parenthesis_opens_at = -1;
    int parenthesis_closes_at = calcul.length();
    for (int idx = 0; idx < calcul.length(); idx++){
        switch (calcul[idx]){
            case 's': // sqrt(
                if (calcul[idx+1] == 'q' and calcul[idx+2] == 'r' and calcul[idx+3] == 't' and calcul[idx+4] == '(')
                    parenthesis_opens_at = idx+4;
                    parenthesis_closes_at = BracketScan(calcul.substr(parenthesis_opens_at + 1, calcul.length()));
                    if (parenthesis_closes_at == -1) return {true, 0};

                break;
            case '(':
                parenthesis_opens_at = idx;
                parenthesis_closes_at = BracketScan(calcul.substr(parenthesis_opens_at + 1, calcul.length()));
                break;
//            case

        }
    }
}






