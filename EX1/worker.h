#pragma once
class Worker
{
public:
	Worker();
	Worker(char name[],long id,double HourlyWage,int workHours,int ExtraWorkingHours);
	const char* getName()const;
	long getId()const;
	double getHourlyWage()const;
	int getworkHours()const;
	int getExtraWorkingHours()const;
	double getmonypay()const;
	bool setHourlyWage(double HourlyWage);
	bool setworkHours(int workHours);
	bool setExtraWorkingHours(int extraWorkingHours);
	void printDataEmployee()const;
	~Worker();

private:
	char name[15] = { "noName" };
	long id;
	double HourlyWage;
	int workHours;
	int ExtraWorkingHours;
	double monypay;
	void paymony();

};
