#include "queue.h"
#include <iostream>

Queue::Queue(int n)
{
	n = 2;
	a = new int [n];
}
Queue::Queue()
{
	a = {};
}
Queue::~Queue()
{
	delete a;
}
int Queue::setNum(int index,int t)
{
	a[index] = t;
}
int Queue::getNum(int index)
{
	return a[index];
}
//int Queue::getSize()
//{
//	return sizeof(a) / sizeof(a[0]);
//}
//const Queue& Queue::operator= (const Queue& a)
//{
//	
//	return *this;
//}
//
//std::ostream& operator<<(std::ostream& cout, Queue& b)
//{	
//	
//	cout << a.getNum(1) <<" ";
//	return cout;
//}
//
//std::istream& operator>>(std::istream& cin, Queue& b)
//{
//	int t;
//	cin >> t;
//	b.setNum(index,t);
//	return cin;
//}