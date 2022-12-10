#pragma once
#include "Teacher.h"
class Temp :public Teacher
{
public:
	Temp();
	Temp(char* name, long id, int num_of_years, int num_of_professions, char** Names_of_subjects_studied, float Weekly_working_hours);
	virtual ~Temp();
	virtual void print()const;
	virtual float get_salery()const;

private:
	float Weekly_working_hours;
};
