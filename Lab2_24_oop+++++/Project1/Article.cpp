#include "Article.h"


Article::Article()
{
	this->header = "---";
	this->text = "";
	this->author = "Arseny";
}
Article::Article(string header, string text, string author)
{
	this->header = header;
	this->text = text;
	this->author = author;
}
Article::~Article()
{

}
string Article::getAuthor()
{
	return this->author;
}

const Article& Article::operator= (const Article& other) {
	this->author = other.author;
	this->header = other.header;
	this->text = other.text;
	return *this;
}
ostream& operator << (ostream& os, Article& a) {
	os << "Заголовок : " << a.header <<
		endl << "----" << a.text << "----" <<
		endl << "Автор : " << a.author << endl;
	return os;
}
void Article::deleteText()
{
	this->text = "                ";
}
