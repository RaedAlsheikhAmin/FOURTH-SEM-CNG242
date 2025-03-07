#include"Header.h"

Cars::Cars(char* str, int n)
{
	this->model = new char[20];
	strcpy(this->model, str);
	this->ID = n;
	numberofcars++;
}

Cars::Cars(const Cars& c)
{
	this->model = new char[20];
	strcpy(this->model, c.model);
	this->ID = c.ID;
	numberofcars++;
}

Cars::~Cars()
{
	delete[]this->model;
	numberofcars--;
}
int Cars::numberofcars = 0;

int Cars::getnumberofcars() { return numberofcars; }