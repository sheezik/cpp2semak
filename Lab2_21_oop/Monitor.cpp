#include "Monitor.h"
Monitor::Monitor()
{
	this->name = " ---";
	this->serialNumber++;
	this->price = 0;
	this->display = 21;
	this->image = "(^_^)";
}
Monitor::Monitor(string name, int price, int display,string image)
{
	this->serialNumber++;
	this->name = name;
	this->price = price;
	this->display = display;
	this->image = image;
	this->totalPrice += price;
}
Monitor::~Monitor()
{
	
}
const Monitor& Monitor::operator= (const Monitor& other) {
	this->serialNumber++;
	this->price = other.price;
	this->display = other.display;
	this->image = other.image;
	return *this;
}
ostream& operator << (ostream& os, Monitor& a) {
	os << "Наименование : " << a.name <<
		endl <<"Серийный номер : " << a.serialNumber <<
		endl << "Цена : " << a.price << "p" <<
		endl << "Размер экрана : " << a.display << '"' <<
		endl << "Я показываю изображение  : " << a.image << endl;
	return os;
}
void Monitor::crashComp()
{
	this->image = "(>_<)";
	this->display = 16;
	this->totalPrice -= this->price;
	this->price = 100000;
	this->totalPrice += this->price;
}