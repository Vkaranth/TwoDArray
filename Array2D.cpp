/*
 * Array.cpp
 *
 *  Created on: Jul 30, 2018
 *      Author: karanv3
 */

#include "Array2D.h"
#include <iostream>
#include <stdint.h>
#include <typeinfo>
#include <stdlib.h>
using namespace std;

//int global = 2;
template <typename T>
Array2D<T>::Array2D(int rowcount, int colcount, const int max){

		this->rowCount = rowcount;
		this->colCount = colcount;
		this->maxValue = max;
		//Array creation
		allocate();

		cout << "Constructed" << endl;
	}

template <typename T>
void Array2D<T>::allocate(){
	array = new T*[rowCount];

	//Array initialization
	for(int i = 0; i < rowCount; ++i)
	  array[i] = new T[colCount];
}

template <typename T>
Array2D<T>::Array2D(const Array2D& other){ //other is old object
	cout << "Inside Copy constructor \n";

	rowCount = other.rowCount;
	colCount = other.colCount;

	allocate();
	for(int rowLoop=0; rowLoop < rowCount; rowLoop++){
		for(int colLoop = 0; colLoop < colCount; colLoop++){
			(*this).array[rowLoop][colLoop] = other.array[rowLoop][colLoop];
		}
	}
}

template <typename T>
void Array2D<T>::setDoubleValues(){
	double m_value = 1.1;
	for(int rowLoop = 0; rowLoop< rowCount; rowLoop++){
		for(int colLoop=0; colLoop< colCount; colLoop++){
			array[rowLoop][colLoop] = m_value;
				m_value++;
			}
		}
	}

template <typename T>
void Array2D<T>::getValues(){
	for(int rowLoop = 0; rowLoop< rowCount; rowLoop++){
		for(int colLoop=0; colLoop< colCount; colLoop++){
			do{
				cin >> array[rowLoop][colLoop];
				if(array[rowLoop][colLoop] > maxValue){
					cout << "You entered value higher than Maximum Value, that is 1000. Re enter lesser value than 1000\n";
				}
			}while(array[rowLoop][colLoop] > maxValue);

		}
	}
}

template <typename T>
void Array2D<T>::getStringValues(){
	for(int rowLoop = 0; rowLoop< rowCount; rowLoop++){
		for(int colLoop=0; colLoop< colCount; colLoop++){
			cin >> array[rowLoop][colLoop];
			}
		}
	}

template <typename T>
void Array2D<T>::displayValues(){
	for(int rowLoop = 0; rowLoop< rowCount; rowLoop++){
		for(int colLoop=0; colLoop< colCount; colLoop++){
		 cout << array[rowLoop][colLoop] << " ";
		 }
		 cout << "\n";
	}
}

template <typename T>
Array2D<T> Array2D<T>::operator+(const Array2D<T>& other){
	Array2D<T> temp(rowCount,colCount);
	for(int rowLoop = 0; rowLoop < rowCount; rowLoop++)
		for(int colLoop = 0; colLoop < colCount; colLoop++)
			temp.array[rowLoop][colLoop] = (*this).array[rowLoop][colLoop] + other.array[rowLoop][colLoop];
	return temp;
}

template <typename T>
Array2D<T>& Array2D<T>::operator ++ (int) {

	string val = typeid(T).name();
	bool isItAString = false;
	if (val.find("string") != std::string::npos) {
	    isItAString = true;
	}
	if(!isItAString){
		cout << "Inside post Increment\n";
		this->displayValues();
		*this += 1;
		return *(this);
	}
	else{

		cout << "Inside post Increment\n"<< endl;
		displayValues();

		for(int rowLoop = 0; rowLoop < rowCount; rowLoop++){
			for(int colLoop = 0; colLoop < colCount; colLoop++){
				temp[rowLoop][colLoop] = (*this).array[rowLoop][colLoop];
	 		}
		}

		for(int rowLoop = 0; rowLoop< rowCount; rowLoop++){
			for(int colLoop=0; colLoop< colCount; colLoop++){
				for(int k=0; temp[rowLoop][colLoop][k]!='\0'; k++)
				    temp[rowLoop][colLoop][k] = temp[rowLoop][colLoop][k] + 1;
			}
		}

	}
}

template <typename T>
void Array2D<T>::setIncrementedValue(){
		for(int rowLoop = 0; rowLoop< rowCount; rowLoop++){
			for(int colLoop=0; colLoop< colCount; colLoop++){
				array[rowLoop][colLoop] = temp[rowLoop][colLoop];
			}
		}
		cout << "Incremented values" << endl;
		displayValues();
}


template <typename T>
Array2D<T>& Array2D<T>::operator ++ () {
	cout << "Inside pre Increment\n";//Working as pre increment
	*this += 1;
	return *(this);
}

template <typename T>
Array2D<T>& Array2D<T>::operator += (const int val) {
	for(int rowLoop=0; rowLoop<rowCount; rowLoop++) {
		for(int colLoop=0; colLoop<colCount; colLoop++) {
	      (*this).array[rowLoop][colLoop] += 'A';
	    }
	}
	return *this;
}



template <typename T>
T Array2D<T>::operator () (int row, int col){
	return array[row][col];
}

template <typename T>
bool Array2D<T>::operator == (const Array2D<T>& other){
	for(int rowLoop=0; rowLoop<3; rowLoop++){
		for(int colLoop=0; colLoop<3; colLoop++){
			if((*this).array[rowLoop][colLoop] == other.array[rowLoop][colLoop]){
					return true;
			}
			else
				return false;
		}
	}
}

template <typename T>
bool Array2D<T>::operator != (const Array2D<T>& other){
	for(int rowLoop=0; rowLoop<3; rowLoop++){
		for(int colLoop=0; colLoop<3; colLoop++){
			if((*this).array[rowLoop][colLoop] != other.array[rowLoop][colLoop]){
					return false;
			}
			else
				return true;
		}
	}
}

template <typename T>
void Array2D<T>::setStringValues(){
	string m_value = "AB";
	for(int rowLoop = 0; rowLoop< rowCount; rowLoop++){
		for(int colLoop=0; colLoop< colCount; colLoop++){
			array[rowLoop][colLoop] = m_value;
			//m_value++;
		}
	}
}
