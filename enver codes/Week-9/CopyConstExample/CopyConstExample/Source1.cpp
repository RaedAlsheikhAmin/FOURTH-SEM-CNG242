#include"Header.h"

void PairPrint(Pair p)
{
	cout << "Name: " << p.getname() << ", Age: " << p.getage() << endl;
}

void PairPrint2(const Pair& p)
{
	cout << "Name: " << p.getname() << ", Age: " << p.getage() << endl;
}

Pair Initialise()
{
	Pair temp;
	temp.setname("First Human");
	temp.setage(10000);
	return temp;
}

void Initialise2(Pair& temp)
{
	temp.setname("First Human");
	temp.setage(10000);
}

int main()
{
	/*Pair p1;
	p1.setage(25);
	p1.setname("Nocola Tesla");
	PairPrint(p1);

	Pair p2 = p1;
	PairPrint(p2);

	Pair p3;
	p3.setname("Hakeem Olojuwon");
	p3.setage(55);
	p2 = p3;
	PairPrint(p2);

	Pair p4;
	p4= Initialise();
	PairPrint(p4);*/

	Pair p5;
	p5.setname("Steve Kerr");
	p5.setage(50);
	PairPrint2(p5);
	Initialise2(p5);
	PairPrint2(p5);
	//p5.getage2() = 0;
	PairPrint2(p5);

	return 0;
}