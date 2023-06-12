#include "Ads.h"


Ads::Ads()
{
	this->header = "---";
	this->text = "";
	this->beginDate = "01.01.1970";
	this->endDate = "02.01.1970";
	this->price = 0;

}
Ads::Ads(string header, string text, string beginDate, string endDate, int price)
{
	this->header = header;
	this->text = text;
	this->beginDate = beginDate;
	this->endDate = endDate;
	this->price = price;
}
Ads::~Ads()
{

}
string Ads::getDates()
{
	return this->beginDate + "-" + this->endDate;
}
int Ads::getPrice()
{
	return this->price;
}

const Ads& Ads::operator= (const Ads& other) {
	this->beginDate = other.beginDate;
	this->endDate = other.endDate;
	this->price = other.price;
	this->header = other.header;
	this->text = other.text;
	return *this;
}
ostream& operator << (ostream& os, Ads& a) {
	os << "Заголовок : " << a.header <<
		endl << "----" << a.text << "----" <<
		endl << "Цена : " << a.price << "р" <<
		endl << "Дата объявления : " << a.getDates() << endl;
	return os;
}
void Ads::deleteText()
{
	this->text = "                ";
}
