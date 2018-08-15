/*
 * Array.h
 *
 *  Created on: Jul 30, 2018
 *      Author: karanv3
 */

#ifndef ARRAY_H_
#define ARRAY_H_
#include <iostream>
using namespace std;

template<typename T>
class Array2D {
private:
	T ** array;
	string temp[10][10];
	int rowCount;
	int colCount;
	int maxValue;

public:

	Array2D(int rowcount, int colcount, const int max = 1000);
	Array2D<T>(const Array2D<T>& other);
	void allocate();
	void m_setIncrementedValue();
	void m_setDoubleValues();
	void m_setStringValues();
	void m_getValues();
	void m_getStringValues();
	void m_displayValues();
	void m_postIncrementString();

	Array2D<T> operator+(const Array2D<T>& other);
	Array2D<T>& operator += (const int val);
	T operator()(int row, int col);
	bool operator == (const Array2D<T>& other);
	bool operator != (const Array2D<T>& other);
	Array2D<T>& operator ++ (int);
	Array2D<T>& operator ++ ();


	template<typename U>
	 class Proxy {
	    public:
	        Proxy(T* _array) : _array(_array) { }

		    T operator[](int index) {
		    	return _array[index];
		    }
		    private:
		        T* _array;
		    };

		Proxy <double> operator[](int index) {
		        return Proxy<double>(array[index]);
		    }

};

#endif /* ARRAY_H_ */
