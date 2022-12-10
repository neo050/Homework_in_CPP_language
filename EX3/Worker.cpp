#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ostream>
#include "Worker.h"
using namespace std;
Worker::Worker() {
	name = NULL;
	id = 0;
	num_of_years = 0;
}
Worker::Worker(char* name, long id, int num_of_years) {
	this->name = new char[strlen(name) + 1];
	if (!this->name) {
		cout << "no memory!!" << endl;
		exit(1);
	}
	strcpy(this->name, name);
	this->id = id;
	this->num_of_years = num_of_years;
}

Worker:: ~Worker() {
	delete[] name;
}
long Worker::get_id()const
{
	return id;
}