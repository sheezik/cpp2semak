#pragma once
#include "Post.h"
class Article : public Post
{

protected:
	string author;
public:
	Article();
	Article(string header, string text, string author);
	~Article();
	string getAuthor();
	const Article& operator = (const Article& other);
	friend ostream& operator << (ostream& os, Article& a);
	void deleteText() override;

};

