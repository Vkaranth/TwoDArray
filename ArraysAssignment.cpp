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

	cout << "Enter number of rows that you want the array to be of\n";
	int rowCount;
	cin >> rowCount;

	cout << "Enter number of columns that you want the array to be of\n";
	int colCount;
	cin >> colCount;


	Array2D<double> doubleArray(rowCount,colCount,1000);
	Array2D<string> stringArray(rowCount,colCount,1000);


	cout << "Would you like to manually enter values to the array?(y/n)\n";
	char manualEntryChoice;
	cin >> manualEntryChoice;
//
	if(manualEntryChoice == 'y' || manualEntryChoice == 'yes'){
		cout << "Enter array entries\n";

		doubleArray.m_getValues();
	}

	else{
		doubleArray.m_setDoubleValues();
	}

	doubleArray.m_displayValues();

	Array2D<double> doubleArrayTwo = doubleArray;

	doubleArrayTwo.m_setDoubleValues();

	//cout << doubleArrayTwo.rowCount;
	cout << "Another array considered is " << endl;
	doubleArrayTwo.m_displayValues();

	cout << "The sum of the two matrices are " << endl;
	Array2D <double> sum = doubleArray + doubleArrayTwo;
	sum.m_displayValues();

	cout << "Enter the scalar value to add to the matrix\n";
	int scalarValue;
	cin>> scalarValue;
	doubleArray += scalarValue;

	cout << "After adding " << scalarValue << " to the matrix, the resulting matrix is \n";
	doubleArray.m_displayValues();

	cout << "After Post Increment:" << endl;
	doubleArray++;
	//doubleArray.m_displayValues();
	doubleArray.m_displayValues();

	cout << "Enter the row you would like to fetch\n";
	int rowToFetch;
	do{
		cin >> rowToFetch;
		if(rowToFetch >= rowCount){
		cout << "Invalid input. The number of rows are " << rowCount << endl;
		}
	}while(rowToFetch >= rowCount);

	cout << "Enter the column you would like to fetch\n";
	int colToFetch;

	do{
		cin >> colToFetch;
		if(colToFetch >= colCount){
			cout << "Invalid input. The number of columns are " << colCount << endl;
	    }
	}while(colToFetch >= colCount);

	cout << "The element at row "<< rowToFetch << " and column " <<colToFetch << " using subscript operator overloading is " <<doubleArray[rowToFetch][colToFetch] << endl;
	cout << "The element at row "<< rowToFetch << " and column " <<colToFetch << " using functor operator is " << doubleArray(rowToFetch,colToFetch) << endl;

	stringArray.m_setStringValues();

	cout << "String 2D array:\n";
	stringArray.m_displayValues();


	cout << "The element at row "<< rowToFetch << " and column " <<colToFetch << " of String matrix, using functor operator overloading is " << stringArray[rowToFetch][colToFetch] << endl;
	//cout << stringArray(rowToFetch,colToFetch) << endl;

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



