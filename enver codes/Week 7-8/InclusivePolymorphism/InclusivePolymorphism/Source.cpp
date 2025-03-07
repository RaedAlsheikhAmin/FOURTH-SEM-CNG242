#include"Header.h"

void write(Animal* a)
{
	cout << a->talk() << endl;
}

int main()
{
	Animal a;
	Cat c;
	Dog d;
	cout << a.talk() << endl;
	cout << c.talk() << endl;
	cout << d.talk() << endl;
    
	cout << "\n-------------------------" << endl;
	Animal* ptra, * ptrc, * ptrd;
	ptra = &a;
	ptrc = &c;
	ptrd = &d;

	//cout << ptra->talk() << endl;
	//cout << ptrc->talk() << endl;
	//cout << ptrd->talk() << endl;

	write(ptra);
	write(ptrc);
	write(ptrd);
	return 0;
}