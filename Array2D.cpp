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

template<typename T>
Array2D<T>::~Array2D() {
	for(int i = 0; i < rowCount; i++) {
		delete[] array[i];
	}
	delete[] array;
	cout << "Deleted\n";
}

template <typename T>
Array2D<T>::Array2D(const Array2D<T>& other){ //other is old object;
	//We are doing the operation of - Array2D<T> new_obj(old_obj); So we are passing old_obj
	//and it is fetched by 'other'. new_obj is the one that is calling this function and it will be considered as 'this';
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
void Array2D<T>::m_getValues(){
	for(int rowLoop = 0; rowLoop< rowCount; rowLoop++){
		for(int colLoop=0; colLoop< colCount; colLoop++){
			cin >> array[rowLoop][colLoop];
			if(array[rowLoop][colLoop] > maxValue){
				cout << "You entered value higher than Maximum Value, that is 1000. Exiting. . .";
				exit(0);
			}
		}
	}
}

template <typename T>
void Array2D<T>::m_displayValues(){
	for(int rowLoop = 0; rowLoop< rowCount; rowLoop++){
		for(int colLoop=0; colLoop< colCount; colLoop++){
		 cout << array[rowLoop][colLoop] << " ";
		 }
		 cout << "\n";
	}
}

template <typename T>
void Array2D<T>::m_setStringValues(){
	char m_value = 'A';
	for(int rowLoop = 0; rowLoop< rowCount; rowLoop++){
		for(int colLoop=0; colLoop< colCount; colLoop++){
			array[rowLoop][colLoop] = m_value;
			m_value++;
		}
	}
}

template <typename T>
Array2D<T> Array2D<T>::operator+(const Array2D<T>& other){
	Array2D<T> temp(rowCount,colCount,1000);
	for(int rowLoop = 0; rowLoop < rowCount; rowLoop++)
		for(int colLoop = 0; colLoop < colCount; colLoop++)
			temp.array[rowLoop][colLoop] = (*this).array[rowLoop][colLoop] + other.array[rowLoop][colLoop];
	return temp;
}



template <typename T>
Array2D<T>& Array2D<T>::operator += (const int val) {
	for(int rowLoop=0; rowLoop<rowCount; rowLoop++) {
		for(int colLoop=0; colLoop<colCount; colLoop++) {
	      (*this).array[rowLoop][colLoop] += val;
	    }
	}
	return *this;
}

template <typename T>
Array2D<T>& Array2D<T>::operator ++ (int) {
	//Array2D<double> temp(rowCount,colCount);

	cout << "Inside post Increment\n";//Working as pre increment
	cout << "Values of matrix:\n";
	this->m_displayValues();
	*this += 1;
	return *(this);
}

template <typename T>
Array2D<T>& Array2D<T>::operator ++ () {
	//Array2D<double> temp(rowCount,colCount);

	cout << "Inside pre Increment\n";//Working as pre increment
	*this += 1;
	return *(this);
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

