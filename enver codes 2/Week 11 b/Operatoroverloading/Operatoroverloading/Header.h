#include<iostream>
using namespace std;

class X
{
private:
	int valX;
public:
	X(int);
	void operator !();
	void operator++();
	void operator++(int);
	X operator +(X);
	void operator =(const X&);
	void operator ()(int a = 1, int b = 2, int c = 3);
	void operator ()(double);
};

class Y
{
private:
	int valY;
public:
	Y(int);
	friend void operator!(Y);
	friend void operator++(Y&);
	friend void operator++(Y&, int);
	friend Y operator +(Y, Y);
	void operator =(const Y&);
};