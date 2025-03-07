#include"Header.h"

X::X(int n) { valX = n; }

void X::operator!()
{
	cout << "Xvalue: " << valX << endl;
}

void X::operator++()
{
	valX++;
}

void X::operator++(int)
{
	valX++;
}

X X::operator+(X x)
{
	X temp(0);
	temp.valX = this->valX + x.valX;
	return temp;
}

void X::operator=(const X& x)
{
	this->valX = x.valX;
}


void X::operator()(int x, int y, int z)
{
	valX = x + y + z;
}


void X::operator()(double d)
{
	valX = d;
}



Y::Y(int n) { valY = n; }

void Y::operator=(const Y& y)
{
	this->valY = y.valY;
}