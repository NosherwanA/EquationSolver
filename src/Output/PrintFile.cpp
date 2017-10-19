using namespace std;


#include "PrintFile_H.h";
#include <string>;
#include <iostream>;
#include <fstream>;

void printFile(double* vals, char* vars) {

	/**

	Prints the results to a output file

	@param double array with the values of the variables and char array with the variables themselves

	*/

	ofstream f;

	f.open("output.txt");

	f << "Results" << endl;

	for (int i = 1; i < 4; i++) {

		f << "Variable " << vars[(i-1)] << " : " << vals[i] << endl;

	}

	f.close();

	return;
}