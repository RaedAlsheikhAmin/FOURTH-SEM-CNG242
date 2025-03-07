#include"Header.h"

Pair::Pair()
{
	cout << "Call constructor" << endl;
	Name = new char[60];
	strcpy(Name, "No name");
	age = 0;
}

Pair::Pair(Pair& p)
{
	cout << "Copy Constructor Called" << endl;
   Name = new char[50];
   strcpy(Name, p.Name);
   this->age = p.age;
}

Pair::~Pair()
{
	cout << "Call the destructor" << endl;
	delete[] Name;
}
void Pair::setage(int n) { age = n; }
void Pair::setname(const char* str) { strcpy(Name, str); }
int Pair::getage() const{ return age; }
char* Pair::getname() const{ return Name; }

void Pair::operator=(Pair p)
{
	strcpy(this->Name, p.Name);
	this->age = p.age;
}