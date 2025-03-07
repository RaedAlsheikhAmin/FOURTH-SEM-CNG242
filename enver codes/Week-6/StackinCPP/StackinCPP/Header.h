#include<iostream>
using namespace std;

class Stacky
{
private:
	int* mystack;
	int top;
	int size;
public:
	Stacky(int);
	void push(int);
	int pop();
	int peek();
	void sprint();
};