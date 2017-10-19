#pragma once
#ifndef EquationSolver_H

#define EquationSolver_H

// Solves the system of equations with three variables using Crammer's Rule
double* SolveEquations(double** LHS, double* RHS, char*vars);

#endif
