#pragma once
#ifndef ARRAY1_H
#define ARRAY1_H
#include<iostream>
using namespace std;

class Array1 {
private:
	int* a;
	static int size;
	static int count;
public:
	Array1();
	~Array1();
	int& operator [](int);
	bool operator ()(int);
	friend ostream& operator<<(ostream&, Array1&);
};
#endif  // !ARRAY1_H