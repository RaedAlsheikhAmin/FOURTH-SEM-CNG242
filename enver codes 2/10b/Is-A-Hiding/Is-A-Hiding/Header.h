#include<iostream>
using namespace std;

class A {
protected:
	int value;
public:
	A(int);
};

class B:public A
{
protected:
	int value;
public:
	B(int,int);
	void printer();
};

class C :public B
{
private:
	int value;
public:
	C(int, int, int);
	void printer();
};