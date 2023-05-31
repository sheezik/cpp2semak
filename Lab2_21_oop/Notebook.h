#pragma once
#include "Comp.h"
class Notebook : public Comp
{
protected:
	int display;
	string cpu;
public:
	Notebook();
	Notebook(string name,int price,int display,string cpu);
	~Notebook();
	const Notebook& operator = (const Notebook& other);
	friend ostream& operator << (ostream& os, Notebook& a);
	void crashComp() override;
};