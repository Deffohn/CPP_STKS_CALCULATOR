#include "result.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <cmath>

std::string Numbers("0123456789");

typedef struct{
    bool error;
    float value;
}double_error;

std::string MallocForwardByOneChar(std::string calcul)
{
    char *forward_calcul = (char *) malloc(calcul.length() - 1);
    for (int idx = 0; idx < calcul.length() - 1; idx++){
        forward_calcul[idx] = calcul[idx + 1];
    }
    return (std::string) forward_calcul;
}

std::string CleanCalcul(std::string calcul)
{
    char* clean_calcul = (char*) malloc(calcul.length()) ; // calcul.length()

    int beacon_process = 0;
    bool html_balise_test = false;
    for (int idx = 0; idx < calcul.length(); idx++){
        if (calcul[idx] == '<'){
            html_balise_test = true;
        }
        else if (calcul[idx] == '>'){
            html_balise_test = false;
        }
        else if (!html_balise_test and calcul[idx] != ' '){
            (clean_calcul)[beacon_process] = calcul[idx];
            beacon_process++;
        }
    }
    char* cleaned_calcul;
    if (beacon_process != 0){
        cleaned_calcul = (char*) malloc(beacon_process);
    }
    for (int idx = 0; idx < beacon_process; idx++){
        cleaned_calcul[idx] = clean_calcul[idx];
    }

    free(clean_calcul);

    if (beacon_process != 0){
        return (std::string) cleaned_calcul;
    }
    else{
        return "";
    }

}

double_error BracketPriority(std::string calcul)
{
    if (calcul.length() == 0)
        return {true, 0};
    else {
        for (int idx = 0; idx < calcul.length(); idx++){

        }
        // TODO
    }
    return {true, 0};
}

double_error Numbering(std::string calcul, double val, bool isComa, double precision)
{
    if (isComa){
        if (calcul[0] == '.') return {true, 0}; // as error for now
        for (int test_idx = 0; test_idx < Numbers.length(); test_idx++){
            if (calcul[0] == Numbers[test_idx]){
                //48 /*ASCII char '0'*/ +
                val += (calcul[0] - 48 /*ASCII char '0'*/) / pow(10, precision);
                precision--;
            }
        }
        return {true, 0}; // as error for now
    }
    return {true, 0};
}

double_error Forward(std::string calcul)
{
    if (calcul.length() == 0){
        // TODO
    }
    else {
        std::string forward_calcul = MallocForwardByOneChar(calcul);
        switch(calcul[0]){
            case '(':
                return BracketPriority(forward_calcul);

            // ================================================

            case '0':
                return Numbering(forward_calcul, 0, false, 0);
            case '1':
                return Numbering(forward_calcul, 1, false, 0);
            case '2':
                return Numbering(forward_calcul, 2, false, 0);
            case '3':
                return Numbering(forward_calcul, 3, false, 0);
            case '4':
                return Numbering(forward_calcul, 4, false, 0);
            case '5':
                return Numbering(forward_calcul, 5, false, 0);
            case '6':
                return Numbering(forward_calcul, 6, false, 0);
            case '7':
                return Numbering(forward_calcul, 7, false, 0);
            case '8':
                return Numbering(forward_calcul, 8, false, 0);
            case '9':
                return Numbering(forward_calcul, 9, false, 0);

            case '.':
                return Numbering(forward_calcul, 0, true, -1);

        }
    }
    return {true, 0};
}

std::string ProcessCalcul(std::string raw_calcul)
{
    std::string calcul = CleanCalcul(raw_calcul);
}






