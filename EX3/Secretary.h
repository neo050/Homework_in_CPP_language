#pragma once
#include "Worker.h"
class Secretary : public Worker
{
public:
	Secretary();
	Secretary(char* name, long id, int num_of_years, float extra_working_hours);
	virtual void print()const;
	virtual ~Secretary();
	virtual float get_salery()const;

private:
	float extra_working_hours;
};
