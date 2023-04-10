#include<iostream>
#include"stack.h"
#define FILE_BUFFER_LENGTH 30000
using namespace std;

stack::stack() 
{
	top  = new char[10];
	base = top;
}

stack::~stack()
{
	top = base = nullptr; // ÖÃ¿ÕÖ¸Õë£¬±ÜÃâÇ±ÔÚµÄÄÚ´æĞ¹Â©
}

void stack::clearstack() 
{
	top = base;
}

bool stack::isempty() 
{
	return top == base ? true : false;
}

char stack::gettop()
{
	if (length() == 0)
	{
		cout << "Sorry,the stack is empty!" << endl;
		return '\0';
	}
	return *(top-1);
}

int stack::length() 
{
	return top - base;
}

int stack::push(char c)
{
	if (length() == 10)
	{
		cout << "Sorry,the stack is full!" << endl;
		return 0;
	}
	*top++ = c;
	return 1;
}

void stack::traverse()
{
	for (char* p = top - 1; p >= base; p--) 
	{
		cout << *p << endl;
	}
}

char stack::pop()
{
	if (length() == 0)
	{
		cout << "Sorry,the stack is empty!" << endl;
		return '\0';
	}
	return *(--top);
}