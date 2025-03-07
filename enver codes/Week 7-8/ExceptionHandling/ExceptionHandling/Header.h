#include<iostream>
using namespace std;

double dividefunc(double a, double b)
{
	if (b == 0)
		throw "Division by zero cannot have this\n\n";
	else
		return a / b;
}