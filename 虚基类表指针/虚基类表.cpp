#include<iostream>
using namespace std;
class A
{
public:
    A(int aa = 1) :a(aa) {}
    void func()
    {
        cout << "a=" << a << endl;
    }
protected:
    int a;
};

class B :virtual public A
{
public:
    B(int aa = 1, int bb = 2) :A(aa), b(bb) {}
    void func()
    {
        A::func();
        cout << "b=" << b << endl;
    }
protected:
    int b;
};

class C :virtual public A
{
public:
    C(int aa = 1, int cc = 3) :A(aa), c(cc) {}
    void func()
    {
        A::func();
        cout << "c=" << c << endl;
    }
protected:
    int c;
};

class D :public B, public C 
{
public:
    D(int aa = 1, int bb = 2, int cc = 3, int dd = 4) :A(aa), B(bb), C(cc), d(dd) {}
    void func()
    {
        B::func();
        C::func();
        cout << "d=" << d << endl;
    }
protected:
    int d;
};

int main()
{
    D objd;
    objd.func();
    int* p = (int*)&objd;
    /*cout << sizeof(A) << endl;
    cout<<sizeof(B)<<endl;
    cout<<sizeof(C)<<endl;
    cout<<sizeof(D)<<endl;*/
    cout << *(int*)*(p + 0) << endl;
    cout << *(p + 1) << endl;
    cout << *(int*)*(p + 2) << endl;
    cout << *(p + 3) << endl;
    cout << *(p + 4) << endl;
    cout << *(p + 5) << endl;
    return 0;
}
