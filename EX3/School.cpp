#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <ostream>
#include "School.h"
#include <typeinfo>
using namespace std;
bool School::check(long id)
{
	for (int i = 0; i < number_of_school_employees; ++i) {
		if (id == workers[i]->get_id())
			return false;
	}
	return true;
}
void School::adding_the_teacher_info(int& num_of_years, int& num_of_professions, char**& Names_of_subjects_studied, Worker**& temp)
{
	char name_of_subject[20];
	temp = new Worker * [number_of_school_employees + 1];
	if (!temp) {
		cout << "no memory!!" << endl;
		exit(1);
	}
	for (int i = 0; i < number_of_school_employees; ++i)
		temp[i] = workers[i];
	cout << "Enter data of teacher enter the data by the order shown: num of years, num of professions : "; cin >> num_of_years; cin >> num_of_professions;
	Names_of_subjects_studied = new char* [num_of_professions];
	if (!Names_of_subjects_studied) {
		cout << "no memory!!" << endl;
		exit(1);
	}
	for (int i = 0; i < num_of_professions; ++i) {
		cout << "Enter name of profession: " << i << endl;
		cin >> name_of_subject;
		Names_of_subjects_studied[i] = new char[strlen(name_of_subject) + 1];
		if (!Names_of_subjects_studied[i]) {
			cout << "no memory!!" << endl;
			exit(1);
		}
		strcpy(Names_of_subjects_studied[i], name_of_subject);
		
	}
}
void School::print_profession(const char profession[])const
{
	for (int i = 0; i < number_of_school_employees ; i++) {
		if (strcmp(typeid(*workers[i]).name(), "class Teacher") == 0 || strcmp(typeid(*workers[i]).name(), "class Temp")==0 || strcmp(typeid(*workers[i]).name(), "class Tutor") == 0 || strcmp(typeid(*workers[i]).name(), "class Deputy") == 0) {
			if (dynamic_cast<Teacher*>(workers[i]) != NULL) {
				(dynamic_cast<Teacher*>(workers[i]))->Find_a_specialty(profession);
			}
			else
			{
				cout << "no memory!!" << endl;
				exit(1);
			}
		}
	}

}
void School::print_tutors()const
{
	for (int i = 0; i < number_of_school_employees; i++) {
		if (strcmp(typeid(*workers[i]).name(), "class Tutor") == 0 || strcmp(typeid(*workers[i]).name(), "class Deputy") == 0 ) {
			if (dynamic_cast<Tutor*>(workers[i]) != NULL) {
				(dynamic_cast<Tutor*>(workers[i]))->print_C_n();
			}
			else
			{
				cout << "no memory!!" << endl;
				exit(1);
			}
		}
	}
}
void School::print_management()const
{
	for (int i = 0; i < number_of_school_employees; i++) {
		if (strcmp(typeid(*workers[i]).name(), "class Manager") == 0 || strcmp(typeid(*workers[i]).name(), "class Deputy") == 0) {
			if (strcmp(typeid(*workers[i]).name(), "class Manager") == 0) {
				if (dynamic_cast<Manager*>(workers[i]) != NULL) {
					(dynamic_cast<Manager*>(workers[i]))->get_name();
					
			    }
				else
				{
					cout << "no memory!!" << endl;
					exit(1);
				}
			
			}
			else
			{
				if (dynamic_cast<Deputy*>(workers[i]) != NULL) {
					(dynamic_cast<Deputy*>(workers[i]))->get_name();

				}
				else
				{
					cout << "no memory!!" << endl;
					exit(1);
				}
			}
			
		}
	}
}
void School::Add_worker(char type)
{
	int k = 0;
	char name[11];
	char name_of_class[4];
	long id;
	Worker** temp=NULL;
	int num_of_years;
	int num_of_professions;
	char** Names_of_subjects_studied=NULL;
	float Weekly_working_hours;
	float num_of_extra;
	cout << "Ernter workwe id: "; cin >> id; cout << endl;
	switch (type) {

	case 'A':
		if (check(id)) {
			
			adding_the_teacher_info(num_of_years, num_of_professions, Names_of_subjects_studied, temp);
			cout << "Enter worker name" << endl;
			cin >> name;
			temp[number_of_school_employees] = new Teacher(name, id, num_of_years, num_of_professions, Names_of_subjects_studied);
			if (!temp[number_of_school_employees]) {
				cout << "no memory!!" << endl;
				exit(1);
			}
			
			number_of_school_employees += 1;
			delete[]workers;
			this->workers = temp;
		}
		else {
			cout << "There is already a person with this ID in our system !!!!!" << endl;
		}
		break;
	case 'B':
		
		if (check(id)) {

			adding_the_teacher_info(num_of_years, num_of_professions, Names_of_subjects_studied, temp);
			cout << "Enter worker name" << endl;
			cin >> name;
			cout << "Ernter worker  weekly working hours: "; cin >> Weekly_working_hours; cout << endl;
			temp[number_of_school_employees] = new Temp(name, id, num_of_years, num_of_professions, Names_of_subjects_studied, Weekly_working_hours);
			if (!temp[number_of_school_employees]) {
				cout << "no memory!!" << endl;
				exit(1);
			}
			number_of_school_employees += 1;
			delete[]workers;
			this->workers = temp;
		}
		else {
			cout << "There is already a person with this ID in our system !!!!!" << endl;
		}
		break;
	case 'C':
		if (check(id)) {
			cout << "Enter name of class: "; cin >> name_of_class; cout << endl;
			for (int i = 0; i < number_of_school_employees && (!k); i++) {
				if (strcmp(typeid(*workers[i]).name(), "class Tutor") == 0|| strcmp(typeid(*workers[i]).name(), "class Deputy") == 0) {
					if (dynamic_cast<Tutor*>(workers[i]) != NULL) {
						if (strcmp((dynamic_cast<Tutor*>(workers[i]))->get_name_of_class(), name_of_class) == 0) {
							k = 1;
							cout << "There is already an educator for this class" << endl;
						}
							
					}
					else
					{
						cout << "no memory!!" << endl;
						exit(1);
					}
				}
			}
			if (!k) {
				adding_the_teacher_info(num_of_years, num_of_professions, Names_of_subjects_studied, temp);
				cout << "Enter worker name" << endl;
				cin >> name;
				temp[number_of_school_employees] = new Tutor(name, id, num_of_years, num_of_professions, Names_of_subjects_studied, name_of_class);
				if (!temp[number_of_school_employees]) {
					cout << "no memory!!" << endl;
					exit(1);
				}
				number_of_school_employees += 1;
				delete[]workers;
				this->workers = temp;
			}

		}
		else {
			cout << "There is already a person with this ID in our system !!!!!" << endl;
		}
		break;
	case 'D':
		if (check(id))
		{
			cout << "Enter name of class: "; cin >> name_of_class; cout << endl;
			for (int i = 0; i < number_of_school_employees && (!k); i++) {
				if (strcmp(typeid(*workers[i]).name(), "class Deputy") == 0 || strcmp(typeid(*workers[i]).name(), "class Tutor") == 0) {
					if (dynamic_cast<Tutor*>(workers[i]) != NULL) {
						if (strcmp((dynamic_cast<Tutor*>(workers[i]))->get_name_of_class(), name_of_class) == 0) {
							k = 1;
							cout << "There is already an educator for this class" << endl;
						}
							
					}
					else
					{
						cout << "no memory!!" << endl;
						exit(1);
					}
				}
			}
			if (!k)
			{
				adding_the_teacher_info(num_of_years, num_of_professions, Names_of_subjects_studied, temp);
				cout << "Enter worker name" << endl;
				cin >> name;
				temp[number_of_school_employees] = new Deputy(name, id, num_of_years, num_of_professions, Names_of_subjects_studied, name_of_class);
				if (!temp[number_of_school_employees]) {
					cout << "no memory!!" << endl;
					exit(1);
				}
				number_of_school_employees += 1;
				delete[]workers;
				this->workers = temp;
			}

		}
		else {
			cout << "There is already a person with this ID in our system !!!!!" << endl;
		}
		break;//Deputy
	case 'E':
		if (check(id))
		{
			if (!manager) {
				cout << "Enter number of years: "; cin >> num_of_years; cout << endl;
				cout << "enter name: "; cin >> name; cout << endl;
				temp = new Worker * [number_of_school_employees + 1];
				if (!temp) {
					cout << "no memory!!" << endl;
					exit(1);
				}
				for (int i = 0; i < number_of_school_employees; ++i)
					temp[i] = workers[i];
				temp[number_of_school_employees] = new Manager(name, id, num_of_years);
				if (!temp[number_of_school_employees]) {
					cout << "no memory!!" << endl;
					exit(1);
				}
				number_of_school_employees += 1;
				delete[]workers;
				this->workers = temp;
				manager = true;
			}
		}
		else
		{
			cout << "There is already a  manager of this school!!" << endl;
		}

		break;
	case 'F':
		if (check(id))
		{

			cout << "Enter number of years: "; cin >> num_of_years; cout << endl;
			cout << "enter name: "; cin >> name; cout << endl;
			cout << "enter num of extra: "; cin >> num_of_extra; cout << endl;
			temp = new Worker * [number_of_school_employees + 1];
			if (!temp) {
				cout << "no memory!!" << endl;
				exit(1);
			}
			for (int i = 0; i < number_of_school_employees; ++i)
				temp[i] = workers[i];
			temp[number_of_school_employees] = new Secretary(name, id, num_of_years, num_of_extra);
			if (!temp[number_of_school_employees]) {
				cout << "no memory!!" << endl;
				exit(1);
			}
			number_of_school_employees += 1; 
			delete[]workers;
			this->workers = temp;

		}
		break;
	}


}
School::School()
{
	workers =NULL;
	number_of_school_employees = 0;
	manager = false;
}

School::~School()
{
	for (int i = 0; i < number_of_school_employees; ++i) {
		delete workers[i];
	}

	delete[]workers;
}
void School::menu()
{
	char choice='0';
	char choiceW='0';
	char profession[20];

	do
	{

		cout << endl;
		cout << "Please select an exercise option regarding the school" << endl;
		cout << "1. Add worker" << endl;
		cout << "2. Print workers" << endl;
		cout << "3. Print profession" << endl;
		cout << "4. Print tutors" << endl;
		cout << "5. Print management" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: "; cin >> choice; cout << endl;

		if ((choice >= '1' && choice <= '6'))
		{
			switch (choice)
			{
			case '1': 
				cout << "Choose type of worker:" << endl
					<< "A. Teacher" << endl
					<< "B. Temp" << endl
					<< "C. Tutor" << endl
					<< "D. Deputy" << endl
					<< "E. Manager" << endl
					<< "F. Secretary" << endl;
				cin >> choiceW;
				if (!(choiceW <= 'F' && choiceW >= 'A')) {
					cout << "Please enter a selection in the range of letters presented to you !!" << endl;
					break;
				}
				switch (choiceW)
				{
				case 'A':
					Add_worker('A');
					break;
				case 'B':
					Add_worker('B');
					break;
				case 'C':
					Add_worker('C');
					break;
				case 'D':
					Add_worker('D');
					break;
				case 'E':
					Add_worker('E');
					break;
				case 'F':
					Add_worker('F');
					break;
				}
				break;
			case '2':
				if (!workers)
				{
					cout << "The school is empty, please add workers!" << endl;
					break;
				}
				for (int i = 0; i < number_of_school_employees; ++i) {
					workers[i]->print();
						cout << "salery: " << workers[i]->get_salery() <<endl;
				}
					
				break;
			case '3':
				if (!workers)
				{
					cout << "The school is empty, please add workers!" << endl;
					break;
				}
				cout << "Please enter the required profession name: "; cin >> profession; cout<< endl;
				print_profession(profession);
				break;
			case '4':
				if (!workers)
				{
					cout << "The school is empty, please add workers!" << endl;
					break;
				}
				print_tutors();
				break;
			case '5':
				if (!workers)
				{
					cout << "The school is empty, please add workers!" << endl;
					break;
				}
				print_management();
				break;
			case '6':
				choice = '6';
			}

		}
		else
		{
			cout << "Hey little piece of shit Enter your choice according to the range presented to you !!!  lol" << endl;
		
		
		}
	} while (choice != '6');
}