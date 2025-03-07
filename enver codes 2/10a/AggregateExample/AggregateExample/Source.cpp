#include"Header.h"

Student::Student(char* str, int n)
{
	name = new char[50];
	strcpy(name, str);
	ST_ID = n;
}

Student::Student(Student& s)
{
	name = new char[50];
	strcpy(name, s.name);
	ST_ID = s.ST_ID;
}

Student::~Student()
{
	delete[] name;
}

void Student::enrol(Course& c)
{
	c.regeisterer(*this);
}

void Student::enrol2(Course& c)
{
	c.container[c.numberofstudents] = this;
	c.numberofstudents++;
}


Course::Course(char* str) 
{
	code = new char[20];
	strcpy(code, str);
	numberofstudents = 0;
}

Course::Course(Course& c)
{
	code = new char[20];
	strcpy(code, c.code);
	numberofstudents = c.numberofstudents;
	for (int i = 0; i < numberofstudents; i++)
	{
		container[i] = c.container[i];
	}
}

Course::~Course()
{
	delete[]code;
}

void Course::regeisterer(Student& s)
{
	container[numberofstudents] = &s;
	numberofstudents++;
}