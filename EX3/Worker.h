#pragma once
class Worker
{
public:
	Worker();
	Worker(char* name, long id, int num_of_years);
	virtual void print()const = 0;
	virtual ~Worker();
	long get_id()const;
	virtual float get_salery()const = 0;
protected:
	char* name;
	long id;
	int num_of_years;

};

