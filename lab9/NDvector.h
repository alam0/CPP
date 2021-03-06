#ifndef NDVECTOR_H
#define NDVECTOR_H

#include <vector>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <iterator>


using namespace std;

//Puzzle class definition
template <typename T>

class NDvector{

	public:
		NDvector(int size = 10); //non-default constructor
		NDvector(const NDvector<T> & ); //copy constructor
		~NDvector(); //destructor
		
		int getSize() const; //return size
		const NDvector &operator=( const NDvector<T> &); //assignment operator
		T &operator[](int); //overload []
		T pushback(T);
		T popback();
		T back();
		void clear();
	private:
		int size; //size of pointer based vector
		int capacity; //max
		T *ptr; // pointer to first element of pointer based vector
		
};

// NDvector non-default constructor
template <typename T>
NDvector<T>::NDvector(int size){
	ptr = new T[size]; //create space for pointer-based vector

}

//copy constructor
template <typename T>
NDvector<T>::NDvector(const NDvector<T> &NDvectorToCopy ) : size( NDvectorToCopy.size ) {
	
	ptr = new T[ size ]; //create space for pointer-based vector
	
	for(int i = 0; i < size; i++)
		ptr[i] = NDvectorToCopy.ptr[i]; //copy into object
	
}

//destructor	
template <typename T>
NDvector<T>::~NDvector() {
	delete [] ptr; //release pointer-based vector space
} 

//function getSize
template <typename T>
int NDvector<T>::getSize() const{
	return (size); //number of elements in Vector
}

//function operator=
template <typename T>
const NDvector<T> &NDvector<T>::operator=(const NDvector<T> &right){
	if(&right != this){ //avoid self-assignment
		if(size != right.size){
			delete [] ptr; //release space
			size = right.size; //resize object
			ptr = new T[size]; //create space for vector copy
		} //end inner if
		
		for(int i = 0; i < size; i++)
			ptr[i] = right.ptr[i]; //copy vector into object
	}
	return (*this); //enables x = y = z, for example
}

template <typename T>
T &NDvector<T>::operator[](int element){
	T value = ptr[element];
	return(value);
}
//push_back
template <typename T>
T NDvector<T>::pushback(T value){
	if(size < capacity){
		//add it to the back
		ptr[size] = value;
		size++;
	}else if(size == capacity){
		//create a new vector with a larger capacity, copy, then add
		T *ptrV2;
		ptrV2 = new T[size*2];
		ptrV2 = NDvector(ptr);
		ptr[size] = value;
		size++;
	}
}	

//pop_back, remove from back
template <typename T>
T NDvector<T>::popback(){
	ptr[size-1] = NULL;
	size--;
}

//back
template <typename T>
T NDvector<T>::back(){
	return ptr[size-1];
}
//clear
template <typename T>
void NDvector<T>::clear() {
	size = 0;
}
			
#endif 
			
			
			
			
			

	
	
