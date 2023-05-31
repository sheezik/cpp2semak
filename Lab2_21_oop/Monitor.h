#pragma once
#include "Notebook.h"
class Monitor : public Notebook
{
protected:
	string image;
public:
	Monitor();
	Monitor(string name, int price, int display,string image);
	~Monitor();
	const Monitor& operator = (const Monitor& other);
	friend ostream& operator << (ostream& os, Monitor& a);
	void crashComp() override;
	void setImage(string image) ;

};