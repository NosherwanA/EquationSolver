#include "EquationSolver_Helper_H.h";

double** ModifyMatrix(double** ToBeModified, double* ToBeModifiedWith, int Postion) {

	/**

	Modifies the matrix for the Crammer's Rule 

	@param 2D (3x3) double array with the to be modified matrix of LHS, double array with the RHS side of equation and int value representing which variable is to be used to modify

	@return double array with the modified matrix

	*/


	double **returnArray = new double*[3];
	for (int i = 0; i < 3; i++) {
		returnArray[i] = new double[3];
	}


	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			if (j == Postion) {

				returnArray[i][j] = ToBeModifiedWith[i];

			}
			else {

				returnArray[i][j] = ToBeModified[i][j];

			}
		}
	}

	return returnArray;

}

double CalculateDeterminent(double** a) {

	/**

	Calculates the determinent of a 3x3 matrix

	@param 2D (3x3) double array whose determinent is to be modified

	@return double representing the determinent of the matrix

	*/

	double answer = 0.00;

	/*
	A B C
	D E F
	G H I
	A(EI-HF)-B(DI-GF)+C(DH-GE)
	*/

	answer = a[0][0] * ((a[1][1] * a[2][2]) - (a[2][1] * a[1][2])) - a[0][1] * (a[1][0] * a[2][2] - a[2][0] * a[1][2]) + a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);

	return answer;
}