#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ostream>
#include "Deputy.h"
using namespace std;
Deputy::Deputy()
{

}
Deputy::Deputy(char* name, long id, int num_of_years, int num_of_professions, char** Names_of_subjects_studied, char name_of_class[4]) :Tutor(name, id, num_of_years, num_of_professions, Names_of_subjects_studied, name_of_class)
{

}
Deputy:: ~Deputy()
{
	
}

void Deputy::print()const
{
	cout << "Deputy" << endl;
	Tutor::print();
}
float Deputy::get_salery()const
{
	return Tutor::get_salery() + 2500;
}
void Deputy::get_name()const
{
	cout << name << endl;
}
