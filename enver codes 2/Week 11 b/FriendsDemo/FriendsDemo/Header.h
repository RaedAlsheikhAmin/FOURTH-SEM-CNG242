#include<iostream>
using namespace std;
class X;
class Y
{
private:
	int valY;
public:
	Y(int);
	void Xprinter(X);
};

class X
{
private:
	int valX;
public:
	X(int);
	friend void Y::Xprinter(X);
};