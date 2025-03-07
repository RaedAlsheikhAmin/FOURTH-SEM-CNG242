#include<iostream>

namespace Circle
{
	const double pi = 3.14;
	double area(double r) { return r * r * pi; }
	double circum(double r) { return 2 * pi * r; }
}