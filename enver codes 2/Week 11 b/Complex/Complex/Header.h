#include<iostream>
using namespace std;

class Complex
{
private:
	double real, imag;
public:
	Complex(double, double);
	friend Complex operator +(Complex, Complex);
	Complex operator - (Complex);
	void operator =(Complex);
	friend ostream& operator <<(ostream&, Complex);
	friend Complex operator *(Complex, Complex);
	friend Complex operator /(Complex, Complex);
};