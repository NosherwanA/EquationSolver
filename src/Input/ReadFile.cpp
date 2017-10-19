using namespace std;

#include "ReadFile_H.h";

#include <string>;
#include <iostream>;
#include <fstream>;

string* readFile() {

	/**

	Reads the equations from the file "input.txt" and returns a string array containing 3 equations

	@return String Array containing 3 equations

	*/

	string* returnArray = new string[3];

	ifstream fin;

	fin.open("input.txt");

	if (!(fin.is_open())) {

		//File not found
		cerr << "Error: File not found!" << endl;
		return nullptr;
	}
	else{

		cout << "File opened successfully" << endl;

		for (int i = 0; i < 3; i++) {
			fin >> returnArray[i];
		}

		return returnArray;

	}

}