#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "MyArray.h"
#include <iomanip>
using namespace std;
void MyArray::resetdata() {
	size = 0;
	arr = NULL;
}
MyArray::MyArray() {
	size = 0;
	arr = NULL;
}
MyArray::MyArray(float arr[], int size) {
	this->arr = new float[size];
	if (!this->arr) {
		resetdata();
		return;
	}
	for (int i = 0; i < size; i++) {
		this->arr[i] = arr[i];
	}
	this->size = size;
}
MyArray::MyArray(int size) {
	this->arr = new float[size];
	if (!this->arr) {
		resetdata();
		return;
	}
	for (int i = 0; i < size; i++) {
		this->arr[i] = 0.0;
	}
	this->size = size;
}

MyArray::MyArray(const MyArray& p) {
	this->arr = new float[p.Num_Of__Element()];
	if (!this->arr) {
		resetdata();
		return;
	}
	this->size = p.Num_Of__Element();
	float num=0.0;
	for (int i = 0; i < size; i++) {
		if (p.Return_a_Element(i, num)) {
			this->arr[i] = num;
		}
	}
	
}

bool MyArray::NewArray(float arr[], int size) {
	delete[]this->arr;
	this->arr = new float[size];
	if (!this->arr) {
		resetdata();
		return false;
	}
	for (int i = 0; i < size; i++) {
		this->arr[i] = arr[i];
	}
	this->size = size;
	return true;

}
bool MyArray::Change_a_Element(int index, float newvalue) {
	if (!(index >= 0 && index <= size)) {
		return false;
	}
	arr[index] = newvalue;
	return true;
}
bool MyArray::Return_a_Element(int index, float& num)const {
	if (!(index >= 0 && index <= size)) {
		return false;
	}
	num = arr[index];
	return true;
}
float MyArray::Sum_Array()const {
	float sum=0.0;
	for (int i = 0; i < size; i++) {
		sum = sum + arr[i];
	}
	return sum;
}
int MyArray::Num_Of__Element()const {
	return size;
}
void MyArray::printArray()const {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout<< endl;
}
MyArray::~MyArray() {
	delete[]arr;
}
