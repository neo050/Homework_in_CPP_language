#pragma once
#include <iostream>
#include <ostream>
#include <typeinfo>
using namespace std;
template <class T>
class Set
{
private:
	T* arr;
	int size;
public:
	Set();
	Set(T* arr, int size);
	Set(const Set& other);
	~Set();
	const Set operator+(const Set& s) const;
	const Set operator-(const Set& s) const;
	const Set operator*(const Set& s) const;
	Set& operator=(const Set& s);
	bool operator==(const Set& s) const;
	bool in(T element) const;
	void print() const;
};
template <class T>
Set<T>::Set()
{
	size = 0;
	arr = NULL;
}
template <class T>
Set<T>::Set(T* arr, int size)
{
	this->arr = new T[size];
	if (!this->arr)
	{
		cout << "memory error" << endl;
		exit(1);
	}
	for (int i = 0; i < size; ++i)
		this->arr[i] = arr[i];
	this->size = size;
	
}
template <class T>
Set<T>::Set(const Set <T>& other)
{
	this->arr = new T[other.size];
	if (!this->arr)
	{
		cout << "memory error" << endl;
		exit(1);
	}
	for (int i = 0; i < other.size; ++i)
		this->arr[i] = other.arr[i];
	this->size = other.size;
}
template <class T>
Set<T>::~Set()
{
	delete[]arr;
}
template <class T>
const Set<T> Set<T>::operator+(const Set<T>& s) const
{	
	int i;
	int counter = 0, k = 0;
	for ( i = 0; i < s.size; ++i)
	{
		if (in(s.arr[i]) == false)
			++counter;
	}
	T* temp_arr = new T[size + counter];
	if (!temp_arr)
	{
		cout << "memory error" << endl;
		exit(1);
	}
	
	
	for (i = 0; i < s.size; ++i)
	{
		if (in(s.arr[i]) == false)
		{
			temp_arr[k] = s.arr[i];
			++k;
		}
			
	}
	for (i = 0; i < size; ++i)
	{
		temp_arr[k] = arr[i];
		++k;
	}
	Set newarr(temp_arr, size + counter);
	delete[]temp_arr;
	return newarr;

}
template <class T>
const Set<T> Set<T>::operator-(const Set<T>& s) const
{
	int counter=0,k=0;
	for (int i = 0; i < size; ++i)
	{
		if (s.in(arr[i]) == true)
			++counter;
	}
	T* temp_arr = new T[size- counter];
	if(!temp_arr)
	{
		cout << "memory error" << endl;
		exit(1);
	}
	for (int i = 0; i < size; ++i)
	{
		if (s.in(arr[i]) == false)
		{
			temp_arr[k] = arr[i];
			++k;
		}
	}
	Set newarr(temp_arr, size - counter);
	delete[]temp_arr;
	return newarr;

}
template <class T>
const Set<T> Set<T>::operator*(const Set<T>& s) const
{
	int counter = 0, k = 0;
	for (int i = 0; i < size; ++i)
	{
		if (s.in(arr[i]) == true)
			++counter;
	}
	T* temp_arr = new T[counter];
	if (!temp_arr )
	{
		cout << "memory error" << endl;
		exit(1);
	}
	for (int i = 0; i < size; ++i)
	{
		if (s.in(arr[i]) == true)
		{
			temp_arr[k] = arr[i];
			++k;
		}
			
			
	}
	Set newarr(temp_arr, counter);
	delete[]temp_arr;
	return newarr;
}
template <class T>
Set<T>& Set<T>:: operator=(const Set<T>& s)
{
	if (s.arr)
	{
		T* temp_arr = new T[s.size];
		if (!temp_arr)
		{
			cout << "memory error" << endl;
			exit(1);
		}
		for (int i = 0; i < s.size; ++i)
			temp_arr[i] = s.arr[i];
		this->size = s.size;
		delete[]this->arr;
		this->arr = temp_arr;
		return *this;
	}
	this->arr = NULL;
	this->size = 0;
	return *this;
}
template <class T>
bool Set<T>::operator==(const Set<T>& s) const
{
	if (s.size != size)
		return false;
	for(int i=0;i<size;++i)
	{
		if (s.in(arr[i]) == false)
			return false;
	}
	return true;
}
template <class T>
bool Set<T>::in(T element) const
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == element)
			return true;
	}
	return false;
}
template <class T>
void Set<T>::print() const
{
	cout << "{";
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i];
		if (i < size - 1)
			cout << ",";
	}
	cout << "}"<<endl;
}