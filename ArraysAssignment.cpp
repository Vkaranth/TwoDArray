//============================================================================
// Name        : Assignment1.cpp
// Author      : Karanth
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Array2D.h"
#include "Array2D.cpp"
using namespace std;

int main() {

	Array2D<double> doubleArray;
	Array2D<string> stringArray;

	cout << "Enter number of rows that you want the array to be of\n";
	int rowCount;
	cin >> rowCount;

	cout << "Enter number of columns that you want the array to be of\n";
	int colCount;
	cin >> colCount;

	cout << "Enter your choice\n1.Create an array of type 'double'\n2.Create an array of type 'string'\n";
	int choice;
	cin >> choice;

	if(choice == 1){
		doubleArray(rowCount,colCount);
	}

	else if(choice == 2){
		stringArray(rowCount,colCount);
	}

	else{
		cout << "Incorrect choice\n";
		break;
	}

	cout << "Would you like to manually enter values to the array?(y/n)\n";
	string manualEntryChoice;
	cin >> manualEntryChoice;

	if(choice == 1 && (manualEntryChoice == 'y' || manualEntryChoice == 'yes')){

	}

	doubleArray.m_setDoubleValues();
	doubleArray.m_displayValues();

	Array2D<double> doubleArrayTwo = doubleArray;

	doubleArrayTwo.m_setDoubleValues();

	//cout << doubleArrayTwo.rowCount;
	doubleArrayTwo.m_displayValues();

	Array2D <double> sum = doubleArray + doubleArrayTwo;
	sum.m_displayValues();

	cout << "Enter the scalar value to add to the array\n";
	int scalarValue;
	doubleArray += scalarValue;

	cout << "After changes\n";
	doubleArray.m_displayValues();

	cout << "Enter the row you would like to fetch\n";
	int rowToFetch;

	cout << "Enter the column you would like to fetch\n";
	int colToFetch;
	cout << doubleArray[rowToFetch][colToFetch] << endl;

	stringArray.m_setStringValues();
	stringArray.m_displayValues();


	cout << doubleArray(rowToFetch,colToFetch) << endl;
	cout << stringArray(rowToFetch,colToFetch) << endl;

	if(doubleArray == doubleArrayTwo){
		cout << "Matrices are equal" << endl;
	}

	else{
		cout << "Matrices are unequal" << endl;
	}

	if(doubleArray != doubleArrayTwo){
		cout << "Matrices are equal" << endl;
	}

	else{
		cout << "Matrices are unequal" << endl;
	}
	return 0;
}



