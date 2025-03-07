#include"Header.h"

int main()
{
	Person p1,p2;
	p1.setname("Stephen Curry");
	p1.setage(34);
	p2.setname("Klay Thompson");
	p2.setage(32);
	//p1.Printer();
	//p2.Printer();

	Employee e1, e2, e3;
	e1.setname("Larry Bird");
	e1.setage(65);
	e1.setID(33);
	
	e2.setname("Scottie Pippen");
	e2.setage(55);
	e2.setID(32);

	e3.setname("James Worthy");
	e3.setage(75);
	e3.setID(80);

	//e1.Printer();
	//e2.Printer();
	//e3.Printer();
	
	Person* myarray[5];
	myarray[0] = &p1;
	myarray[1] = &p2;
	myarray[2] = &e1;
	myarray[3] = &e2;
	myarray[4] = &e3;

	for (int i = 0; i < 5; i++)
		myarray[i]->Printer();

	//p1.age = 25;
	return 0;
}