#pragma once
class MyArray
{
public:
	MyArray();
	MyArray(float arr[],int size);
	MyArray( int size);
    MyArray(const MyArray &p);
	bool NewArray(float arr[], int size);
	bool Change_a_Element(int index, float newvalue);
	bool Return_a_Element(int index,float &num)const;
	float Sum_Array()const;
	int Num_Of__Element()const;
	void printArray()const;

	~MyArray();
private:
	float* arr;
	int size;
	void resetdata();
};

