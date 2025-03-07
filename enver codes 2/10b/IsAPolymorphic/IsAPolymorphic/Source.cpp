#include"Header.h"

A::A(int n)
{
	this->val = n;
}

void A::Show()
{
	cout << "A's show value:" << this->val << endl;
}

B::B(int a, int b):A(a)
{
	this->valB=b;
}

void B::Show()
{
	//cout << "Parent value:" << this->val << endl;
	cout << "B's show value:" << this->valB << endl;
}

C::C(int a, int c):A(a)
{
	this->valC = c;
}

void C::Show()
{
	//cout << "Parent value:" << this->val << endl;
	cout << "C's show value:" << this->valC << endl;
}
