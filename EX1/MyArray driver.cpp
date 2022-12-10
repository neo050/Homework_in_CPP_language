#include<iostream>
#include<cstring>
#include "MyArray.h"
#include <iomanip>
using namespace std;
int main() {
	float arr[] = { 1.3,7.629846,852.647012,-5.0249705,54467 };
	float arr1[] = {1,2,9 };
	float arr2[] = {0,1,0,1 };
	MyArray x(arr,5),y(x);
	x.printArray();
	x.Change_a_Element(1,5.3);
	x.printArray();
	y.printArray();
	x.NewArray( arr1, 3);
	x.printArray();
	y.NewArray(arr1, 3);
	y.printArray();
	y.Change_a_Element(1, 5.3);
	cout << y.Sum_Array() << endl;
	cout << x.Sum_Array() << endl;
	y.printArray();
	return 0;
}