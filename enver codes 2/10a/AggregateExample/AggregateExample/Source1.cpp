#include"Header.h"

ostream& operator<<(ostream& os, Course c)
{
	os << "Course-" << c.code << "\n--------------------------------" << endl;
	for (int i = 0; i < c.numberofstudents; i++)
	{
		os << i + 1 << "- Student No:" << c.container[i]->getid() << ", Name: " << c.container[i]->getname() << endl;
	}

	return os;
}



int main()
{
	Student s1("Stephen Curry", 34);
	Student s2("Shawn Kemp", 55);
	Student s3("Deangelo Russel", 29);
	Student s4("Steve Kerr", 56);
	Course c1("CNG 242");
	c1.regeisterer(s1);
	c1.regeisterer(s2);
	c1.regeisterer(s3);
	c1.regeisterer(s4);

	Student s5("Chris Haywood", 20);
	s5.enrol(c1);

	Student s6("Albert Einstein", 90);
	s6.enrol2(c1);
	cout << c1<<endl;

	Course* c2=new Course("CNG 223");
	c2->regeisterer(s1);
	c2->regeisterer(s2);
	cout << *c2 << endl;
	delete c2;

	Course* c3 = new Course("CNG 435");
	c3->regeisterer(s1);
	c3->regeisterer(s2);
	cout << *c3 << endl;


	return 0;
}