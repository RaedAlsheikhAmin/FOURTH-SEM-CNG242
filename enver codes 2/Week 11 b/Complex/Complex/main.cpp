#include"Header.h"

Complex operator +(Complex c1, Complex c2)
{
	Complex temp(0, 0);
	temp.real = c1.real + c2.real;
	temp.imag = c1.imag + c2.imag;
	return temp;
}


ostream& operator<<(ostream& os, Complex c)
{
	os <<"("<< c.real << " + " << c.imag << "i"<<")";
	return os;
}

Complex operator *(Complex c1, Complex c2)
{
	Complex temp(0, 0);
	temp.real = c1.real * c2.real - c1.imag * c2.imag;
	temp.imag = c1.imag * c2.real + c1.real * c2.imag;
	return temp;

}

Complex operator /(Complex c1, Complex c2)
{
	Complex temp(0, 0);
	double divider = c2.real * c2.real + c2.imag * c2.imag;
	temp.real = (c1.real * c2.real + c1.imag * c2.imag)/divider;
	temp.imag = (c1.imag * c2.real - c1.real * c2.imag) / divider;
	return temp;

}


int main()
{
	Complex c1(1.1, 2.2), c2(3.1, 3.2);
	cout << c1 << " + " << c2 << "=" << c1 + c2 << endl;

	Complex c3(0, 0);
	c3 = c2 - c1;
	cout << c2 << " - " << c1 << "=" << c3 << endl;

	cout << c1 << " * " << c2 << "=" << c1 * c2 << endl;
	cout << c1 << " / " << c2 << "=" << c1 / c2 << endl;

	return 0;
}