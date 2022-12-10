#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "Worker.h"
#include <iomanip>
using namespace std;
Worker::Worker() {
	 id = 0;
	 HourlyWage=0.0;
	 workHours = 0;
	 ExtraWorkingHours=0;
	 monypay = 0.0;
}
Worker::Worker(char name[], long id, double HourlyWage, int workHours, int ExtraWorkingHours) {
	strcpy(this->name, name);
	this->id = id;
	this->HourlyWage = HourlyWage;
	this->workHours = workHours;
	this->ExtraWorkingHours = ExtraWorkingHours;
	paymony();
}
double Worker::getHourlyWage()const {
	return HourlyWage;
}
const char* Worker::getName()const {
	return name;
}
long Worker::getId()const {
	return id;
}
int Worker::getworkHours()const {
	return workHours;
}

int Worker::getExtraWorkingHours()const {
	return ExtraWorkingHours;
}
double  Worker::getmonypay()const {
	return monypay;
}

bool Worker::setHourlyWage(double HourlyWage) {
	this->HourlyWage = HourlyWage;
	paymony();
	return true;
}
bool Worker::setworkHours(int workHours) {
	this->workHours = workHours;
	paymony();
	return true;
}
bool Worker::setExtraWorkingHours(int extraWorkingHours) {
	this-> ExtraWorkingHours = extraWorkingHours;
	paymony();
	return true;
}
void Worker::paymony() {
  monypay = ((double)HourlyWage) *( workHours) +((double)(HourlyWage) * (ExtraWorkingHours)) * 1.5;
}
void Worker::printDataEmployee()const {
	cout << name << "," << id << "," << fixed << showpoint << setprecision(2) << HourlyWage << "," << workHours << "," << ExtraWorkingHours << "," << fixed << showpoint << setprecision(2) << monypay<<endl;
}

Worker::~Worker() {
	cout << "this is the ende" << endl;
}