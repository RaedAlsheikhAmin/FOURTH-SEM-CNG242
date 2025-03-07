#include<iostream>
using namespace std;

class Animal
{
public:
	virtual const char* talk() { return "I am an animal!!"; }
};

class Cat:public Animal
{
public:
	const char* talk() { return "Miaw miaww!!!"; }
};

class Dog :public Animal
{
public:
	const char* talk() { return "Woof woof!!!"; }
};