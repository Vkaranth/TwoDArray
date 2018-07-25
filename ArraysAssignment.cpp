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

//template<typename T>
//class Array2D{
//
//private:
//	T ** array;
//	int rowCount;
//	int colCount;
//
//public:
//
//	Array2D(int rowcount, int colcount){
//
//		this->rowCount = rowcount;
//		this->colCount = colcount;
//
//		//Array creation
//		array = new T*[rowCount];
//
//		//Array initialization
//		for(int i = 0; i < rowCount; ++i)
//		 array[i] = new T[colCount];
//
//		cout << "Constructed" << endl;
//	}
//
//
//	//Copy constructor
////	Array2D(const Array2D& other){
////		cout << "Created by copying\n";
////	}
//
//
//	void m_setDoubleValues(){
//		double m_value = 1.1;
//		for(int i = 0; i< rowCount; i++){
//			for(int j=0; j< colCount; j++){
//				array[i][j] = m_value;
//				m_value++;
//			}
//		}
//	}
//
//
//	void m_displayValues(){
//		for(int i = 0; i< rowCount; i++){
//			for(int j=0; j< colCount; j++){
//			 cout << array[i][j] << " ";
//			 }
//			cout << "\n";
//		}
//	}
//
//	void m_setStringValues(){
//	  char m_value = 'A';
//		for(int i = 0; i< rowCount; i++){
//			for(int j=0; j< colCount; j++){
//				array[i][j] = m_value;
//					m_value++;
//				}
//			}
//		}
//
//
//
//	Array2D<T> operator+(const Array2D<T>& other){
//	//declare a matrix temp of type T to store the result and return this matrix
//	Array2D<double> temp(rowCount,colCount);
//	for(int i = 0; i < rowCount; i++)
//	for(int j = 0; j < colCount; j++)
//	temp.array[i][j] = (*this).array[i][j] + other.array[i][j];
//	return temp;
//	}
//
////	Array2D<T> operator+=(const Array2D<T>& other){
////		//declare a matrix temp of type T to store the result and return this matrix
////		Array2D<double> temp(rowCount,colCount);
////		for(int i = 0; i < rowCount; i++)
////		for(int j = 0; j < colCount; j++)
////		temp.array[i][j] = (*this).array[i][j] + other.array[i][j];
////		return temp;
////		}
//	Array2D<T>& operator += (const int val) {
//
//	  for(unsigned i=0; i<rowCount; i++) {
//	    for(unsigned j=0; j<colCount; j++) {
//	      (*this).array[i][j] += val;
//	    }
//	  }
//
//	  return *this;
//	}
//
//template<typename U>
// class Proxy {
//    public:
//        Proxy(T* _array) : _array(_array) { }
//
//	        T operator[](int index) {
//	            return _array[index];
//	        }
//	    private:
//	        T* _array;
//	    };
//
//	Proxy <double> operator[](int index) {
//	        return Proxy<double>(array[index]);
//	    }
//
////	~Array2D(){
////		for(int i = 0; i < rowCount; ++i) {
////		    delete [] array[i];
////		}
////		delete [] array;
////		cout << "Deleted\n";
////	}
//};


int main() {


	Array2D<double> doubleArray(3,3);
	Array2D<string> stringArray(3,3);

	doubleArray.m_setDoubleValues();
	doubleArray.m_displayValues();

	Array2D<double> doubleArrayTwo = doubleArray;

	doubleArrayTwo.m_setDoubleValues();

	//cout << doubleArrayTwo.rowCount;
	doubleArrayTwo.m_displayValues();

	Array2D <double> sum = doubleArray + doubleArrayTwo;
	sum.m_displayValues();

	doubleArray += 10;

	cout << "After changes\n";
	doubleArray.m_displayValues();

	//cout << doubleArray[2][3];

	stringArray.m_setStringValues();
	stringArray.m_displayValues();


	return 0;
}



