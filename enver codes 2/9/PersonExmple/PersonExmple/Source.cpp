#include"Header.h"

Person::Person()
{
	strcpy(Name, "No name");
	this->age = 0;
}

void Person::Printer()
{
	cout << "Person Print\n---------------------" << endl;
	cout << "Name: " << this->Name << endl;
	cout << "Age: " << this->age << endl << endl;
}

void Person::setname(char* str)
{
	strcpy(Name, str);
}

void Person::setage(int n)
{
	this->age = n;
}

void Employee::setID(int n)
{
	STAFF_ID = n;
}

void Employee::Printer()
{
	cout << "Employee Print\n---------------------" << endl;
	cout << "Name: " << this->Name << endl;
	cout << "Age: " << this->age << endl;
	cout << "Staff_ID: " << this->STAFF_ID << endl<< endl;
}