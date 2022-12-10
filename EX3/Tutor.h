#pragma once
#include "Teacher.h"
class Tutor : public Teacher
{
public:
	Tutor();
	Tutor(char* name, long id, int num_of_years, int num_of_professions, char** Names_of_subjects_studied, char name_of_class[4]);
	virtual ~Tutor();
	virtual void print()const;
	virtual float get_salery()const;
	virtual const char* get_name_of_class()const;
	void print_C_n()const;
protected:
	char name_of_class[4] = { " " };
};

