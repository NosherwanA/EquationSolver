#pragma once
#ifndef EquationParser_Helper_H

#define EquationParser_Helper_H

#include <string>
using std::string;
#include <algorithm>;

//Extracts the coefficient of the variable from the LHS of a given equation
double getCoefficient(char, string);

#endif
