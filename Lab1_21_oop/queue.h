#pragma once
#include <iostream>
class Queue 
{
private:
	int n;
	int *a;

public:
	Queue(int n);
	Queue();
	~Queue();

	int setNum(int index,int t);
	void addQueue(int index,int num);
	int getQueue();
	int getNum(int index);
	int getSize();
	void delQueue(int index);
	void print();
	const Queue& operator= (const Queue& right);
	friend std::ostream& operator<<(std::ostream& cout, Queue*& a);
	friend std::istream& operator>>(std::istream& cin, Queue& a);
	void copy(int* a);
};