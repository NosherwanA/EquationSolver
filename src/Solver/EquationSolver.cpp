#include "EquationSolver_H.h";
#include "EquationSolver_Helper_H.h";

double* SolveEquations(double** LHS, double* RHS, char*vars) {

	/**

	Solves the system of equations with three variables using Crammer's Rule

	@param 2D (3x3) double array with the LHS side of equations, double array with the RHS side of equation and char variable with the variables used in the equations

	@return double arrray with the values of each of the the variables

	*/

	double* returnArray = new double[4]; // 0th element for the original determinent

	double det, detA, detB, detC;


	det = CalculateDeterminent(LHS);

	double** temp;

	temp = ModifyMatrix(LHS, RHS, 0);
	detA = CalculateDeterminent(temp);
	for (int i = 0; i < 3; i++) {
		delete[] temp[i];
	}
	delete[] temp;


	temp = ModifyMatrix(LHS, RHS, 1);
	detB = CalculateDeterminent(temp);
	for (int i = 0; i < 3; i++) {
		delete[] temp[i];
	}
	delete[] temp;


	temp = ModifyMatrix(LHS, RHS, 2);
	detC = CalculateDeterminent(temp);
	for (int i = 0; i < 3; i++) {
		delete[] temp[i];
	}
	delete[] temp;

	returnArray[0] = det;
	returnArray[1] = (detA / det);
	returnArray[2] = (detB / det);
	returnArray[3] = (detC / det);

	return returnArray;
}