#include <iostream>
#include "Post.h"


Post::Post()
{
	this->header = "---";
	this->text = "";
}
Post::Post(string header, string text)
{
	this->header = header;
	this->text = text;
}
Post::~Post()
{

}
string Post::getHeader()
{
	return this->header;
}
string Post::getText()
{
	return this->text;
}
