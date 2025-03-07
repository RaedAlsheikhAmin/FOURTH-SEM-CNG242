#include<iostream>
using namespace std;

class Person {
protected:
	char Name[50];
	int age;

public:
	Person();
	virtual void Printer();
	void setname(char*);
	void setage(int);
	int getage() { return age; }
	char* getname() { return Name; }
};

class Employee :public Person
{
private:
	int STAFF_ID;
public:
	void setID(int);
	void Printer();
};