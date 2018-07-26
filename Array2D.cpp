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

//template<typename T>
//Array2D<T>::~Array2D() {
//	for(int i = 0; i < rowCount; ++i) {
//		delete [] array[i];
//		}
//		delete [] array;
//		cout << "Deleted\n";
//}

template <typename T>
void Array2D<T>::m_setDoubleValues(){
	double m_value = 1.1;
	for(int rowLoop = 0; rowLoop< rowCount; rowLoop++){
		for(int colLoop=0; colLoop< colCount; colLoop++){
			array[rowLoop][colLoop] = m_value;
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
	for(unsigned int i=0; i<rowCount; i++) {
		for(unsigned int j=0; j<colCount; j++) {
	      (*this).array[i][j] += val;
	    }
	}
	return *this;
}

template <typename T>
T Array2D<T>::operator () (int row, int col){
	return array[row][col];
}

template <typename T>
int Array2D<T>::getRows(){
	return this->rowCount;
}

template <typename T>
int Array2D<T>::getCols(){
	return this->colCount;
}

template <typename T>
bool Array2D<T>::operator == (const Array2D<T>& other){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if((*this).array[i][j] == other.array[i][j]){
					return true;
				}
				else
					return false;
		}
	}
}

template <typename T>
bool Array2D<T>::operator != (const Array2D<T>& other){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if((*this).array[i][j] != other.array[i][j]){
					return false;
				}
				else
					return true;
		}
	}
}
//template <typename T>
//T Array2D<T>::operator ++ (const Array2D<T>& other){
//	if()
//
//}
