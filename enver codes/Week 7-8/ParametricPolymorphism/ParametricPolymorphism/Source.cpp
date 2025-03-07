#include"Header.h"

int main()
{
	int i1 = 1, i2 = 10;
	char c1 = 'A', c2 = 'B';
	cout << "i1:" << i1 << ",  i2:" << i2 << endl;
	swapy(i1, i2);
	cout << "i1:" << i1 << ",  i2:" << i2 << endl;

	cout << "c1:" << c1 << ",  c2:" << c2 << endl;
	swapy(c1, c2);
	cout << "c1:" << c1 << ",  c2:" << c2 << endl;

	struct Mytree <int> m1;
	struct Mytree <char> m2;
	cout << "\n\n-----------------------" << endl;
	Complex ca = { 1.1,2.2 };
	Complex cb = { 3.3,4.4 };
	cout << "Adding integers: " << i1 << " + " << i2 << "=" << adder(i1, i2) << endl;;
	cout << "Adding Complex: ";
	Complexprint(ca);
	cout << " + "; 
	Complexprint(cb);
	cout << "=";
	Complexprint(adder(ca,cb));

	
	return 0;
}