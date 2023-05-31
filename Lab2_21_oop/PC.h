#pragma once
#include "Notebook.h"
class PC : public Notebook
{
protected:
	int tdp;
public:
	PC();
	PC(string name, int price, int tdp, string cpu);
	~PC();
	const PC& operator = (const PC& other);
	friend ostream& operator << (ostream& os, PC& a);
	void crashComp() override;

};