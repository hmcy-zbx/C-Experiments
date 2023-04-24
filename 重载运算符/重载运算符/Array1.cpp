#include<iostream>
#include<iomanip>
#include"Array1.h"
using namespace std;

int Array1::size = 10;
int Array1::count = 0;
Array1::Array1()
{
	a = new int[size];
	for (int i = 0; i < size; i++) {
		a[i] = count;
		count++;
	}
}

Array1::~Array1()
{
	delete[] a;
}

int& Array1::operator [](int index)
{
	if (!operator()(index))
	{
		return a[index];
	}
	else
	{
		cout << "Error!!!" << endl;
		exit(-1);
	}
}

bool Array1::operator ()(int index)
{
	return (0 < index && index < size) ? true : false;
}

ostream& operator<<(ostream& out, Array1& arr)
{
	for (int i = 0; i < arr.size; i++)
	{
		cout << left << setw(5) << arr.a[i] << " ";
	}
	cout << endl;
	return out;
}