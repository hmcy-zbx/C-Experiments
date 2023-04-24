#pragma once
#ifndef ARRAY2_H
#define ARRAY2_H
#include<iostream>
#include"Array1.h"
using namespace std;

class Array2{
private:
	Array1* a;
	static int size;
public:
	Array2();
	~Array2();
	Array1& operator[](int);
	bool operator()(int);
	friend ostream& operator<< (ostream& out, Array2& arr);
};
#endif // !ARRAY2_H
