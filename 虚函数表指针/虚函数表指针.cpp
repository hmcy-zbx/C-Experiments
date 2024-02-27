#include<iostream>
using namespace std;
class A {
private:
	int a;
public:
	virtual void f1() { cout << "f1() is called of A" << endl; }
	virtual void f2() { cout << "f2() is called of A" << endl; }
	virtual void f3() { cout << "f3() is called of A" << endl; }
};
class B :public A {
private:
	int b;
public:
	void f1() { cout << "f1() is called of B" << endl; }
	void f2() { cout << "f2() is called of B" << endl; }
	void f3() { cout << "f3() is called of B" << endl; }
};

int GetVirtual(A& a)
{
	void** vTableP = *(void***)&a;
	int number = 0;
	while (*vTableP)
	{
		vTableP++;
		number++;
	}
	return number;
}

typedef void(*FUNCP)();
FUNCP p;
void f(A& a)
{
	int* p = (int*)&a;
	for (int i = 0; i < GetVirtual(a); i++)
	{
		FUNCP q = *((FUNCP*)*p + i);
		if (q != nullptr)
		{
			q();
		}
	}
}
int main()
{
	A a;
	B b;
	cout << "A:" << sizeof(a) << endl;
	cout << "B:" << sizeof(b) << endl;
	f(a);
	cout << "----------------------" << endl;
	f(b);
}