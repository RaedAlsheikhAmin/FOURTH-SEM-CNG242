#include<iostream>
using namespace std;

class A
{
protected:
	int val;
public:
	A(int);
	virtual void Show();
};

class B :public A
{
private:
	int valB;
public:
	B(int, int);
	void Show();
};

class C :public A
{
private:
	int valC;
public:
	C(int, int);
	void Show();
};