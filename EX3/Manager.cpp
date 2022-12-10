#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ostream>
#include "Manager.h"
using namespace std;
Manager::Manager()
{

}
Manager::Manager(char* name, long id, int num_of_years) :Worker(name, id, num_of_years)
{

}
void Manager::print()const
{
	cout << "Manager" << endl;
	cout << name << endl << id << endl << num_of_years << endl;
}
Manager::~Manager()
{

}
float Manager::get_salery()const
{
	return 10000 + 800 * (float)num_of_years;
}
void Manager::get_name()const
{
	cout << name << endl;
}