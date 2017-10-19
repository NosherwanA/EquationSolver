#include "EquationParser_Helper_H.h";
#include <string>;
#include <algorithm>;

double getCoefficient(char c, string eq) {

	/**

	Extracts the coefficient of the variable from the LHS of a given equation

	@param char representing the variable and a string representing the LHS of an equation

	@return double representing the coefficient of the variable

	*/

	double returnValue = 0.00;


	int found = eq.find(c);

	if (found == string::npos)
	{

		// If VARIABLE not found then coeefiicent is zero

		returnValue = 0.00;
		return returnValue;

	}
	else
	{
		// IF VARIABLE IS FOUND

		int leneq1 = eq.length();

		string reversedStr = eq.substr(0, (found + 1));
		reverse(reversedStr.begin(), reversedStr.end());

		int first_pos_sign = reversedStr.find_first_of("+", 0);
		int first_neg_sign = reversedStr.find_first_of("-", 0);

		string coefficient;

		if ((first_pos_sign == string::npos) && (first_neg_sign == string::npos)) {

			int revstrlen = reversedStr.length();

			if (revstrlen == 1) {
				//iF COEFFICIENT IS 0
				returnValue = 1.00;
				return returnValue;
			}

			coefficient = reversedStr.substr(1, revstrlen);
			reverse(coefficient.begin(), coefficient.end());

			returnValue = stod(coefficient);
			return returnValue;

		}
		else if (first_pos_sign == string::npos) {

			if (first_neg_sign == 1) {
				//iF COEFFICIENT IS 0
				returnValue = -1.00;
				return returnValue;
			}

			coefficient = reversedStr.substr(1, (first_neg_sign - 1));
			reverse(coefficient.begin(), coefficient.end());

			returnValue = (stod(coefficient) * -1);
			return returnValue;

		}
		else if (first_neg_sign == string::npos) {

			if (first_pos_sign == 1) {
				//iF COEFFICIENT IS 0
				returnValue = 1.00;
				return returnValue;
			}

			coefficient = reversedStr.substr(1, (first_pos_sign - 1));
			reverse(coefficient.begin(), coefficient.end());

			returnValue = stod(coefficient);
			return returnValue;

		}
		else if (first_pos_sign < first_neg_sign) {

			if (first_pos_sign == 1) {
				//iF COEFFICIENT IS 0
				returnValue = 1.00;
				return returnValue;
			}

			coefficient = reversedStr.substr(1, (first_pos_sign - 1));
			reverse(coefficient.begin(), coefficient.end());

			returnValue = stod(coefficient);
			return returnValue;

		}
		else if (first_neg_sign < first_pos_sign) {

			if (first_neg_sign == 1) {
				//iF COEFFICIENT IS 0
				returnValue = -1.00;
				return returnValue;
			}

			coefficient = reversedStr.substr(1, (first_neg_sign - 1));
			reverse(coefficient.begin(), coefficient.end());

			returnValue = (stod(coefficient) * -1);
			return returnValue;
		}
	}
}