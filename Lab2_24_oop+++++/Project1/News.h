#pragma once
#include "Post.h"
class News : public Post
{

protected:
	string date;
	string theme;
public:
	News();
	News(string header, string text, string date, string theme);
	~News();
	string getDate();
	string getTheme();
	const News& operator = (const News& other);
	friend ostream& operator << (ostream& os, News& a);
	void deleteText() override;

};
