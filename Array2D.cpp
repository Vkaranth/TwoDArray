/*
 * Array2D.cpp
 *
 *  Created on: Jul 25, 2018
 *      Author: karanv3
 */

#include "Array2D.h"
#include <iostream>
using namespace std;

template <typename T>
Array2D<T>::Array2D(int rowcount, int colcount){

		this->rowCount = rowcount;
		this->colCount = colcount;

		//Array creation
		array = new T*[rowCount];

		//Array initialization
		for(int i = 0; i < rowCount; ++i)
		 array[i] = new T[colCount];

		cout << "Constructed" << endl;
	}


	//Copy constructor
//	Array2D(const Array2D& other){
//		cout << "Created by copying\n";
//	}

template <typename T>
void Array2D<T>::m_setDoubleValues(){
	double m_value = 1.1;
	for(int i = 0; i< rowCount; i++){
		for(int j=0; j< colCount; j++){
			array[i][j] = m_value;
				m_value++;
			}
		}
	}


template <typename T>
void Array2D<T>::m_displayValues(){
	for(int i = 0; i< rowCount; i++){
		for(int j=0; j< colCount; j++){
		 cout << array[i][j] << " ";
		 }
		 cout << "\n";
	}
}

template <typename T>
void Array2D<T>::m_setStringValues(){
	char m_value = 'A';
	for(int i = 0; i< rowCount; i++){
		for(int j=0; j< colCount; j++){
			array[i][j] = m_value;
			m_value++;
		}
	}
}

template <typename T>
Array2D<T> Array2D<T>::operator+(const Array2D<T>& other){
	//declare a matrix temp of type T to store the result and return this matrix
Array2D<double> temp(rowCount,colCount);
for(int i = 0; i < rowCount; i++)
for(int j = 0; j < colCount; j++)
temp.array[i][j] = (*this).array[i][j] + other.array[i][j];
return temp;
}



template <typename T>
Array2D<T>& Array2D<T>::operator += (const int val) {
	for(unsigned i=0; i<rowCount; i++) {
		for(unsigned j=0; j<colCount; j++) {
	      (*this).array[i][j] += val;
	    }
	}
	return *this;
}


