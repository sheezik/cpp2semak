#include "PC.h"
PC::PC()
{
	this->serialNumber++;
	this->name = " ---";
	this->price = 0;
	this->tdp = 65;
	this->cpu = "intel Xeon";
}
PC::PC(string name,int price,int tdp, string cpu)
{
	this->serialNumber++;
	this->name = name;
	this->price = price;
	this->tdp = tdp;
	this->cpu = cpu;
	this->totalPrice += price;
}
PC::~PC()
{

}
const PC& PC::operator= (const PC& other) {
	this->serialNumber++;
	this->price = other.price;
	this->tdp = other.tdp;
	this->cpu = other.cpu;
	return *this;
}
ostream& operator << (ostream& os, PC& a) {
	os << "������������ : " << a.name <<
		endl <<"�������� ����� : " << a.serialNumber <<
		endl << "���� : " << a.price << "p" <<
		endl << "������������ �������� : " << a.tdp <<" W" <<
		endl << "��������� : " << a.cpu << endl;
	return os;
}
void PC::crashComp()
{
	this->tdp = 1000;
	this->cpu = "Intel Pentium";
	this->totalPrice -= this->price;
	this->price = 100000;
	this->totalPrice += this->price;
	
}
