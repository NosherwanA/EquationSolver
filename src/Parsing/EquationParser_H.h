#pragma once
#pragma once
#ifndef EquationParser_H

#define EquationParser_H

#include <string>
using std::string;
#include <algorithm>;
using std::sort;
using std::find;

//Extracts the variables from system of the equations and returns a char array containing the variables
char* getVariables(string, string, string);

//Takes the RHS of the system of equations and coverts them to a double array
double *RHS(string, string, string);

//Takes the LHS of the system of equations and extractes the coefficients for each variable to be reurned as a pointer to a double array
double **LHS(string, string, string, char*);

//Takes a complete equation and returns pointer to a string array contianing the LHS and RHS of the equation
string* EqSplitter(string);

#endif
