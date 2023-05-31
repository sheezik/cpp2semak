#pragma once
#include <iostream>
using namespace std;

class Comp
{

protected :
	string name;
	int price;
	static int totalPrice;
	static int serialNumber;
public:
	Comp();
	Comp(string name,int price);
	~Comp();
	static int getQuantity();
	static int getTotalPrice();
	string getName();
	int getPrice();
	virtual void crashComp() = 0;

};