#pragma once
#include "Post.h"
class Ads : public Post
{

protected:
	string beginDate, endDate;
	int price;

public:
	Ads();
	Ads(string header, string text, string beginDate,string endDate,int price);
	~Ads();
	string getDates();
	int getPrice();
	const Ads& operator = (const Ads& other);
	friend ostream& operator << (ostream& os, Ads& a);
	void deleteText() override;

};

