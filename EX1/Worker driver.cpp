#include<iostream>
#include<cstring>
#include "Worker.h"
#include <iomanip>
#define MAX 15
using namespace std;
int main() {
	char name[MAX] = { "neoray hagag" };
	Worker neoray(name, 208090738, 55.6, 200, 50);
	neoray.printDataEmployee();
	neoray.setExtraWorkingHours(55);
	neoray.printDataEmployee();
	neoray.setHourlyWage(89.3);
	neoray.printDataEmployee();
	cout << neoray.getName() << endl<< neoray.getExtraWorkingHours()<<endl<< neoray.getmonypay()<<endl<<neoray.getHourlyWage()<<endl<< neoray.getworkHours()<<endl;
	return 0;
}