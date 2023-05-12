#include <iostream>
#include <Windows.h>
#include <fstream>
#include <stdio.h>
#include <stdarg.h>
#include "Queue.h"

using namespace std;

// default constructor
Queue::Queue() {
	this->currentSize = 0;
	this->size = 1;
	this->arr = new int[this->size];
}

// universal inizialize constructor
Queue::Queue(int size, int el...) {
	this->currentSize = 0;
	this->size = size;
	this->arr = new int[this->size];

	va_list arg_list;
	va_start(arg_list, size);
	for (int i = 0; i < size; i++) {
		this->arr[i] = va_arg(arg_list, int);
	}
	va_end(arg_list);
}

// the main constructor
Queue::Queue(int size) {
	this->currentSize = 0;
	this->size = size;
	this->arr = new int[this->size];
}

// copy constructor
Queue::Queue(const Queue& other) {
	this->currentSize = other.currentSize;
	this->size = other.size;
	this->arr = new int[this->size];

	for (int i = 0; i < this->size; i++) {
		this->arr[i] = other.arr[i];
	}
}


// get the size of the array
int Queue::getSize() {
	return this->size;
}

void Queue::pushNum(int num)
{
	if (currentSize == size)
	{
		int* newArr = new int[this->size + 10];

		for (int i = 0; i < this->size; i++) {
			newArr[i] = this->arr[i];
		}
		delete[] this->arr;
		this->arr = newArr;
		this->arr[this->size] = num;
		this->size = this->size + 10;
		this->currentSize++;
	}
	else
	{this->arr[this->currentSize] = num;
	this->currentSize++; }
	
}

void Queue::popNum()
{
	if (currentSize !=0)
	{
		int* newArr = new int[this->size];

		for (int i = 0; i < this->size-1; i++) {
			newArr[i] = this->arr[i+1];
		}
		delete[] this->arr;
		this->arr = newArr;
		
		this->currentSize--;
	}
}


// redefining the assignment operation
const Queue& Queue::operator= (const Queue& other) {
	this->size = other.size;
	if (this->arr != nullptr) {
		delete[] this->arr;
	}
	this->arr = new int[this->size];

	for (int i = 0; i < this->size; i++) {
		this->arr[i] = other.arr[i];
	}
	return *this;
}


// destructor for clearing the memory allocated for the array 
Queue::~Queue() {
	delete[] this->arr;
}

//Redefining streaming input operations
ostream& operator << (ostream& os, Queue& a) {
	for (int i = 0; i < a.currentSize; i++) {
		os << a.arr[i] << " ";
	}
	os << endl;
	return os;
}

////Redefining streaming output operations
//istream& operator >> (istream& is, Queue& a) {
//	for (int i = 0; i < a.getSize(); i++)
//	{
//		is >> a.arr[i];
//	}
//	return is;
//}

