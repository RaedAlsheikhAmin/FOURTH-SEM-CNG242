#include<iostream>
using namespace std;

class Person
{
protected:
	char* name;
	int age;
public:
	Person(char*, int);
	Person(const Person&);
	~Person();
};

class Student: virtual public Person
{
protected:
	int Student_ID;
public:
	Student(char*, int, int);
};

class Staff :virtual public Person
{
protected:
	int SSN;
public:
	Staff(char*, int, int);
};

class StudentStaff:public Student, public Staff
{
public:
	StudentStaff(char*, int, int, int);
	void printer();
};