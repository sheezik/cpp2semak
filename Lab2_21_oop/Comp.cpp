#include <iostream>
#include "Comp.h"

int Comp::serialNumber = 0;
int Comp::totalPrice = 0;
Comp::Comp()
{
	this->name = " ---";
	this->serialNumber= serialNumber;
	this->price = 0;
}
Comp::Comp(string name,int price)
{
	this->name = name;
	this->serialNumber++;
	this->price = price;
	this->totalPrice += price;
}
Comp::~Comp()
{

}
int Comp::getQuantity()
{
	return serialNumber;
}
int Comp::getTotalPrice()
{
	return totalPrice;
}
int Comp::getPrice()
{
	return this->price;
}
string Comp::getName()
{
	return this->name;
}