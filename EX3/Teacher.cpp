#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ostream>
#include "Teacher.h"
using namespace std;
Teacher::Teacher() :Worker()
{
	Names_of_subjects_studied = NULL;
	num_of_professions = 0;
}
Teacher::Teacher(char* name, long id, int num_of_years, int num_of_professions, char** Names_of_subjects_studied) : Worker(name, id, num_of_years)
{
	this->num_of_professions = num_of_professions;
	/*this->Names_of_subjects_studied = new char* [num_of_professions];
	if (!this->Names_of_subjects_studied) {
		cout << "no memory!!" << endl;
		exit(1);
	}
	for (int i = 0; i < num_of_professions; ++i) {
		this->Names_of_subjects_studied[i] = new char[strlen(Names_of_subjects_studied[i]) + 1];
		if (!this->Names_of_subjects_studied[i]) {
			cout << "no memory!!" << endl;
			exit(1);
		}
		strcpy(this->Names_of_subjects_studied[i], Names_of_subjects_studied[i]);
	}
	for (int i = 0; i < num_of_professions; ++i) {
		delete[]  Names_of_subjects_studied[i];
	}
	delete[]  Names_of_subjects_studied;*/
	this->Names_of_subjects_studied = Names_of_subjects_studied;
}
void Teacher::Find_a_specialty(const char name[])const
{
	for (int i = 0; i < num_of_professions; ++i)
	{
		if (strcmp(Names_of_subjects_studied[i], name) == 0)
			cout << this->name << endl;
	}
}
Teacher:: ~Teacher()
{
	for (int i = 0; i < num_of_professions; i++) {
		delete[] Names_of_subjects_studied[i];
	}
	delete[] Names_of_subjects_studied;
	
}
void Teacher::print()const
{
	cout << "Teacher information is: " << endl;
	cout << name << endl << id << endl << num_of_years << endl;
	cout << "The nums of the professions that the teacher teaches are : " << num_of_professions << endl;
	cout << "The names of the professions that the teacher teaches are : " << endl;
	for (int i = 0; i < num_of_professions; ++i) {
		cout << Names_of_subjects_studied[i];
		if (i < num_of_professions - 1)
		{
			cout << ",";
		}
	}
	cout << endl;

}
float Teacher::get_salery()const
{
	float salery;
	salery = 5000 + 500 * (float)num_of_years + 300 * (float)num_of_professions;
	return salery;
}