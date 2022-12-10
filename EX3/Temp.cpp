#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ostream>
#include "Temp.h"
using namespace std;
Temp::Temp()
{
	Weekly_working_hours = 0.0;
}
Temp::Temp(char* name, long id, int num_of_years, int num_of_professions, char** Names_of_subjects_studied, float Weekly_working_hours) :Teacher(name, id, num_of_years, num_of_professions, Names_of_subjects_studied)
{
	this->Weekly_working_hours = Weekly_working_hours;

}
Temp::~Temp()
{
	
}
void Temp::print()const
{
	cout << "temp" << endl;
	cout << name << endl << id << endl << num_of_years << endl;
	cout << "nums of Weekly working hours: " << Weekly_working_hours << endl;
}
float Temp::get_salery()const
{
	float salery = 300 * Weekly_working_hours;
	if (num_of_years > 5 && Weekly_working_hours > 10)
		salery += 700;
	return salery;
}
