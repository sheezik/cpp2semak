
#include "News.h"


News::News()
{
	this->header = "---";
	this->text = "";
	this->date = "01.01.1970";
	this->theme = "эпоха Unix";
}
News::News(string header, string text, string date, string theme)
{
	this->header = header;
	this->text = text;
	this->date = date;
	this->theme = theme;
}
News::~News()
{

}
string News::getDate()
{
	return this->date;
}
string News::getTheme()
{
	return this->theme;
}
const News& News::operator= (const News& other) {
	this->date = other.date;
	this->theme = other.theme;
	this->header = other.header;
	this->text = other.text;
	return *this;
}
ostream& operator << (ostream& os, News& a) {
	os << "Заголовок : " << a.header <<
		endl << "Тема  : " << a.theme <<
		endl << "----" << a.text << "----" <<
		endl << "Дата : " << a.date  << endl;
	return os;
}
void News::deleteText()
{
	this->text = "                ";
}
