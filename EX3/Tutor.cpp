#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ostream>
#include "Tutor.h"
using namespace std;
Tutor::Tutor() :Teacher()
{

}
Tutor::Tutor(char* name, long id, int num_of_years, int num_of_professions, char** Names_of_subjects_studied, char name_of_class[4]) : Teacher(name, id, num_of_years, num_of_professions, Names_of_subjects_studied)
{
	strcpy(this->name_of_class, name_of_class);
}
Tutor:: ~Tutor()
{
	
}
void Tutor::print_C_n()const
{
	cout << name << endl;
	cout << name_of_class << endl;

}
void Tutor::print()const
{
	cout << "Tutor" << endl;
	Teacher::print();
	cout << "The name of the class: " << name_of_class << endl;
}
float Tutor::get_salery()const
{
	return Teacher::get_salery() + 1000;
}
const char* Tutor::get_name_of_class()const
{
	return name_of_class;
}