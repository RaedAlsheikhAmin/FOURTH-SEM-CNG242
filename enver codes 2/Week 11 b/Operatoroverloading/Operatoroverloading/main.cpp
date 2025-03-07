#include"Header.h"

void operator !(Y y)
{
	cout << "Yvalue: " << y.valY << endl;
}

void operator++(Y& y)
{
	y.valY++;
}

void operator ++ (Y& y, int)
{
	y.valY++;
}

Y operator +(Y y1, Y y2)
{
	Y temp(0);
	temp.valY = y1.valY + y2.valY;
	return temp;
}

int main()
{
	X x1(1);
    Y y1(10);
	!x1;
	!y1;
	cout << "--------------------------" << endl;
	++x1;
	++y1;
	!x1;
	!y1;
	cout << "--------------------------" << endl;
	x1++;
	y1++;
	!x1;
	!y1;
	cout << "--------------------------" << endl;
	X x2(5);
	Y y2(20);
	!(x1 + x2);
	!(y1 + y2);
	cout << "--------------------------" << endl;
	X x3(0);
	Y y3(0);

	x3 = x1 + x2;
	y3 = y1 + y2;
	!x3;
	!y3;
	cout << "--------------------------" << endl;
	X x4(0);
	x4();
	!x4;
	x4(10);
	!x4;
	x4(10,20);
	!x4;
	x4(10, 20,30);
	!x4;
	x4(3.14);
	!x4;


	return 0;
}