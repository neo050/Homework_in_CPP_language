#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Student.h"
#include "Worker.h"
#define SIZE 10
using namespace std;
long int Worker:: total_Worker=0;
double Worker::total_Salary=0.0;
long int student::total_num_course=0;
long int student::total_grades=0;
  void Find(student** arr1,int size1, Worker** arr2, int size2, char id[SIZE]) {
	  int find = 0;
	  for (int i = 0; i < size1; i++) {
		  if (strcmp(id, arr1[i]->id) == 0) {
			  cout << *arr1[i];
			  ++find;
		  }
	  }
	  if (find == 0) {
		  for (int j = 0; j < size2; j++) {
			  if (strcmp(id, arr2[j]->id) == 0) {
				  cout << *arr2[j];
				  ++find;
			  }
		  }
	  }
	  if (find == 0) {
		  cout << "There is no person with this ID in our database" << endl;
	  }
	  
  }
int rich(Worker** arr1, int size1) {
	float max = arr1[0]->get_Salary();
	int Index = 0;
	for (int i = 1; i < size1; ++i) {
		if( arr1[i]->get_Salary() > max) {
			max = arr1[i]->get_Salary();
			Index = i;
		}
	}
	return Index;
}
int best(student** arr1, int size1) {
	float max = arr1[0]->averege();
	int Index = 0;
	for (int i = 1; i < size1; ++i) {
		if (arr1[i]->averege() > max) {
			max = arr1[i]->averege();
			Index = i;
		}
	}
	return Index;
}

int main() {
	char name[20], id[10];
	int choice=1,k, Studentindex, Studentscore, Workerindex;
	float Salary, Workervalue;
	int sizeStudent, sizeWorker;
	cout << "enter num of Students: ";
	cin >> sizeStudent; cout << endl;
	cout << "enter num of Workers: ";
	cin >> sizeWorker; cout << endl;
	student** students = new student * [sizeStudent];
	if (!students) {
		cout << "no memory!!" << endl;
		exit(1);
	}
	Worker** workers = new Worker * [sizeWorker];
	if (!workers) {
		cout << "no memory!!" << endl;
		delete[]students;
		exit(1);
	}

	for (int i = 0; i < sizeStudent; ++i) {
		cout << "enter name of student" << " " << i << ":" << " ";
		cin >> name; cout << endl << "enter ID of student" << " " << i << ":" << " ";
	    cin >> id; cout << endl;
		students[i] = new student(name, id);
	}
	for (int j = 0; j < sizeWorker; ++j) {
		cout << "enter name of worker" << " " << j << ":" << " ";
		cin >> name; cout << endl << "enter ID of  worker" << " " << j << ":" << " ";
		cin >> id; cout << endl << "enter salary of  worker" << " " << j << ":" << " ";
		cin >> Salary; cout << endl;
		workers[j] = new Worker(name, id, Salary);
	}
	cout << "Hello dear Arthur(; Please select an option according to the numbers shown to you, if you want to close the program enter 10." << endl << endl;
	do {
		cout <<"1. Print all the information of the employees and students"<<endl;
		cout <<"2. Adding a grade in a new course for a student."<<endl;
		cout <<"3. Printing a student with the highest average."<<endl;
		cout <<"4. Print the average of all the grades of all the students."<<endl;
		cout <<"5. Changing an employee's salary to monetary value."<<endl;
		cout <<"6. Change of employee's salary in percent."<<endl;
		cout <<"7. Printing an employee with the highest salary." << endl;
		cout <<"8. Printing average wages."<< endl;
		cout <<"9. Printing information about a person by ID number." << endl;
		cout <<"10. To end the program." << endl;
		cout << "Please enter your choice: "; cin >> choice; cout << endl;
		if (choice > 0 && choice < 11) {
			switch (choice)
			{
			case 1:
				for (k = 0; k < sizeStudent; ++k)
					cout << *students[k];
				for (k = 0; k < sizeWorker; ++k)
					cout << *workers[k];
				break;
			case 2:
				cout << "Please enter the student number in the above range" << "0 -" << sizeStudent - 1 <<" and score between 0-100 "<<endl;
				cout << "Enter student index: "; cin >> Studentindex; cout << endl;
				cout << "Enter student score: "; cin >> Studentscore; cout << endl;
				if ((Studentindex >= sizeStudent || Studentindex < 0)||!(Studentscore>=0&& Studentscore<=100)) {
					cout << "Error !! Invalid index or invalid score" << endl;
					break;
				}
				*students[Studentindex] += Studentscore;
				break;
			case 3:
				Studentindex = best(students, sizeStudent);
				cout << *students[Studentindex];
				break;
			case 4:
				cout<<(*students[0]).get_total_averege()<<endl;
				break;
			case 5:
				cout << "Please enter the worker number in the above range between " << "0-" << sizeWorker - 1 << " and the change  mony " << endl;
				cout << "Enter worker index: "; cin >> Workerindex; cout << endl;
				cout << "Enter worker change mony: "; cin >> Workervalue; cout << endl;
				if (Workerindex >= sizeWorker || Workerindex < 0) {
					cout << "Error !! Invalid index " << endl;
					break;
				}
				*workers[Workerindex]+=Workervalue;
				break;
			case 6:
				cout << "Please enter the worker number in the above range" << "0 -" << sizeWorker - 1 << " and the percent of change mony " << endl;
				cout << "Enter worker index: "; cin >> Workerindex; cout << endl;
				cout << "percent of change mony: "; cin >> Workervalue; cout << endl;
				if (Workerindex >= sizeWorker || Workerindex < 0) {
					cout << "Error !! Invalid index " << endl;
					break;
				}
				*workers[Workerindex] *= Workervalue;
				break;
			case 7:
				Workerindex = rich(workers, sizeWorker);
				cout << *workers[Workerindex];
				break;
			case 8:
				cout<<(*workers[0]).get_total_averege_Salary()<<endl;
				break;
			case 9:
				cout << "Please enter the worker or the student  ID" << "0 -" << endl;
				cout << "Enter ID: ";
				cin >> id; cout << endl;
				Find(students, sizeStudent, workers, sizeWorker, id);
				break;
			case 10:
				cout << "Goodbye Arthur have a wonderful day (;" << endl;
				choice = 10;
			}
		}
	} while (choice !=10);
	

	for (int i = 0; i < sizeStudent; ++i) 
		delete students[i];
	delete[] students;
	
	for (int j = 0; j < sizeWorker; ++j) 
		delete workers[j];
	delete[] workers;

	return 0;
}