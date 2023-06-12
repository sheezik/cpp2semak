#pragma once
#include <iostream>
using namespace std;

class Post
{

protected:
	string header;
	string text;
public:
	Post();
	Post(string header, string text);
	~Post();
	string getHeader();
	string getText();
	virtual void deleteText() = 0;

};