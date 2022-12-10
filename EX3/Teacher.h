#pragma once
#include "Worker.h"
class Teacher : public Worker
{
public:
	Teacher();
	Teacher(char* name, long id, int num_of_years, int num_of_professions, char** Names_of_subjects_studied);
	virtual ~Teacher();
	virtual void print()const;
	virtual float get_salery()const;
	 void Find_a_specialty(const char name[])const;

protected:
	int num_of_professions;
	char** Names_of_subjects_studied;

};

