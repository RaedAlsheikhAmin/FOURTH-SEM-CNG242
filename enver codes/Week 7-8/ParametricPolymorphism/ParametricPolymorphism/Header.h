#include<iostream>
using namespace std;


template<class U>
void swapy(U& elem1, U& elem2)
{
	U temp;
	temp = elem1;
	elem1 = elem2;
	elem2 = temp;
}

template<class alpha>
struct Mytree
{
	alpha elem;
	struct Mytree* left, * right;
};

struct Complex
{
	double real, imag;
};

double adder(double num1, double num2) { return (num1 + num2); }

Complex adder(Complex c1, Complex c2)
{
	Complex temp;
	temp.real = c1.real * c2.real - c1.imag * c2.imag;
	temp.imag = c1.real * c2.imag + c1.imag * c2.real;
	return temp;
}

void Complexprint(Complex c)
{
	cout << "(" << c.real << " + " << c.imag << "i)";
}