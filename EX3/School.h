#pragma once
#include "Worker.h"
#include "Deputy.h"
#include "Manager.h"
#include "Secretary.h"
#include "Teacher.h"
#include "Temp.h"
#include "Tutor.h"

class School
{
public:
	School();
	~School();
	void menu();
	void Add_worker(char type);
	bool check(long id);
	void adding_the_teacher_info(int& num_of_years, int& num_of_professions, char**& Names_of_subjects_studied, Worker**& temp);
	void print_profession(const char[])const;
	void print_tutors()const;
	void print_management()const;
	
private:
	int number_of_school_employees;
	Worker** workers;
	bool manager;

};

