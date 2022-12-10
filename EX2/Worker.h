#define _CRT_SECURE_NO_WARNING
#include <iostream>
//#include <ostream>
//#include <cstring>
#include <string>

#define SIZE 10
using namespace std;
class student;
//class Worker;

// void Find(student** arr1, int size1, Worker** arr2, int size2, char id[SIZE]);
class Worker 
{
public:
	
	Worker(char name[], char id[], float Salary);
	Worker(const Worker &neoray);
	friend ostream& operator<<(ostream& os, const Worker& neoray);
	Worker operator+=(float num);
	Worker operator*=(float num);
	bool operator>(const Worker& neoray)const;
	static double get_total_averege_Salary();
	friend void Find(student** arr1, int size1, Worker** arr2, int size2, char id[SIZE]);
	float get_Salary()const;
	~Worker();

private:
	void set_id_name(char name[], char id[]);
	static long int total_Worker;
	static double total_Salary;
	char* name;
	char id[10];
	float Salary;
};


