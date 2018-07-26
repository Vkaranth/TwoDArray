/*
 * Array2D.h
 *
 *  Created on: Jul 25, 2018
 *      Author: karanv3
 */

#ifndef ARRAY2D_H_
#define ARRAY2D_H_
#include <iostream>
using namespace std;

template<typename T>
class Array2D{

private:
	T ** array;
	int rowCount;
	int colCount;

public:

	Array2D(int rowcount, int colcount);
	//~Array2D();
	void m_setDoubleValues();
	void m_displayValues();

	void m_setStringValues();
	int getRows();
	int getCols();

	Array2D<T> operator+(const Array2D<T>& other);
	Array2D<T>& operator += (const int val);
	T operator()(int row, int col);
	bool operator == (const Array2D<T>& other);
	bool operator != (const Array2D<T>& other);
	//T operator ++ (const Array2D<T>& other, int index);


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

//	~Array2D(){
//		for(int i = 0; i < rowCount; ++i) {
//		    delete [] array[i];
//		}
//		delete [] array;
//		cout << "Deleted\n";
//	}


};




#endif /* ARRAY2D_H_ */
