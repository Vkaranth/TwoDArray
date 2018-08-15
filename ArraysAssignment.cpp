//============================================================================
// Name        : TrySwitch.cpp
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

	cout << "Choose the type of 2D Array\n1.Double\n2.String\n";
	int typeOfArray;
	cin >> typeOfArray;

	if(typeOfArray == 1){

	Array2D<double> doubleArray(rowCount,colCount,1000);

	cout << "Would you like to manually enter values to the array?(y/n)\n";
	char manualEntryChoice;
	cin >> manualEntryChoice;

	if(manualEntryChoice == 'y' || manualEntryChoice == 'yes'){
		cout << "Enter array entries\n";
		doubleArray.m_getValues();
	}

	else{
		doubleArray.m_setDoubleValues();
	}

	doubleArray.m_displayValues();

	Array2D<double> doubleArrayTwo = doubleArray;
//	cout << "Enter the operation to be performed\n1.Matrix addition\n2.Pre-increment\n3.Post-increment\n4.Scalar addition\n5.Fetch element from matrix\n6.Matrix Comparison\n";
//	int choice;
//	cin >> choice;

	int rowToFetch;
	int colToFetch;
	int continueValue = 1;

  do{
	  cout << "Enter the operation to be performed\n1.Matrix addition\n2.Pre-increment\n3.Post-increment\n4.Scalar addition\n5.Fetch element from matrix\n6.Matrix Comparison\n";
	  int choice;
	  cin >> choice;
	switch(choice){

	case 1:
		cout << "Case 1" << endl;
		cout << "The first matrix is:\n";
				doubleArray.m_displayValues();
				cout << "Would you like to manually enter values for another numeric matrix to add with the present matrix?(y/n)?\n";
				char enterAnotherMatrix;
				cin >> enterAnotherMatrix;

				if(enterAnotherMatrix == 'yes' || enterAnotherMatrix == 'y'){
					Array2D<double> doubleArrayThree(rowCount, colCount);
					cout << "Enter array entries\n";
					doubleArrayThree.m_getValues();
					doubleArrayThree.m_displayValues();
					cout << "The sum of the two matrices are " << endl;
					Array2D<double> sum = doubleArray + doubleArrayThree;
					sum.m_displayValues();
				}
				else{

					doubleArrayTwo.m_setDoubleValues();
					//cout << doubleArrayTwo.rowCount;
					cout << "Another array considered is " << endl;
					doubleArrayTwo.m_displayValues();

					cout << "The sum of the two matrices are " << endl;
					Array2D<double> sum = doubleArray + doubleArrayTwo;
					cout << "\nReached here, after adding\n";
					sum.m_displayValues();
					cout << endl;
				 }
		break;

	case 2:
		cout << "Case 2  " << endl;
		cout << "Matrix, after pre increment operation:\n";
		++doubleArray;
		doubleArray.m_displayValues();
		break;

	case 3:
		cout << "Case 2  " << endl;
		cout << "Matrix, after post increment operation:\n";
		doubleArray++;
		//doubleArray.m_displayValues();
		break;

	case 4:
		cout << "Enter the scalar value to add to the matrix\n";
		int scalarValue;
		cin>> scalarValue;
		doubleArray += scalarValue;

		cout << "After adding " << scalarValue << " to the matrix, the resulting matrix is \n";
		doubleArray.m_displayValues();
		break;

	case 5:
		cout << "Enter the row you would like to fetch from the below matrix\n";
		doubleArray.m_displayValues();
		do{
			cin >> rowToFetch;
			if(rowToFetch >= rowCount){
			cout << "Invalid input. The number of rows are " << rowCount << endl;
			}
		}while(rowToFetch >= rowCount);

		cout << "Enter the column you would like to fetch\n";
		do{
			cin >> colToFetch;
			if(colToFetch >= colCount){
			cout << "Invalid input. The number of columns are " << colCount << endl;
		    }
		}while(colToFetch >= colCount);

		cout << "The element at row "<< rowToFetch << " and column " <<colToFetch << " using subscript operator overloading is " << doubleArray[rowToFetch][colToFetch] << "\n";
		cout << "The element at row "<< rowToFetch << " and column " <<colToFetch << " using functor operator is " << doubleArray(rowToFetch,colToFetch) << endl;

		break;

	case 6:
		cout << "Matrix available for comparison is :\n";
		doubleArray.m_displayValues();
		cout << "Would you like to manually enter values for another numeric matrix to compare with the present matrix?(y/n)?";
				//enterAnotherMatrix;
		cin >> enterAnotherMatrix;

		if(enterAnotherMatrix == 'yes' || enterAnotherMatrix == 'y'){
			Array2D<double> doubleArrayThree = doubleArray;
			cout << "Enter " << rowCount * colCount << " number of type double values\n";
			doubleArrayThree.m_getValues();

			if(doubleArray == doubleArrayThree){
				cout << "Matrices are equal" << endl;
		    }

			else{
				cout << "Matrices are unequal" << endl;
			    }
		}

		else{
			doubleArrayTwo.m_setDoubleValues();
			if(doubleArray != doubleArrayTwo){
				cout << "Matrices are equal" << endl;
			}
			else{
				cout << "Matrices are not equal" << endl;
				}
			}

		break;
	default:
		cout  << "Invalid choice\n";
		break;
	}

	cout << "Do you wish to continue?(y/n)\n";
	char cont;
	cin >> cont;

	if(cont == 'y' || cont == 'yes')
		continueValue = 1;
	else{
		cout << "Exiting. . . .\n";
		continueValue = 0;
	}
 }while(continueValue);

  return 0;
} //End of if typeOfArray = 1

	else if(typeOfArray == 2){
		Array2D<string> stringArray(rowCount,colCount,1000);
		stringArray.m_setStringValues();

		cout << "String 2D array:\n";
		stringArray.m_displayValues();

		Array2D<string> stringArrayTwo = stringArray;

		cout << "String concatenation demonstration\n";
		cout << "After concatenating the above matrix with itself, we get\n";
		Array2D<string> stringSum = stringArray + stringArrayTwo;
		stringSum.m_displayValues();

//		cout << "Incrementing. . .\n";
//		++stringSum;
		stringSum.m_displayValues();
		cout << "Matrix available for comparison is :\n";
		stringArray.m_displayValues();

		cout << "Postfix operation demonstration\n";
		stringArray++;
		cout << "-----------------------------------------------------------" << endl;
		stringArray.m_setIncrementedValue();
//		cout << "--------------------------------------------------------------" << endl;
//		stringArray.m_displayValues();

		cout << "Would you like to manually enter values for another string matrix to compare with the present matrix?(y/n)?\n";
		char enterAnotherMatrix;
		cin >> enterAnotherMatrix;

		if(enterAnotherMatrix == 'yes' || enterAnotherMatrix == 'y'){
			Array2D<string> stringArrayTwo = stringArray;
			cout << "Enter " << rowCount * colCount << " number of type string values\n";
			stringArrayTwo.m_getStringValues();
			cout << "You entered\n";
			stringArrayTwo.m_displayValues();

			cout << "String concatenation demonstration\n";
			Array2D<string> stringSum = stringArray + stringArrayTwo;
			stringSum.m_displayValues();

		    if(stringArray == stringArrayTwo){
			 cout << "Equal matrices\n";
		    }
		    else{
		    	cout << "Unequal matrices\n";
		    }

		}
		else{
			Array2D<string> stringArrayTwo = stringArray;
			stringArrayTwo.m_setStringValues();
			cout << "First matrix\n";
			stringArrayTwo.m_displayValues();
			cout << "Second matrix\n";
			stringArray.m_displayValues();
			if(stringArray == stringArrayTwo){
				cout << "Equal matrices\n";
		    }
			else{
			cout << "Unequal matrices\n";
			}
		}
		return 0;
	}

	else{
		cout << "Invalid choice\n";
		cout << "Exiting. . . .\n";
		exit(0);
	}
}
