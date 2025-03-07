#include"Header.h"

int main()
{
	A a1(10);
	B b1(10, 20),b2(30,40);
	C c1(100, 200),c2(300,400);
	a1.Show();
	b1.Show();
	c1.Show();
	cout <<"\n\n-----------------------\n\n" << endl;
	A* myarray[5];
	myarray[0] = &a1;
	myarray[1] = &b1;
	myarray[2] = &b2;
	myarray[3] = &c1;
	myarray[4] = &c2;

	for (int i = 0; i < 5; i++)
		myarray[i]->Show();



	return 0;
}