#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ostream>
#include "Secretary.h"
using namespace std;
Secretary::Secretary()
{
	extra_working_hours = 0.0;
}
Secretary::Secretary(char* name, long id, int num_of_years, float extra_working_hours) :Worker(name, id, num_of_years)
{
	this->extra_working_hours = extra_working_hours;
}
void Secretary::print()const
{
	cout << "Secretary" << endl;
	cout << name << endl << id << endl << num_of_years << endl;
	cout << "Num of extra working hours: " << extra_working_hours << endl;
}
Secretary::~Secretary()
{
	
}
float Secretary::get_salery()const
{
	return 5000 + 200 * (float)num_of_years + 60 * extra_working_hours;
}
