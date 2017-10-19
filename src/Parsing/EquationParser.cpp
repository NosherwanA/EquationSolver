#include "EquationParser_H.h";
#include "EquationParser_Helper_H.h";
#include <string>;
#include <algorithm>;

char* getVariables(string str1, string str2, string str3) {

	/**

	Extracts the variables from system of the equations and returns a char array containing the variables

	@param 3 Strings containg the system ofe quations 

	@return Char Array containing 3 variables

	*/

	string line = str1 + str2 + str3;
	char* variables = new char[3];
	int j = 0;

	for (int i = 0; i < line.size(); ++i)
	{
		if (!((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')))
		{
			line[i] = '\0';
		}
		else if (!(find(variables, (variables + 3), line[i]) != (variables + 3)))
		{
			variables[j] = line[i];
			j++;
		}
	}

	sort(variables, (variables + 3));

	return variables;
}

double *RHS(string eq1, string eq2, string eq3) {

	/**

	Takes the RHS of the system of equations and coverts them to a double array

	@param 3 Strings for the RHS of 3 equations

	@return Pointer to a double array 

	*/

	double* returnArray = new double[3];

	returnArray[0] = stod(eq1);
	returnArray[1] = stod(eq2);
	returnArray[2] = stod(eq3);

	return returnArray;
}

double **LHS(string eq1, string eq2, string eq3, char* vars) {

	/**

	Takes the LHS of the system of equations and extractes the coefficients for each variable to be reurned as a pointer to a double array

	@param 3 String variables representing RHS of three equats and char array containing all the variables used in the system of questions

	@return String Array containing 3 equations

	*/

	double **CoEfficients = new double*[3];
	for (int i = 0; i < 3; i++) {
		CoEfficients[i] = new double[3];
	}

	char c;
	int i = 0, j = 0;


	for (int x = 0; x < 3; x++)
	{
		c = vars[x];

		CoEfficients[i][j] = getCoefficient(c, eq1);
		i++;

		CoEfficients[i][j] = getCoefficient(c, eq2);
		i++;

		CoEfficients[i][j] = getCoefficient(c, eq3);
		i++;

		j++;
		i = 0;

	}

	return CoEfficients;

}

string* EqSplitter(string str) {

	/**

	Takes a complete equation and returns pointer to a string array contianing the LHS and RHS of the equation

	@param String containing a single equation

	@return String array contianing the LHS and RHS of the equation

	*/

	string* returnArray = new string[2];

	string LHS;
	string RHS;

	int split = str.find("=");
	int strlen = str.length();

	LHS = str.substr(0, split);
	RHS = str.substr((split + 1), strlen);

	returnArray[0] = LHS;
	returnArray[1] = RHS;

	return returnArray;
}