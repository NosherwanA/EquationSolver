#pragma once
#ifndef EquationSolver_Helper_H

#define EquationSolver_Helper_H

//Modifies the matrix for the Crammer's Rule
double** ModifyMatrix(double**, double*, int);

//Calculates the determinent of a 3x3 matrix
double CalculateDeterminent(double**);

#endif
