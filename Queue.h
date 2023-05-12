#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

class Queue
{
private:
	int size; // size of the array
	int currentSize = 0;
	int* arr;

public:
	Queue(); // default constructor

	Queue(int size, int el...); // universal inizialize constructor

	Queue(int size); // the main constructor

	Queue(const Queue& other); // copy constructor

	int getSize();  // get the size of the array

	void pushNum(int num);

	void popNum();

	const Queue& operator = (const Queue& other); // redefining the assignment operation
	

	~Queue(); // destructor for clearing the memory allocated for the array 

	friend ostream& operator << (ostream& os, Queue& a);
	//friend istream& operator >> (istream& is, Queue& a);

};