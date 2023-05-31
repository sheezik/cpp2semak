#include "Notebook.h"

Notebook::Notebook()
{
	this->serialNumber = serialNumber;
	this->name = " ---";
	this->price = 0;
	this->display = 0;
	this->cpu = "intel Xeon";
}
Notebook::Notebook(string name, int price, int display, string cpu)
{
	this->serialNumber++;
	this->name = name;
	this->price = price;
	this->display = display;
	this->cpu = cpu;
	this->totalPrice += price;
}
Notebook::~Notebook()
{

}
const Notebook& Notebook::operator= (const Notebook& other) {
	this->serialNumber++;
	this->price = other.price;
	this->display = other.display;
	this->cpu = other.cpu;
	return *this;
}
ostream& operator << (ostream& os, Notebook& a) {
	os << "Наименование : " << a.name <<
		endl << "Серийный номер : " << a.serialNumber <<
		endl << "Цена : " << a.price <<"p" <<
		endl << "Размер экрана : " << a.display<<'"' <<
		endl << "Процессор : " << a.cpu << endl;
	return os;
}
void Notebook::crashComp() 
{
	this->cpu = "Intel Pentium";
	this->totalPrice -= this->price;
	this->price = 100000;
	this->totalPrice += this->price;
	this->display = 10;
}
