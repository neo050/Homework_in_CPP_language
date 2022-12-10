#define _CRT_SECURE_NO_WARNINGS
#include "Set.h"
#include <iostream>
#include <ostream>
#include <typeinfo>
using namespace std;
template <class T>
T* remove(const T* arr, int& size, T val)
{
	int tsize = 0, k = 0;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] != val)
			++tsize;
	}
	T* arr_new = new T[tsize];
	if (!arr_new)
	{
		cout << "memory error" << endl;
		exit(1);
	}
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] != val)
		{
			arr_new[k] = arr[i];
			++k;
		}

	}
	size = tsize;

	return arr_new;
}
template <class T>
void bildarray(T*& arr, int& size)
{
	cout << "Enter size of array " << typeid(*arr).name() << endl;
	cin >> size;
	arr = new T[size];
	if (!arr)
	{
		cout << "memory error" << endl;
		exit(1);
	}
	cout << "Enter data of array " << typeid(*arr).name() << endl;
	for (int i = 0; i < size; ++i)
		cin >> arr[i];
}
template <class T>
void print_arr(const T* arr, int size)
{
	cout << "{ ";
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << "}";
	cout << endl;
}

int main()
{

	int size_f, size_i;
	float* arr_f = NULL, val_f, * n_arr_f;
	long* arr_i = NULL, val_i, * n_arr_i;

	/*cout << "Enter data of float array" << endl;*/
	bildarray<float>(arr_f, size_f);
	cout << "Enter float val  for fonc remove: "; cin >> val_f; cout << endl;
	cout << "The old float array...   ";
	print_arr<float>(arr_f, size_f);
	n_arr_f = remove<float>(arr_f, size_f, val_f);
	cout << "The new float array...   ";
	print_arr<float>(n_arr_f, size_f);
	/*cout << "Enter data of long array" << endl;*/
	bildarray<long>(arr_i, size_i);
	cout << "Enter long val for fonc remove: "; cin >> val_i; cout << endl;
	cout << "The old long array...  ";
	print_arr<long>(arr_i, size_i);
	n_arr_i = remove<long>(arr_i, size_i, val_i);
	cout << "The new long array...  ";
	print_arr<long>(n_arr_i, size_i);
	delete[]arr_f;
	delete[]n_arr_f;
	delete[]arr_i;
	delete[]n_arr_i;
	cout << endl << endl;
	int* array_int1;
	char* array_char1,temparr[100];
	float* array_float1;
	int size_one,i;
	

	cout << "Please enter the sizes of the arrays:"<<endl;
	cout << "array 1 -> <int> array 1" << endl << "array 2 -> <int> array 2" << endl << "array 3 -> <float> array 1" << endl << "array 4 -> <float> array 2" << endl << "array 5 -> <char> array 1" << endl << "array 6 -> <char> array 2" << endl;
	
	
		
			cout << "enter size of array " << 1 << " :"; cin >> size_one;
			array_int1 = new int[size_one];
			if (!array_int1)
			{
				cout << "memory error" << endl;
				exit(1);
			}
			cout << "Please enter <int> number to array " << 1 << ": ";
			for (i = 0; i < size_one; i++)
			{
				cin >> array_int1[i];
			}
			cout << endl;
			Set <int> array1(array_int1, size_one);
		
				
		
			cout << "enter size of array " << 2 << " :"; cin >> size_one;
			if (array_int1)
				delete[]array_int1;
			array_int1 = new int[size_one];
			if (!array_int1)
			{
				cout << "memory error" << endl;
				exit(1);
			}
			cout << "Please enter <int> number to array " << 2 << ": ";
			for (i = 0; i < size_one; i++)
			{
				cin >> array_int1[i];
			}
			cout << endl;
			Set <int> array2(array_int1, size_one);
			Set <int> array_union = array2 + array2;
			Set <int> array_difference = array1 - array2;
			Set <int> array_and = array1 * array2;
		
			cout << "enter size of array " << 3 << " :"; cin >> size_one;
			array_float1 = new float[size_one];
			if (!array_float1)
			{
				cout << "memory error" << endl;
				exit(1);
			}
			cout << "Please enter <float> number to array " << 3 << ": ";
			for (i = 0; i < size_one; i++)
			{
				cin >> array_float1[i];
			}
			cout << endl;
			Set <float> arrayfloat1(array_float1, size_one);


		
			cout << "enter size of array " << 4 << " :"; cin >> size_one;
			if (array_float1)
				delete[]array_float1;
			array_float1 = new float[size_one];
			if (!array_float1)
			{
				cout << "memory error" << endl;
				exit(1);
			}
			cout << "Please enter <float> number to array " << 4 << ": ";
			for (i = 0; i < size_one; i++)
			{
				cin >> array_float1[i];
			}
			cout << endl;
			Set <float> arrayfloat2(array_float1, size_one);
			Set <float> array_float_union = arrayfloat1 + arrayfloat2;
			Set <float> array_float_difference = arrayfloat1 - arrayfloat2;
			Set <float> array_float_and = arrayfloat1 * arrayfloat2;

			cout << "Please enter <char> leters to array " << 5 << ": ";
			
			cin >> temparr;
			

			size_one = strlen(temparr) + 1;
			/*array_char1 = new char[size_one];
			if (!array_char1)
			{
				cout << "memory error" << endl;
				exit(1);
			}
			strcpy(array_char1, temparr);
			cout << endl;*/
			Set <char> arrayword1(temparr, size_one);

			
			cout << "Please enter <char> leters to array " << 6 << ": ";
		/*	if (array_char1)
				delete[]array_char1;*/
		
			cin >> temparr;
			size_one = strlen(temparr) + 1;
			/*array_char1 = new char[size_one];
			if (!array_char1)
			{
				cout << "memory error" << endl;
				exit(1);
			}
			strcpy(array_char1, temparr);*/
			cout << endl;
			Set <char> arrayword2(temparr, size_one);
			Set <char> array_word_union = arrayword1 + arrayword2;
			Set <char> array_word_difference = arrayword1 - arrayword2;
			Set <char> array_word_and = arrayword1 * arrayword2;
		
	cout << endl;
	cout << "Union array: " << endl;
	array_union.print();
	array_float_union.print();
	array_word_union.print();
	cout << "--------------------------" << endl;
	cout << "Difference array: " << endl;
	array_difference.print();
	array_float_difference.print();
	array_word_difference.print();
	cout << "--------------------------" << endl;
	cout << "And array: " << endl;
	array_and.print();
	array_float_and.print();
	array_word_and.print();
	cout << "--------------------------" << endl;
	delete[]array_int1;
	/*delete[]array_char1;*/
	delete[]array_float1;
	return 0;
}