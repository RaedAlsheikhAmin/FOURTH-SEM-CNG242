#include"Header.h"

Complex::Complex(double r, double i)
{
	this->real = r;
	this->imag = i;
}

Complex Complex::operator-(Complex c)
{
	Complex temp(0,0);
	temp.real = this->real - c.real;
	temp.imag = this->imag - c.imag;
	return temp;
}

void Complex::operator=(Complex c)
{
	this->real = c.real;
	this->imag = c.imag;
}