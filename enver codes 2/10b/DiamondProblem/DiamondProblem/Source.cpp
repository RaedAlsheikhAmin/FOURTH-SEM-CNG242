#include"Header.h"

Person::Person(char* str, int n)
{
	name = new char[50];
	strcpy(name, str);
	age = n;
}

Person::Person(const Person& p)
{
	name = new char[50];
	strcpy(name, p.name);
	age = p.age;
}

Person::~Person()
{
	delete[] name;
}

Student::Student(char* str, int n, int m):Person(str,n)
{
	this->Student_ID = m;
}

Staff::Staff(char* str, int m, int n) :Person(str, m)
{
	this->SSN = n;
}

StudentStaff::StudentStaff(char* str, int m,int n,int l):Person(str,m),Student(str,m,n),Staff(str,m,l)
{

}

void StudentStaff::printer()
{
	cout << "Name:" << this->name << endl;
	cout << "Age:" << this->age << endl;
	cout << "Student ID:" << this->Student_ID << endl;
	cout << "SSN:" << this->SSN << endl;
}