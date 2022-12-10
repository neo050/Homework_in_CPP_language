
#pragma once
#include "Tutor.h"
class Deputy :public Tutor
{
public:
	Deputy();
	Deputy(char* name, long id, int num_of_years, int num_of_professions, char** Names_of_subjects_studied, char name_of_class[4]);
	virtual ~Deputy();
	virtual void print()const;
	virtual float get_salery()const;
	void get_name()const;
};

