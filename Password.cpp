/**
* Project-Password-Username Implementation using Hash Map
* Testing
* Password.cpp
* Copyright (c) 2022, Myo Aung.
*/

#include <fstream>
#include <string>
#include <vector>
#include "SeparateChaining.h"
#include "LinearProbing.h"

using namespace std;

int main() {

	string pw, name, answer;
	HashMap<string, string>* LPHM = new HashMap<string, string>;
	Hash SCHM;
	cout << "------------------------------" << endl;
	cout << "READING FROM \"password.txt\" " << endl;
	cout << "------------------------------" << endl;

	fstream outputFile("password.txt", ios::in);
	string first, second;
	if (outputFile.is_open()) {
		while (!outputFile.eof()) {
		outputFile >> first >> second;
		cout << "["<< first << ", " << second << "]" << endl;
		
		SCHM.put(first, second);							// For separate chaining
		
		LPHM->insert(first, second);						// For linear probing
		}
	}
	else {
		cout << "ERROR! FILE NOT FOUND!!" << endl;
		return 0;
	}
	LPHM->print();											// TESTING LINEAR PROBING
	cout << "The size of the map: " << LPHM->sizeofMap() << endl;
	do {
	cout << "Username: ";
	cin >> name;
	cout << "Password: ";
	cin >> pw;
	LPHM->verify(name, pw);
	cout << "Would you like to continue? " << endl << "Answer(Yes / No): ";
	cin >> answer;
	cout << endl;
	} while (answer == "Yes" || answer == "yes" || answer == "y");
	cout << endl << "Erase: " << LPHM->erase("myo") << endl;

	SCHM.print();											// TESTING SEPARATE CHAINING
	cout << "The size of the map: " << SCHM.size() << endl;
	do{
	cout << "Enter User Name: ";
	cin >> name;
	cout << "Enter Password: ";
	cin >> pw;
	SCHM.verify(name, pw);
	cout << "Would you like to continue? " << endl << "Answer(Yes / No): ";
	cin >> answer;
	cout << endl;
	} while (answer == "Yes" || answer == "yes" || answer == "y");

	return 0;
}