#include"Header.h"

A::A(int n)
{
	this->value = n;
}

B::B(int n,int k):A(n)
{
	this->value = k;
}

void B::printer()
{
	cout << "Value:" << value;
}

C::C(int a, int b, int c):B(a,b)
{
	this->value = c;
}

void C::printer()
{
	cout << "Value of grand parent:" << A::value << endl;
	cout << "Value of parent:" << B::value << endl;
	cout << "Value:" <<value << endl;

}