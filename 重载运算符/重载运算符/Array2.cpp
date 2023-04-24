#include<iostream>
#include<iomanip>
#include"Array2.h"
using namespace std;

int Array2::size = 10;
int count = 0;

Array2::Array2()
{
	a = new Array1[size];
}

Array2::~Array2()
{
	delete[] a;
}

Array1& Array2::operator [](int index)
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

bool Array2::operator ()(int index)
{
	return (0 < index && index < size) ? true : false;
}

ostream& operator<<(ostream& out, Array2& arr)
{
	for (int i = 0; i < arr.size; i++)
	{
		cout << arr.a[i];
	}
	cout << endl;
	return out;
}