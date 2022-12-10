#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cstring>
#include <string>
#define SIZE 10
using namespace std;
class Worker;
//class student;

//void Find(student** arr1, int size1, Worker** arr2, int size2, char id[SIZE]);
class student
{
public:
	/*student(string name, string id, int* grades, int num_course);*/
	void set_id_name(char name[], char id[]);
	student(char name[], char id[]);
	student(const student& neoray);
	friend ostream& operator<<(ostream& os, const student& nahray);
	float averege()const;
	student  operator+=(int grade);
	/*student& operator=(student& n);*/
	bool  operator >(const student& neoray)const;
	static double get_total_averege();
	int get_num_course()const;
	int get_grades()const;
	friend void Find(student** arr1, int size1, Worker** arr2, int size2, char id[SIZE]);
	~student();

private:
	char* name;
	char id[SIZE];
	int num_course;
	static long int total_num_course;
	static long int total_grades;
	int* grades;
};
