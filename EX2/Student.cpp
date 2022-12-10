#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <ostream>
//#include <cstring>
#include <string>
#include "Student.h"
using namespace std;
//student::student(string name, string id, int* grades, int num_course) {
//	this->name = name;
//	this->id = id;
//	if (grades) {
//		this->grades = new int[num_course];
//		if (this->grades) {
//			for (int i = 0; i < num_course; ++i)
//				this->grades[i] = grades[i];
//			this->num_course = num_course;
//			total_num_course = total_num_course + get_num_course();
//			total_grades = total_grades + get_grades();
//			return;
//		}
//		else
//		{
//			cout << "no memory" << endl;
//			exit(1);
//		}
//	}
//
//	this->num_course = 0;
//	this->grades = NULL;
//
//}
void student::set_id_name(char name[], char id[]) {
	this->name = new char[strlen(name) + 1];
	if (!this->name) {
		cout << "no memory";
		exit(1);
	}
	strcpy(this->name, name);
	strcpy(this->id, id);
}
student::student( char name[],  char id[]) {
	set_id_name(name, id);
	num_course = 0;
	grades = NULL;
}
student::student(const student& neoray) {
	this->name = new char[strlen(neoray.name) + 1];
	if (!this->name) {
		cout << "no memory";
		exit(1);
	}
	strcpy(this->name, neoray.name);
	strcpy(this->id, id);
	if (neoray.grades) {
		grades = new int[neoray.num_course];
		if (grades) {
			for (int i = 0; i < neoray.num_course; ++i)
				grades[i] = neoray.grades[i];
			num_course = neoray.num_course;
			total_num_course = total_num_course + get_num_course();
			total_grades = total_grades + get_grades();
			return;
		}
		else
		{
			cout << "no memory" << endl;
			exit(1);
		}
	}
	
		num_course = 0;
		grades = NULL;
}
float student::averege()const {
	return (float)get_grades() / (float)get_num_course();
}
student student:: operator+=(int grade) {
	if (grade >= 0 && grade <= 100) {
		int* arr = new int[num_course + 1];
		if (arr) {
			for (int i = 0; i < num_course; ++i)
				arr[i] = grades[i];
			arr[num_course] = grade;
			num_course += 1;
			delete[]grades;
			grades = arr;
			total_num_course += 1;
			total_grades += grade;

		}
		else
		{
			cout << "no memory" << endl;
			exit(1);
		}
	}
	else
	{
		cout << "not ok grade " << endl << " for ok -> 0<=  [grade] <=100  <-" << endl;
	}
	return *this;
}
ostream& operator<<(ostream& os, const student& neoray) {
	os << "student name:" << neoray.name << endl << "Id:" << neoray.id << endl << "Num of course:" << neoray.num_course << endl << "grades: ";
	for (int i = 0; i < neoray.num_course;++i) {
		os << neoray.grades[i];
		if (i < neoray.num_course - 1)
			os << ",";
	}
	os << endl;
	return os;
}
bool student:: operator >(const student& neoray)const {
	if (averege() > neoray.averege())
		return true;
	return false;
}
int student::get_num_course()const {
	return num_course;
}
int student::get_grades()const {
	int sumofgrades = 0;
	for (int i = 0; i < num_course; ++i) {
		sumofgrades += grades[i];
	}
	return sumofgrades;
}
student::~student() {
	total_num_course = total_num_course - get_num_course();
	total_grades = total_grades - get_grades();
	delete[] grades;
	delete[] name;
}
double student::get_total_averege() {
	return (double)total_grades / total_num_course;
}
