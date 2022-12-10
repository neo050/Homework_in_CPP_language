#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ostream>
//#include <cstring>
#include <string>
#include "Worker.h"
using namespace std;
void Worker::set_id_name(char name[], char id[]) {
	this->name = new char[strlen(name) + 1];
	if (!this->name) {
		cout << "no memory";
		exit(1);
	}
	strcpy(this->name, name);
	strcpy(this->id, id);
}
Worker::Worker (char name[], char id[], float Salary) {
	set_id_name(name,  id);
	this->Salary = Salary;
	total_Worker += 1;
	total_Salary += Salary;
}
Worker::Worker(const Worker& neoray) {
	this->name = new char[strlen(neoray.name) + 1];
	if (!this->name) {
		cout << "no memory";
		exit(1);
	}
	strcpy(this->name, neoray.name);
	strcpy(this->id, id);
	Salary = neoray.Salary;
	total_Worker += 1;
	total_Salary += neoray.Salary;
}
ostream& operator<<(ostream& os, const Worker& neoray) {
	os << "Worker name:" << neoray.name << endl << "Id:" << neoray.id << endl << "Salary:" << neoray.Salary << endl;
	return os;
}
double Worker::get_total_averege_Salary() {
	return total_Salary / total_Worker;
}
Worker Worker::operator+=(float num) {
	total_Salary -= Salary;
	Salary += num;
	total_Salary += Salary;
	return *this;
}
Worker Worker::operator*=(float num) {
	total_Salary -= Salary;
	Salary = Salary+ Salary*(num/100);
	total_Salary += Salary;
	return *this;
}
bool Worker::operator>(const Worker& neoray)const {
	if (Salary > neoray.Salary)
		return true;
	return false;
}
float Worker::get_Salary()const {
	return Salary;
}
Worker::~Worker() {
	total_Salary -= Salary;
	total_Worker -= 1;
	delete[] name;
}
