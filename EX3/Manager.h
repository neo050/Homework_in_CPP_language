
#pragma once
#include "Worker.h"
class Manager :public Worker
{
public:
	Manager();
	Manager(char* name, long id, int num_of_years);
	virtual void print()const;
	virtual ~Manager();
	virtual float get_salery()const;
	void get_name()const;
};
