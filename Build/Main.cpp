using namespace std;
#include <iostream>;
#include <string>;
#include <algorithm>;
#include <fstream>;

#include "PrintFile_H.h";
#include "ReadFile_H.h";
#include "EquationParser_H.h";
#include "EquationSolver_H.h";

int main() {

	// All variables needed throughout the program
	string* Equations;
	double **LHSMatrix;
	double *RHSMatrix;
	char *Variables;

	// Reading the equations from a text file
	Equations = readFile();

	if (Equations == nullptr) {
		return -1;
	}

	//Splitting the equations into Left hand side and right hand side
	string eq1RHS, eq2RHS, eq3RHS;
	string eq1LHS, eq2LHS, eq3LHS;

	string* temp;

	temp = EqSplitter(Equations[0]);
	eq1LHS = temp[0];
	eq1RHS = temp[1];

	delete[] temp;

	temp = EqSplitter(Equations[1]);
	eq2LHS = temp[0];
	eq2RHS = temp[1];

	delete[] temp;

	temp = EqSplitter(Equations[2]);
	eq3LHS = temp[0];
	eq3RHS = temp[1];

	delete[] temp;
	delete[] Equations;

	temp = nullptr;

	//Getting the RHS side of the equations into the matrix
	RHSMatrix = RHS(eq1RHS, eq2RHS, eq3RHS);

	//Getting the array of the variables used in the system of equations and sorting them alphabatically
	Variables = getVariables(eq1LHS, eq2LHS, eq3LHS);

	//Getting the LHS side into a matrix
	LHSMatrix = LHS(eq1LHS, eq2LHS, eq3LHS, Variables);

	//Solving the system of equations using Crammer's Rule
	double* values; //correspond to the values of the variables in the same order as the char array "Variables"
	values = SolveEquations(LHSMatrix, RHSMatrix, Variables);
	
	//Printing the results to a txt file "output.txt"
	printFile(values, Variables);
	
	//Releasing memory
	delete[] values;
	delete[] Variables;
	delete[] RHSMatrix;

	for (int i = 0; i < 3; i++) {
		delete[] LHSMatrix[i];
	}
	delete[] LHSMatrix;

	return 0;
}
