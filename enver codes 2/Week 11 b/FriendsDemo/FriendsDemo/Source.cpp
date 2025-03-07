#include"Header.h"

Y::Y(int n) { valY = n; }
X::X(int n) { valX = n; }

void Y::Xprinter(X x)
{
	cout << "Printing X: " << x.valX << endl;
}